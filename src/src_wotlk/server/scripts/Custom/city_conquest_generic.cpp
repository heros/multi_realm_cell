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
#include "../../game/CityConquestMgr.h"

struct city_conquest_genericAI : public ScriptedAI
{
    city_conquest_genericAI(Creature *c) : ScriptedAI(c) 
	{
		CityConquest.RegisterCreature(me, 0);
	}

    void Reset()
    {

    }

    void EnterCombat(Unit* pWho)
    {

    }

    void EnterEvadeMode()
    {
    }

    void UpdateAI(const uint32 uiDiff)
    {
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_city_conquest_generic(Creature* pCreature)
{
    return new city_conquest_genericAI (pCreature);
}

void AddSC_city_conquest_generic()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "city_conquest_generic";
    newscript->GetAI = &GetAI_city_conquest_generic;
    newscript->RegisterSelf();
}
