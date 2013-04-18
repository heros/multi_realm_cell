/*
 * Copyright (C) Likan Mod   (https://github.com/ChaosDevLikan/)
 * Copyright (C) Prydev      (http://sourceforge.net/projects/prydevserver) 
 * Copyright (C) TrinityCore (http://www.trinitycore.org)
 * Copyright (C) MaNGOS      (http://www.getmangos.com)
 * Copyright (C) ArkCORE     (http://www.arkania.net)
 * Copyright (C) SkyFireEMU  (http://www.projectskyfire.org)
 *
 * World of Warcraft
 * You can edit but you can not delete this copyright.
 * Genesis Emulator - Genesis Database 
 *
 *
 * By Likan Developer Core C++, SQL (FUN, WoTLK, Cata Realm) of Genesis Server
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include <cstring>

enum eEnums
{
    SPELL_POLYMORPH         = 12826,
    SPELL_MARK_OF_THE_WILD  = 26990,

    //These texts must be added to the creature texts of the npc for which the script is assigned.
    SAY_NOT_INTERESTED      = 0, // "Normal select, guess you're not interested."
    SAY_WRONG               = 1, // "Wrong!"
    SAY_CORRECT             = 2  // "You're right, you are allowed to see my inner secrets."
};

#define GOSSIP_ITEM_1       "A quiz: what's your name?"
#define GOSSIP_ITEM_2       "I'm not interested"

class example_gossip_codebox : public CreatureScript
{
    public:

        example_gossip_codebox()
            : CreatureScript("example_gossip_codebox")
        {
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1, "", 0, true);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

            player->PlayerTalkClass->SendGossipMenu(907, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            if (action == GOSSIP_ACTION_INFO_DEF+2)
            {
                //Read comment in enum
                creature->AI()->Talk(SAY_NOT_INTERESTED);
                player->CLOSE_GOSSIP_MENU();
            }

            return true;
        }

        bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, char const* code)
        {
            player->PlayerTalkClass->ClearMenus();
            if (sender == GOSSIP_SENDER_MAIN)
            {
                switch (action)
                {
                case GOSSIP_ACTION_INFO_DEF+1:
                    if (player->GetName() != code)
                    {
                        //Read comment in enum
                        creature->AI()->Talk(SAY_WRONG);
                        creature->CastSpell(player, SPELL_POLYMORPH, true);
                    }
                    else
                    {
                        //Read comment in enum
                        creature->AI()->Talk(SAY_CORRECT);
                        creature->CastSpell(player, SPELL_MARK_OF_THE_WILD, true);
                    }
                    player->CLOSE_GOSSIP_MENU();

                    return true;
                }
            }

            return false;
        }
};

void AddSC_example_gossip_codebox()
{
    new example_gossip_codebox();
}
