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

/*
 * CREATE TABLE IF NOT EXISTS `killstreak` (
 *   `guid` int(10) unsigned NOT NULL,
 *   `ks` smallint(5) unsigned NOT NULL,
 *   `high_ks` smallint(5) unsigned NOT NULL,
 *   PRIMARY KEY (`guid`)
 * ) ENGINE=InnoDB DEFAULT CHARSET=latin1;
 */

#include "ScriptPCH.h"



bool isInArena(Player * player)
{
	//Blade's Edge Arena
	if (player->GetZoneId() == 3702)
		return true;
	//Ruins of Lordaeron
	if (player->GetZoneId() == 153)
		return true;
	//Nagrand Arena
	if (player->GetZoneId() == 3698)
		return true;

	return false;
}

void sleep()
{
	int i = 0;
	while (i <= 3000)
		i++;
}

int32 GetKillstreak(Player * player)
{
	sleep();
	QueryResult ks = CharacterDatabase.PQuery("SELECT * FROM killstreak WHERE guid = '%u'", player->GetGUID());
	if (!ks)
		return -1;
	Field * killstreak = ks->Fetch();

	return killstreak[1].GetInt32();
}

bool HasKillstreak(Player * player)
{
	QueryResult ks = CharacterDatabase.PQuery("SELECT * FROM killstreak WHERE guid = '%u'", player->GetGUID());
	if (!ks)
		return false;
	Field * ksfield = ks->Fetch();
	if (ksfield[1].GetInt32() == 0)
		return false;
	return true;
}

void alertServer(Player * killer, Player * victim, int32 killstreak, int code)
{
	std::string msg;
	std::string kstreak;
	std::stringstream ks;
	ks << killstreak;
	kstreak = ks.str();

	switch(code)
	{
		case 0:
			msg = "|cffff0000[Killstreak] |cffffffff";
			msg += victim->GetName();
			msg += "'s |cff00ffffkillstreak of ";
			msg += kstreak;
			msg += " has been ended by |cffffffff";
			msg += killer->GetName();
			break;
		case 1:
			msg = "|cffff0000[Killstreak] |cffffffff";
			msg += killer->GetName();
			msg += "|cff00ffff has a killstreak of ";
			msg += kstreak;
			break;
		case 2:
			msg = "|cffff0000[Killstreak] |cffffffff";
			msg += killer->GetName();
			msg += "|cff00ffff has a killstreak of ";
			msg += kstreak;
			msg += ". A bounty worth 50 arena points has been placed for their head.";
			break;
	}

	sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), 0);
}

class Killstreak : public PlayerScript
{
	public:
		Killstreak() : PlayerScript("Killstreak"){}

	void OnPVPKill(Player * killer, Player * victim)
	{
		if (killer->GetGUID() == victim->GetGUID())
			return;
		if (isInArena(killer) || isInArena(victim))
			return;

		// Clear any morphs and buffs the victim might have
		victim->DeMorph();
		victim->RemoveAllAuras();

		if (GetKillstreak(victim) >= 25)
		{
			killer->SetArenaPoints(killer->GetArenaPoints() + 50);
		}

		if (!HasKillstreak(killer))
			CharacterDatabase.PExecute("REPLACE INTO killstreak(guid, ks) VALUES ('%u', 1)", killer->GetGUID());
		else
		{
			CharacterDatabase.PExecute("UPDATE killstreak SET ks = (ks+1) WHERE guid = '%u'", killer->GetGUID());
			QueryResult ks = CharacterDatabase.PQuery("SELECT * FROM killstreak WHERE guid = '%u'", killer->GetGUID());
			Field * high_ks = ks->Fetch();
			if (GetKillstreak(killer) > high_ks[2].GetInt32())
				CharacterDatabase.PExecute("UPDATE killstreak SET high_ks = ks WHERE guid = '%u'", killer->GetGUID());

		}

		if (HasKillstreak(victim))
		{
			CharacterDatabase.PExecute("UPDATE killstreak SET ks = 0 WHERE guid = '%u'", victim->GetGUID());
			// Only send a server message if their streak is 5 or more
			if (GetKillstreak(victim) >= 5)
				alertServer(killer, victim, GetKillstreak(victim), 0);
		}

		uint32 kstreak = GetKillstreak(killer);

		switch(kstreak)
		{
			case 5:
				alertServer(killer, victim, kstreak, 1);
				killer->AddItem(6657, 5);
				break;
			case 10:
				alertServer(killer, victim, kstreak, 1);
				killer->AddItem(20558, 1);
				break;
			case 15:
				alertServer(killer, victim, kstreak, 1);
				killer->AddItem(8529, 15);
				break;
			case 20:
				alertServer(killer, victim, kstreak, 1);
				killer->AddItem(20558, 2);
				break;
			case 25:
				alertServer(killer, victim, kstreak, 2);
				break;
			case 30:
				alertServer(killer, victim, kstreak, 2);
				killer->AddItem(20558, 3);
				break;
			case 35:
				alertServer(killer, victim, kstreak, 2);
				break;
			case 40:
				alertServer(killer, victim, kstreak, 2);
				killer->AddItem(20558, 4);
				break;
			case 45:
				alertServer(killer, victim, kstreak, 2);
				break;
			case 50:
				alertServer(killer, victim, kstreak, 2);
				killer->AddItem(20558, 5);
				break;
			case 55:
				alertServer(killer, victim, kstreak, 2);
				break;
			case 60:
				alertServer(killer, victim, kstreak, 2);
				killer->AddItem(20558, 6);
				break;
			case 65:
				alertServer(killer, victim, kstreak, 2);
				break;
			case 70:
				alertServer(killer, victim, kstreak, 2);
				killer->AddItem(20558, 7);
				break;
			case 75:
				alertServer(killer, victim, kstreak, 2);
				break;
			case 80:
				alertServer(killer, victim, kstreak, 2);
				killer->AddItem(20558, 8);
				break;
			case 85:
				alertServer(killer, victim, kstreak, 2);
				break;
			case 90:
				alertServer(killer, victim, kstreak, 2);
				killer->AddItem(20558, 9);
				break;
			case 95:
				alertServer(killer, victim, kstreak, 2);
				break;
			case 100:
				alertServer(killer, victim, kstreak, 2);
				killer->AddItem(20558, 10);
				break;
		}
	}
};

void AddSC_Killstreak()
{
	new Killstreak();
}