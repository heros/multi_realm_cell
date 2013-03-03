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

class gurubashipvp : public PlayerScript
{
public:
	gurubashipvp() : PlayerScript("gurubashipvp") { }

    void OnPvPKill(Player *pKiller, Player *pVictim) {
		int reward = 100; //How many points shall the killer get?
		int pvparea = 2177; //Area ID of the place both characters must be to be eligible for reward
	    int area1 = pKiller->GetAreaId();
	    int area2 = pVictim->GetAreaId();
		if(area1 == area2) {
			int area = area;
			if(area == pvparea) {
				if(pKiller->GetTeam() != pVictim->GetTeam()) {
				    int honor = pKiller->GetHonorPoints();
				    pKiller->ModifyHonorPoints(honor + reward);
				}
			}
		}
    }
};

void AddSC_gurubashipvp() {
	new gurubashipvp;
}
