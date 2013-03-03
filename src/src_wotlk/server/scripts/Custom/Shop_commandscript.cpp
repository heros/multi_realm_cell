/*
* Copyright (C) Likan Mod 2012-2013 <https://github.com/ChaosDevLikan/>
* Copyright (C) 3server 2005-2013 <https://cata.3server>
 *
 * World of Warcraft: Cataclysm 
 * You can edit but you can not delete this copyright.
 * 3server Emulator - 3server Database 
 *
 *
 * By Likan Developer Core C++, SQL (FUN, WoTLK, Cata Realm) of 3server Server
 */

#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Chat.h"
#include "Group.h"

class Shop_commandscript : public CommandScript
{
public:
    Shop_commandscript() : CommandScript("Shop_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand ShopCommandTable[] =
        {
            { "command",            SEC_PLAYER,  false, &HandleShopCommand,             "", NULL },
            { "tele",               SEC_PLAYER,  false, &HandleShopCommand,             "", NULL },
            { NULL,             0,                  false, NULL,                        "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "duel",           SEC_PLAYER,      true, NULL,                   "", ShopCommandTable },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }

 
    static bool HandleShopCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
        //podmínky pro combat a lítaní.
        if (me->isInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (me->isInFlight())
        {
            me->GetMotionMaster()->MovementExpired();
            me->CleanupAfterTaxiFlight();
        return true;
        }

        if ( me->GetTeam() == ALLIANCE ) 
        {
              me->TeleportTo(0,-1845.97f,-4243.01f,195.26f,2.39f); //souøadnice
        }
        else if ( me->GetTeam() == HORDE ) 
        {
              me->TeleportTo(0,7437.82f,-1685.38f,2.13f,1.04f); //souøadnice   
        }
        return true;
    }
};

void AddSC_Shop_commandscript()
{
    new Shop_commandscript();
}