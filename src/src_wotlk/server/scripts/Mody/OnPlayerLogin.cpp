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

class OnPlayerLogin : public PlayerScript
{
public:
OnPlayerLogin() : PlayerScript("OnPlayerLogin") {}

void OnLogin(Player * player)
{
char msg[500];
sprintf(msg, "%s Has Logged Into The Server!",player->GetName());
sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
}
}; 
void AddSC_OnPlayerLogin()
{
new OnPlayerLogin();
}
