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

class GoldOnKill : public PlayerScript
{
	public:
	GoldOnKill() : PlayerScript("GoldOnKill") {}
//1
  //void OnPVPKill(Player * killer, Player * killed)
    //{
    //killer->SetMoney(killer->GetMoney() + 20000);
    //sWorld->SendWorldText(LANG_SYSTEMMESSAGE, Win!!!);
    //killed->SetMoney(killed->GetMoney() - 10000);
    //} 

//2

};

void AddSC_GoldOnKill()
{
	new GoldOnKill();
}
