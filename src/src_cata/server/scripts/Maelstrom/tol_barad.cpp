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


#include "ScriptPCH.h"
#include "BattlefieldMgr.h"
#include "BattlefieldTB.h"
#include "Battlefield.h"
#include "ScriptSystem.h"
#include "WorldSession.h"
#include "ObjectMgr.h"

enum eTBqueuenpctext
{
    TB_NPCQUEUE_TEXT_H_NOWAR       = 110006,
    TB_NPCQUEUE_TEXT_H_QUEUE       = 110002,
    TB_NPCQUEUE_TEXT_H_WAR         = 110005,
    TB_NPCQUEUE_TEXT_A_NOWAR       = 110003,
    TB_NPCQUEUE_TEXT_A_QUEUE       = 110001,
    TB_NPCQUEUE_TEXT_A_WAR         = 110004,
    TB_NPCQUEUE_TEXTOPTION_JOIN    = -1732009,
};

class npc_tb_spiritguide : public CreatureScript
{
public:
    npc_tb_spiritguide() : CreatureScript("npc_tb_spiritguide") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        BattlefieldTB* BfTB = (BattlefieldTB*)sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_TB);
        if (BfTB)
        {
            GraveYardVect gy = BfTB->GetGraveYardVect();
            for (uint8 i = 0; i<gy.size(); i++)
            {
                if (gy[i]->GetControlTeamId() == player->GetTeamId())
                {
                   player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, sObjectMgr->GetSkyFireStringForDBCLocale(((BfGraveYardTB*)gy[i])->GetTextId()), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+i);
                }
            }
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
    {
        player->CLOSE_GOSSIP_MENU();

        BattlefieldTB* BfTB = (BattlefieldTB*)sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_TB);
        if (BfTB)
        {
            GraveYardVect gy = BfTB->GetGraveYardVect();
            for (uint8 i = 0; i<gy.size(); i++)
            {
                if (action-GOSSIP_ACTION_INFO_DEF == i && gy[i]->GetControlTeamId() == player->GetTeamId())
                {
                    const WorldSafeLocsEntry* ws = sWorldSafeLocsStore.LookupEntry(gy[i]->GetGraveYardId());
                    player->TeleportTo(ws->map_id, ws->x, ws->y, ws->z, 0);
                }
            }
        }
        return true;
    }
};

class npc_tol_barad_battlemage : public CreatureScript
{
    public:
    npc_tol_barad_battlemage() : CreatureScript("npc_tol_barad_battlemage") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        BattlefieldTB* BfTB = (BattlefieldTB*)sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_TB);
        if (BfTB)
        {
            if (BfTB->IsWarTime())
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, sObjectMgr->GetSkyFireStringForDBCLocale(TB_NPCQUEUE_TEXTOPTION_JOIN), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                player->SEND_GOSSIP_MENU(BfTB->GetDefenderTeam() ? TB_NPCQUEUE_TEXT_H_WAR : TB_NPCQUEUE_TEXT_A_WAR, creature->GetGUID());
            }
            else
            {
                uint32 uiTime = BfTB->GetTimer()/1000;
                player->SendUpdateWorldState(5332, time(NULL)+uiTime);
                if (uiTime < 15 * MINUTE)
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, sObjectMgr->GetSkyFireStringForDBCLocale(TB_NPCQUEUE_TEXTOPTION_JOIN), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                    player->SEND_GOSSIP_MENU(BfTB->GetDefenderTeam() ? TB_NPCQUEUE_TEXT_H_QUEUE : TB_NPCQUEUE_TEXT_A_QUEUE, creature->GetGUID());
                }
                else
                {
                    player->SEND_GOSSIP_MENU(BfTB->GetDefenderTeam() ? TB_NPCQUEUE_TEXT_H_NOWAR:TB_NPCQUEUE_TEXT_A_NOWAR, creature->GetGUID());
                }
            }
        }
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/)
    {
        player->CLOSE_GOSSIP_MENU();

        BattlefieldTB* BfTB = (BattlefieldTB*)sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_TB);
        if (BfTB)
        {
            if (BfTB->IsWarTime())
            {
                BfTB->InvitePlayerToWar(player);
            }
            else
            {
                uint32 uiTime = BfTB->GetTimer()/1000;
                if (uiTime < 15 * MINUTE)
                    BfTB->InvitePlayerToQueue(player);
            }
        }
        return true;
    }
};

void AddSC_tol_barad()
{
   new npc_tol_barad_battlemage();
   new npc_tb_spiritguide();
}
