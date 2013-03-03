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

#include "ScriptPCH.h"
#include "Chat.h"

class cs_world_chat : public CommandScript
{
	public:
		cs_world_chat() : CommandScript("cs_world_chat"){}

	ChatCommand * GetCommands() const
	{
		static ChatCommand WorldChatCommandTable[] = 
		{
			{"chat",	SEC_PLAYER,		true,		&HandleWorldChatCommand,	"", NULL},
			{NULL,		0,				false,		NULL,						"", NULL}
		};

		return WorldChatCommandTable;
	}

	static bool HandleWorldChatCommand(ChatHandler * handler, const char * args)
	{
		if (!args)
			return false;

		std::string msg = "";
		Player * player = handler->GetSession()->GetPlayer();

		switch(player->GetSession()->GetSecurity())
		{
			// Player
			case SEC_PLAYER:
				if (player->GetTeam() == ALLIANCE)
				{
					msg += "|cff0000ff[Alliance] |cffffffff[";
					msg += player->GetName();
					msg += "] |cfffaeb00";
				}

				if (player->GetTeam() == HORDE)
				{
					msg += "|cffff0000[Horde] |cffffffff[";
					msg += player->GetName();
					msg += "] |cfffaeb00";
				}
				break;
			// Moderator/trial 
			case SEC_MODERATOR:
				msg += "|cffff8a00[EM] |cffffffff[";
				msg += player->GetName();
				msg += "] |cfffaeb00";
				break;
			// GM
			case SEC_GAMEMASTER:
				msg += "|cff00ffff[GM] |cffffffff[";
				msg += player->GetName();
				msg += "] |cfffaeb00";
				break;
			// Admin
			case SEC_ADMINISTRATOR:
				msg += "|cfffa9900[Admin] |cffffffff[";
				msg += player->GetName();
				msg += "] |cfffaeb00";
				break;

		}
			
		msg += args;
		sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), 0);	

		return true;
	}
};

void AddSC_cs_world_chat()
{
	new cs_world_chat();
}