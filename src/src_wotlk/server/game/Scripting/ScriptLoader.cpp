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

#include "ScriptLoader.h"

//examples
void AddSC_example_creature();
void AddSC_example_escort();
void AddSC_example_gossip_codebox();
void AddSC_example_misc();
void AddSC_example_commandscript();

// spells
void AddSC_deathknight_spell_scripts();
void AddSC_druid_spell_scripts();
void AddSC_generic_spell_scripts();
void AddSC_hunter_spell_scripts();
void AddSC_mage_spell_scripts();
void AddSC_paladin_spell_scripts();
void AddSC_priest_spell_scripts();
void AddSC_rogue_spell_scripts();
void AddSC_shaman_spell_scripts();
void AddSC_warlock_spell_scripts();
void AddSC_warrior_spell_scripts();
void AddSC_quest_spell_scripts();
void AddSC_item_spell_scripts();
void AddSC_example_spell_scripts();

void AddSC_SmartSCripts();

//Commands
void AddSC_account_commandscript();
void AddSC_achievement_commandscript();
void AddSC_debug_commandscript();
void AddSC_event_commandscript();
void AddSC_gm_commandscript();
void AddSC_go_commandscript();
void AddSC_gobject_commandscript();
void AddSC_honor_commandscript();
void AddSC_learn_commandscript();
void AddSC_modify_commandscript();
void AddSC_npc_commandscript();
void AddSC_quest_commandscript();
void AddSC_reload_commandscript();
void AddSC_tele_commandscript();
void AddSC_titles_commandscript();
void AddSC_wp_commandscript();

#ifdef SCRIPTS
//world
void AddSC_areatrigger_scripts();
void AddSC_boss_emeriss();
void AddSC_boss_taerar();
void AddSC_boss_ysondre();
void AddSC_generic_creature();
void AddSC_go_scripts();
void AddSC_guards();
void AddSC_item_scripts();
void AddSC_npc_professions();
void AddSC_npc_innkeeper();
void AddSC_npcs_special();
void AddSC_npc_taxi();
void AddSC_achievement_scripts();

//Bots
void AddSC_druid_bot();
void AddSC_priest_bot();
void AddSC_shaman_bot();
void AddSC_warrior_bot();
void AddSC_rogue_bot();
void AddSC_mage_bot();
void AddSC_warlock_bot();
void AddSC_paladin_bot();
void AddSC_hunter_bot();
void AddSC_script_bot_giver();

// battlegrounds

// outdoor pvp
void AddSC_outdoorpvp_ep();
void AddSC_outdoorpvp_hp();
void AddSC_outdoorpvp_na();
void AddSC_outdoorpvp_si();
void AddSC_outdoorpvp_tf();
void AddSC_outdoorpvp_zm();

// player
void AddSC_lexics_chat_log();

// mody

void AddScripts()
{
    AddExampleScripts();
    AddSpellScripts();
    AddSC_SmartSCripts();
    AddCommandScripts();
#ifdef SCRIPTS
    AddWorldScripts();
    AddBattlegroundScripts();
    AddOutdoorPvPScripts();
    AddCustomScripts();
	AddModyScripts();
#endif
}

void AddExampleScripts()
{
    AddSC_example_creature();
    AddSC_example_escort();
    AddSC_example_gossip_codebox();
    AddSC_example_misc();
    AddSC_example_commandscript();
}

void AddSpellScripts()
{
    AddSC_deathknight_spell_scripts();
    AddSC_druid_spell_scripts();
    AddSC_generic_spell_scripts();
    AddSC_hunter_spell_scripts();
    AddSC_mage_spell_scripts();
    AddSC_paladin_spell_scripts();
    AddSC_priest_spell_scripts();
    AddSC_rogue_spell_scripts();
    AddSC_shaman_spell_scripts();
    AddSC_warlock_spell_scripts();
    AddSC_warrior_spell_scripts();
    AddSC_quest_spell_scripts();
    AddSC_item_spell_scripts();
    AddSC_example_spell_scripts();
}

void AddCommandScripts()
{
    AddSC_account_commandscript();
    AddSC_achievement_commandscript();
    AddSC_debug_commandscript();
    AddSC_event_commandscript();
    AddSC_gm_commandscript();
    AddSC_go_commandscript();
    AddSC_gobject_commandscript();
    AddSC_honor_commandscript();
    AddSC_learn_commandscript();
    AddSC_modify_commandscript();
    AddSC_npc_commandscript();
    AddSC_quest_commandscript();
    AddSC_reload_commandscript();
    AddSC_tele_commandscript();
    AddSC_titles_commandscript();
    AddSC_wp_commandscript();
}

void AddWorldScripts()
{
#ifdef SCRIPTS
    AddSC_areatrigger_scripts();
    AddSC_boss_emeriss();
    AddSC_boss_taerar();
    AddSC_boss_ysondre();
    AddSC_generic_creature();
    AddSC_go_scripts();
    AddSC_guards();
    AddSC_item_scripts();
    AddSC_npc_professions();
    AddSC_npc_innkeeper();
    AddSC_npcs_special();
    AddSC_npc_taxi();
    AddSC_achievement_scripts();

    //Bots
    AddSC_druid_bot();
    AddSC_priest_bot();
    AddSC_shaman_bot();
    AddSC_warrior_bot();
    AddSC_rogue_bot();
    AddSC_mage_bot();
    AddSC_warlock_bot();
    AddSC_paladin_bot();
    AddSC_hunter_bot();
    AddSC_script_bot_giver();

    AddSC_lexics_chat_log();
#endif
}

// mody
void AddModyScripts()
{

}
#endif

void AddOutdoorPvPScripts()
{
#ifdef SCRIPTS
    AddSC_outdoorpvp_ep();
    AddSC_outdoorpvp_hp();
    AddSC_outdoorpvp_na();
    AddSC_outdoorpvp_si();
    AddSC_outdoorpvp_tf();
    AddSC_outdoorpvp_zm();
#endif
}

void AddBattlegroundScripts()
{
#ifdef SCRIPTS
#endif
}

#ifdef SCRIPTS
	void AddSC_pryds_guildmaster();
	void AddSC_item_custom_stone();
	void AddSC_item_custom_summon();
	void AddSC_System_OnPVPKill();
	void AddSC_ItemRequester();
	void AddSC_pryds_buffer();
	void AddSC_npc_teleport();
	void AddSC_pryds_allinone();
	void AddSC_Npc_Beastmaster();
	void AddSC_Reset();
    void AddSC_VAS_AutoBalance();
    void AddSC_GoldOnKill();
    void AddSC_System_Xpforpvp();
    void AddSC_gurubashipvp();
    void AddSC_OnPlayerLogin();
    void AddSC_cs_world_chat();

	void AddSC_kill_mod();
	void AddSC_gm_login();
	void AddSC_Killstreak();
	void AddSC_PvPTitles();
	void AddSC_creature_mod();
#endif

void AddCustomScripts()
{
#ifdef SCRIPTS
	AddSC_pryds_guildmaster();
	AddSC_item_custom_stone();
	AddSC_item_custom_summon();
	AddSC_System_OnPVPKill();
	AddSC_ItemRequester();
	AddSC_pryds_buffer();
	AddSC_npc_teleport();
	AddSC_pryds_allinone();
	AddSC_Npc_Beastmaster();
	AddSC_Reset();
	AddSC_VAS_AutoBalance();
	AddSC_GoldOnKill();
	AddSC_System_Xpforpvp();
	AddSC_gurubashipvp();
	AddSC_OnPlayerLogin();
	AddSC_cs_world_chat();

	AddSC_kill_mod();
	AddSC_gm_login();
	AddSC_Killstreak();
	AddSC_PvPTitles();
	AddSC_creature_mod();
#endif
}
