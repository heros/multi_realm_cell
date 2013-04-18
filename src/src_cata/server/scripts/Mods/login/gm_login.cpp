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

//Includes
#include "ScriptPCH.h"

//Define Spells
enum SkillSpells
{
	SPELL_BLOCK = 107,
	SPELL_BOWS = 264,
	SPELL_CROSSBOWS = 5011,
	SPELL_DAGGERS = 1180,
	SPELL_DUAL_WIELD = 674,
	SPELL_FIST_WEAPONS = 15590,
	SPELL_GUNS = 266,
	SPELL_MAIL = 8737,
	SPELL_PLATE = 750,
	SPELL_ONE_HANDED_AXES = 196,
	SPELL_ONE_HANDED_MACES = 198,
	SPELL_ONE_HANDED_SWORDS = 201,
	SPELL_TWO_HANDED_AXES = 197,
	SPELL_TWO_HANDED_MACES = 199,
	SPELL_TWO_HANDED_SWORDS = 202,
	SPELL_STAVES = 227,
	SPELL_THROW = 2764,
	SPELL_THROWN = 2567,
	SPELL_POLEARMS = 200,
	SPELL_RELIC = 52665,
	SPELL_RELIC_2 = 27764,
	SPELL_RELIC_3 = 27762,
	SPELL_RELIC_4 = 27763,
	SPELL_SHIELD = 9116,
	SPELL_SHOOT = 3018,
	SPELL_SHOOT_WANDS = 5019,
	SPELL_WANDS = 5009
};

//script
class gm_login : public PlayerScript
{
    public:

        gm_login() : PlayerScript("gm_login"){}

		uint64 playerGUID;
		void OnCreate(Player * player)
		{
			playerGUID = player->GetGUID();
		}

		void OnLogin(Player* player)
		{
			if (playerGUID == player->GetGUID())
			{
				QueryResult account = CharacterDatabase.PQuery("SELECT * FROM characters WHERE guid = '%u'", playerGUID);
				Field * accID = account->Fetch();
				QueryResult gmaccount = LoginDatabase.PQuery("SELECT * FROM account_access WHERE id = '%u' AND gmlevel >= '1'", accID[1].GetInt32());
				if (gmaccount)
				{

				switch(player->getClass())
				{

				/*#####################################################################
				# generic defines
				#####################################################################*/

              	case CLASS_PALADIN:
              	{
              	//spec
              	player->learnSpell(SPELL_BLOCK, true);
              	player->learnSpell(SPELL_ONE_HANDED_AXES, true);
              	player->learnSpell(SPELL_ONE_HANDED_MACES, true);
              	player->learnSpell(SPELL_ONE_HANDED_SWORDS, true);
              	player->learnSpell(SPELL_PLATE, true);
              	player->learnSpell(SPELL_POLEARMS, true);
              	player->learnSpell(SPELL_RELIC_3, true);
              	player->learnSpell(SPELL_SHIELD, true);
              	player->learnSpell(SPELL_TWO_HANDED_AXES, true);
              	player->learnSpell(SPELL_TWO_HANDED_MACES, true);
              	player->learnSpell(SPELL_TWO_HANDED_SWORDS, true);
              	// abylity
              	player->learnSpell(76271,false);
              	player->learnSpell(76294,false);
              	player->learnSpell(35395,false);
              	player->learnSpell(20271,false);
              	player->learnSpell(20154,false);
              	player->learnSpell(20165,false);
              	player->learnSpell(31801,false);
              	player->learnSpell(20164,false);
              	player->learnSpell(465,false);
              	player->learnSpell(7294,false);
              	player->learnSpell(19746,false);
              	player->learnSpell(32223,false);
              	player->learnSpell(19891,false);
              	player->learnSpell(635,false);
              	player->learnSpell(19750,false);
              	player->learnSpell(82326,false);
              	player->learnSpell(85673,false);
              	player->learnSpell(82242,false);
              	player->learnSpell(7328,false);
              	player->learnSpell(25780,false);
              	player->learnSpell(31789,false);
              	player->learnSpell(853,false);
              	player->learnSpell(62124,false);
              	player->learnSpell(1022,false);
              	player->learnSpell(1044,false);
              	player->learnSpell(1038,false);
              	player->learnSpell(633,false);
              	player->learnSpell(879,false);
              	player->learnSpell(73629,false);
              	player->learnSpell(69820,false);
              	player->learnSpell(13819,false);
              	player->learnSpell(34769,false);
              	player->learnSpell(73630,false);
              	player->learnSpell(69826,false);
              	player->learnSpell(23214,false);
              	player->learnSpell(34767,false);
              	player->learnSpell(20217,false);
              	player->learnSpell(19740,false);
              	player->learnSpell(26573,false);
              	player->learnSpell(2812,false);
              	player->learnSpell(498,false);
              	player->learnSpell(4987,false);
              	player->learnSpell(54428,false);
              	player->learnSpell(24275,false);
              	player->learnSpell(642,false);
              	player->learnSpell(86525,false);
              	player->learnSpell(87511,false);
              	player->learnSpell(96231,false);
              	player->learnSpell(31884,false);
              	player->learnSpell(10326,false);
              	player->learnSpell(6940,false);
              	player->learnSpell(86474,false);
              	player->learnSpell(87494,false);
              	player->learnSpell(84963,false);
              	player->learnSpell(82327,false);
              	player->learnSpell(86150,false);
              	// dodatek
              	}
				break;

              	case CLASS_SHAMAN:
              	{
              	//spec
              	player->learnSpell(SPELL_BLOCK, true);
              	player->learnSpell(SPELL_FIST_WEAPONS, true);
              	player->learnSpell(SPELL_MAIL, true);
              	player->learnSpell(SPELL_ONE_HANDED_AXES, true);
              	player->learnSpell(SPELL_ONE_HANDED_MACES, true);
              	player->learnSpell(SPELL_RELIC_4, true);
              	player->learnSpell(SPELL_SHIELD, true);
              	player->learnSpell(SPELL_STAVES, true);
              	player->learnSpell(SPELL_TWO_HANDED_AXES, true);
              	player->learnSpell(SPELL_TWO_HANDED_MACES, true);
              	// abylity
              	player->learnSpell(2008,false);
              	player->learnSpell(76272,false);
              	player->learnSpell(556,false);
              	player->learnSpell(76780,false);
              	player->learnSpell(2825,false);
              	player->learnSpell(66843,false);
              	player->learnSpell(66842,false);
              	player->learnSpell(66844,false);
              	player->learnSpell(51886,false);
              	player->learnSpell(2062,false);
              	player->learnSpell(8042,false);
              	player->learnSpell(2484,false);
              	player->learnSpell(51730,false);
              	player->learnSpell(8184,false);
              	player->learnSpell(6196,false);
              	player->learnSpell(2894,false);
              	player->learnSpell(8349,false);
              	player->learnSpell(1535,false);
              	player->learnSpell(8050,false);
              	player->learnSpell(8227,false);
              	player->learnSpell(8042,false);
              	player->learnSpell(8056,false);
              	player->learnSpell(8033,false);
              	player->learnSpell(2645,false);
              	player->learnSpell(77472,false);
              	player->learnSpell(8177,false);
              	player->learnSpell(73920,false);
              	player->learnSpell(5394,false);
              	player->learnSpell(8004,false);
              	player->learnSpell(331,false);
              	player->learnSpell(32182,false);
              	player->learnSpell(51514,false);
              	player->learnSpell(1064,false);
              	player->learnSpell(421,false);
              	player->learnSpell(51505,false);
              	player->learnSpell(403,false);
              	player->learnSpell(324,false);
              	player->learnSpell(8190,false);
              	player->learnSpell(86529,false);
              	player->learnSpell(87507,false);
              	player->learnSpell(5675,false);
              	player->learnSpell(86477,false);
              	player->learnSpell(87497,false);
              	player->learnSpell(73899,false);
              	player->learnSpell(370,false);
              	player->learnSpell(20608,false);
              	player->learnSpell(8017,false);
              	player->learnSpell(3599,false);
              	player->learnSpell(79206,false);
              	player->learnSpell(5730,false);
              	player->learnSpell(8071,false);
              	player->learnSpell(8075,false);
              	player->learnSpell(87718,false);
              	player->learnSpell(36936,false);
              	player->learnSpell(8143,false);
              	player->learnSpell(73683,false);
              	player->learnSpell(73682,false);
              	player->learnSpell(73681,false);
              	player->learnSpell(131,false);
              	player->learnSpell(52127,false);
              	player->learnSpell(546,false);
              	player->learnSpell(76296,false);
              	player->learnSpell(57994,false);
              	player->learnSpell(8512,false);
              	player->learnSpell(8232,false);
              	player->learnSpell(3738,false);
              	// dodatek
              	player->learnSpell(8024,false);
              	player->learnSpell(73680,false);
              	}
				break;

              	case CLASS_WARRIOR:
              	{
              	//spec
              	player->learnSpell(SPELL_BLOCK, true);
              	player->learnSpell(SPELL_BOWS, true);
              	player->learnSpell(SPELL_CROSSBOWS, true);
              	player->learnSpell(SPELL_DUAL_WIELD, true);
              	player->learnSpell(SPELL_FIST_WEAPONS, true);
              	player->learnSpell(SPELL_GUNS, true);
              	player->learnSpell(SPELL_ONE_HANDED_AXES, true);
              	player->learnSpell(SPELL_ONE_HANDED_MACES, true);
              	player->learnSpell(SPELL_ONE_HANDED_SWORDS, true);
              	player->learnSpell(SPELL_PLATE, true);
              	player->learnSpell(SPELL_POLEARMS, true);
              	player->learnSpell(SPELL_SHIELD, true);
              	player->learnSpell(SPELL_SHOOT, true);
              	player->learnSpell(SPELL_STAVES, true);
              	player->learnSpell(SPELL_THROW, true);
              	player->learnSpell(SPELL_THROWN, true);
              	player->learnSpell(SPELL_TWO_HANDED_AXES, true);
              	player->learnSpell(SPELL_TWO_HANDED_MACES, true);
              	player->learnSpell(SPELL_TWO_HANDED_SWORDS, true);
              	// abylity
              	player->learnSpell(76268,false);
              	player->learnSpell(88163,false);
              	player->learnSpell(6673,false);
              	player->learnSpell(469,false);
              	player->learnSpell(1160,false);
              	player->learnSpell(2457,false);
              	player->learnSpell(2458,false);
              	player->learnSpell(71,false);
              	player->learnSpell(18499,false);
              	player->learnSpell(845,false);
              	player->learnSpell(86346,false);
              	player->learnSpell(676,false);
              	player->learnSpell(55694,false);
              	player->learnSpell(5308,false);
              	player->learnSpell(1715,false);
              	player->learnSpell(6544,false);
              	player->learnSpell(78,false);
              	player->learnSpell(57755,false);
              	player->learnSpell(1161,false);
              	player->learnSpell(100,false);
              	player->learnSpell(1134,false);
              	player->learnSpell(20252,false);
              	player->learnSpell(3411,false);
              	player->learnSpell(5246,false);
              	player->learnSpell(86479,false);
              	player->learnSpell(87500,false);
              	player->learnSpell(7384,false);
              	player->learnSpell(3127,false);
              	player->learnSpell(86526,false);
              	player->learnSpell(87509,false);
              	player->learnSpell(6552,false);
              	player->learnSpell(97462,false);
              	player->learnSpell(1719,false);
              	player->learnSpell(772,false);
              	player->learnSpell(20230,false);
              	player->learnSpell(6572,false);
              	player->learnSpell(64382,false);
              	player->learnSpell(2565,false);
              	player->learnSpell(871,false);
              	player->learnSpell(1464,false);
              	player->learnSpell(23920,false);
              	player->learnSpell(12678,false);
              	player->learnSpell(88161,false);
              	player->learnSpell(7386,false);
              	player->learnSpell(355,false);
              	player->learnSpell(6343,false);
              	player->learnSpell(34428,false);
              	player->learnSpell(76290,false);
              	player->learnSpell(1680,false);
              	// dodatek
              	}
				break;

              	case CLASS_HUNTER:
              	{
              	//spec
              	player->learnSpell(SPELL_BOWS, true);
              	player->learnSpell(SPELL_CROSSBOWS, true);
              	player->learnSpell(SPELL_DUAL_WIELD, true);
              	player->learnSpell(SPELL_FIST_WEAPONS, true);
              	player->learnSpell(SPELL_GUNS, true);
              	player->learnSpell(SPELL_MAIL, true);
              	player->learnSpell(SPELL_ONE_HANDED_AXES, true);
              	player->learnSpell(SPELL_ONE_HANDED_SWORDS, true);
              	player->learnSpell(SPELL_POLEARMS, true);
              	player->learnSpell(SPELL_STAVES, true);
              	player->learnSpell(SPELL_TWO_HANDED_AXES, true);
              	player->learnSpell(SPELL_TWO_HANDED_SWORDS, true);
				// abylity
              	player->learnSpell(3044,false);
              	player->learnSpell(76250,false);
              	player->learnSpell(20043,false);
              	player->learnSpell(13159,false);
              	player->learnSpell(5118,false);
              	player->learnSpell(13165,false);
              	player->learnSpell(82661,false);
              	player->learnSpell(75,false);
              	player->learnSpell(1462,false);
              	player->learnSpell(883,false);
              	player->learnSpell(83242,false);
              	player->learnSpell(83243,false);
              	player->learnSpell(83244,false);
              	player->learnSpell(83245,false);
              	player->learnSpell(51753,false);
              	player->learnSpell(51755,false);
              	player->learnSpell(77767,false);
              	player->learnSpell(5116,false);
              	player->learnSpell(79682,false);
              	player->learnSpell(19263,false);
              	player->learnSpell(781,false);
              	player->learnSpell(2641,false);
              	player->learnSpell(20736,false);
              	player->learnSpell(6197,false);
              	player->learnSpell(77769,false);
              	player->learnSpell(13813,false);
              	player->learnSpell(82939,false);
              	player->learnSpell(1499,false);
              	player->learnSpell(60192,false);
              	player->learnSpell(13809,false);
              	player->learnSpell(82941,false);
              	player->learnSpell(13795,false);
              	player->learnSpell(82945,false);
              	player->learnSpell(34600,false);
              	player->learnSpell(82948,false);
              	player->learnSpell(6991,false);
              	player->learnSpell(5384,false);
              	player->learnSpell(1543,false);
              	player->learnSpell(1130,false);
              	player->learnSpell(34026,false);
              	player->learnSpell(53351,false);
              	player->learnSpell(86528,false);
              	player->learnSpell(87506,false);
              	player->learnSpell(53271,false);
              	player->learnSpell(86472,false);
              	player->learnSpell(87493,false);
              	player->learnSpell(136,false);
              	player->learnSpell(34477,false);
              	player->learnSpell(2643,false);
              	player->learnSpell(82243,false);
              	player->learnSpell(3045,false);
              	player->learnSpell(2973,false);
              	player->learnSpell(982,false);
              	player->learnSpell(1513,false);
              	player->learnSpell(19503,false);
              	player->learnSpell(1978,false);
              	player->learnSpell(56641,false);
              	player->learnSpell(1515,false);
              	player->learnSpell(19884,false);
              	player->learnSpell(19883,false);
              	player->learnSpell(19885,false);
              	player->learnSpell(19882,false);
              	player->learnSpell(19880,false);
              	player->learnSpell(19879,false);
              	player->learnSpell(19878,false);
              	player->learnSpell(1494,false);
              	player->learnSpell(19801,false);
              	player->learnSpell(76249,false);
              	player->learnSpell(82654,false);
              	player->learnSpell(2974,false);
              	// dodatek
              	player->learnSpell(79682,false);
              	player->learnSpell(93321,false);
              	}
				break;

              	case CLASS_ROGUE:
              	{
              	//spec
              	player->learnSpell(SPELL_BOWS, true);
              	player->learnSpell(SPELL_CROSSBOWS, true);
              	player->learnSpell(SPELL_DUAL_WIELD, true);
              	player->learnSpell(SPELL_FIST_WEAPONS, true);
              	player->learnSpell(SPELL_GUNS, true);
              	player->learnSpell(SPELL_ONE_HANDED_AXES, true);
              	player->learnSpell(SPELL_ONE_HANDED_MACES, true);
              	player->learnSpell(SPELL_ONE_HANDED_SWORDS, true);
              	player->learnSpell(SPELL_SHOOT, true);
              	player->learnSpell(SPELL_THROW, true);
              	player->learnSpell(SPELL_THROWN, true);
				// abylity
              	player->learnSpell(76273,false);
              	player->learnSpell(76297,false);
              	player->learnSpell(1752,false);
              	player->learnSpell(1752,false);
              	player->learnSpell(79327,false);
              	player->learnSpell(1784,false);
              	player->learnSpell(921,false);
              	player->learnSpell(8676,false);
              	player->learnSpell(5277,false);
              	player->learnSpell(2842,false);
              	player->learnSpell(6770,false);
              	player->learnSpell(82245,false);
              	player->learnSpell(73651,false);
              	player->learnSpell(1766,false);
              	player->learnSpell(1776,false);
              	player->learnSpell(1804,false);
              	player->learnSpell(2983,false);
              	player->learnSpell(53,false);
              	player->learnSpell(5171,false);
              	player->learnSpell(1856,false);
              	player->learnSpell(1833,false);
              	player->learnSpell(1725,false);
              	player->learnSpell(408,false);
              	player->learnSpell(2836,false);
              	player->learnSpell(2094,false);
              	player->learnSpell(8647,false);
              	player->learnSpell(51722,false);
              	player->learnSpell(703,false);
              	player->learnSpell(1966,false);
              	player->learnSpell(1842,false);
              	player->learnSpell(1943,false);
              	player->learnSpell(1860,false);
              	player->learnSpell(86531,false);
              	player->learnSpell(87504,false);
              	player->learnSpell(32645,false);
              	player->learnSpell(31224,false);
              	player->learnSpell(26679,false);
              	player->learnSpell(5938,false);
              	player->learnSpell(57934,false);
              	player->learnSpell(51723,false);
              	player->learnSpell(86476,false);
              	player->learnSpell(87496,false);
              	player->learnSpell(74001,false);
              	player->learnSpell(73981,false);
              	player->learnSpell(76577,false);
              	// dodatek
              	player->learnSpell(2098,false);
              	}
              	break;

              	case CLASS_DRUID:
              	{
              	//spec
              	player->learnSpell(SPELL_DAGGERS, true);
              	player->learnSpell(SPELL_FIST_WEAPONS, true);
              	player->learnSpell(SPELL_ONE_HANDED_MACES, true);
              	player->learnSpell(SPELL_POLEARMS, true);
              	player->learnSpell(SPELL_RELIC_2, true);
              	player->learnSpell(SPELL_STAVES, true);
              	player->learnSpell(SPELL_TWO_HANDED_MACES, true);
              	// abylity
              	player->learnSpell(76275,false);
              	player->learnSpell(76300,false);
              	player->learnSpell(84736,false);
              	player->learnSpell(5176,false);
              	player->learnSpell(8921,false);
              	player->learnSpell(467,false);
              	player->learnSpell(339,false);
              	player->learnSpell(768,false);
              	player->learnSpell(1082,false);
              	player->learnSpell(22568,false);
              	player->learnSpell(50464,false);
              	player->learnSpell(1822,false);
              	player->learnSpell(774,false);
              	player->learnSpell(2912,false);
              	player->learnSpell(33876,false);
              	player->learnSpell(33878,false);
              	player->learnSpell(5215,false);
              	player->learnSpell(8936,false);
              	player->learnSpell(50769,false);
              	player->learnSpell(5487,false);
              	player->learnSpell(99,false);
              	player->learnSpell(6795,false);
              	player->learnSpell(6807,false);
              	player->learnSpell(18960,false);
              	player->learnSpell(1066,false);
              	player->learnSpell(783,false);
              	player->learnSpell(779,false);
              	player->learnSpell(5570,false);
              	player->learnSpell(16864,false);
              	player->learnSpell(20484,false);
              	player->learnSpell(5229,false);
              	player->learnSpell(6785,false);
              	player->learnSpell(81170,false);
              	player->learnSpell(80964,false);
              	player->learnSpell(80965,false);
              	player->learnSpell(770,false);
              	player->learnSpell(16857,false);
              	player->learnSpell(2782,false);
              	player->learnSpell(5217,false);
              	player->learnSpell(8998,false);
              	player->learnSpell(1850,false);
              	player->learnSpell(20719,false);
              	player->learnSpell(5209,false);
              	player->learnSpell(29166,false);
              	player->learnSpell(2908,false);
              	player->learnSpell(1126,false);
              	player->learnSpell(5211,false);
              	player->learnSpell(5225,false);
              	player->learnSpell(9005,false);
              	player->learnSpell(62078,false);
              	player->learnSpell(62600,false);
              	player->learnSpell(16914,false);
              	player->learnSpell(5221,false);
              	player->learnSpell(2637,false);
              	player->learnSpell(86530,false);
              	player->learnSpell(87505,false);
              	player->learnSpell(22842,false);
              	player->learnSpell(16689,false);
              	player->learnSpell(1079,false);
              	player->learnSpell(22812,false);
              	player->learnSpell(33943,false);
              	player->learnSpell(22570,false);
              	player->learnSpell(33763,false);
              	player->learnSpell(33745,false);
              	player->learnSpell(740,false);
              	player->learnSpell(40120,false);
              	player->learnSpell(33786,false);
              	player->learnSpell(52610,false);
              	player->learnSpell(5185,false);
              	player->learnSpell(86470,false);
              	player->learnSpell(87491,false);
              	player->learnSpell(78777,false);
              	player->learnSpell(77758,false);
              	player->learnSpell(77761,false);
              	player->learnSpell(77764,false);
              	player->learnSpell(88747,false);
              	player->learnSpell(88751,false);
              	// dodatek
              	}
				break;

              	case CLASS_MAGE:
              	{
              	//spec
              	player->learnSpell(SPELL_DAGGERS, true);
              	player->learnSpell(SPELL_ONE_HANDED_SWORDS, true);
              	player->learnSpell(SPELL_SHOOT_WANDS, true);
              	player->learnSpell(SPELL_STAVES, true);
              	player->learnSpell(SPELL_WANDS, true);
              	// abylity
              	player->learnSpell(76276,false);
              	player->learnSpell(76298,false);
              	player->learnSpell(133,false);
              	player->learnSpell(5143,false);
              	player->learnSpell(2136,false);
              	player->learnSpell(116,false);
              	player->learnSpell(122,false);
              	player->learnSpell(2139,false);
              	player->learnSpell(92315,false);
              	player->learnSpell(12051,false);
              	player->learnSpell(118,false);
              	player->learnSpell(1953,false);
              	player->learnSpell(120,false);
              	player->learnSpell(30451,false);
              	player->learnSpell(1449,false);
              	player->learnSpell(3565,false);
              	player->learnSpell(32271,false);
              	player->learnSpell(3562,false);
              	player->learnSpell(3567,false);
              	player->learnSpell(32272,false);
              	player->learnSpell(3561,false);
              	player->learnSpell(49359,false);
              	player->learnSpell(3566,false);
              	player->learnSpell(3563,false);
              	player->learnSpell(2948,false);
              	player->learnSpell(45438,false);
              	player->learnSpell(475,false);
              	player->learnSpell(130,false);
              	player->learnSpell(30482,false);
              	player->learnSpell(11419,false);
              	player->learnSpell(32266,false);
              	player->learnSpell(11416,false);
              	player->learnSpell(11417,false);
              	player->learnSpell(32267,false);
              	player->learnSpell(10059,false);
              	player->learnSpell(49360,false);
              	player->learnSpell(11420,false);
              	player->learnSpell(11418,false);
              	player->learnSpell(2120,false);
              	player->learnSpell(88148,false);
              	player->learnSpell(1463,false);
              	player->learnSpell(759,false);
              	player->learnSpell(55342,false);
              	player->learnSpell(89744,false);
              	player->learnSpell(10,false);
              	player->learnSpell(49361,false);
              	player->learnSpell(49358,false);
              	player->learnSpell(7302,false);
              	player->learnSpell(44614,false);
              	player->learnSpell(1459,false);
              	player->learnSpell(61721,false);
              	player->learnSpell(28272,false);
              	player->learnSpell(61305,false);
              	player->learnSpell(28271,false);
              	player->learnSpell(61780,false);
              	player->learnSpell(33690,false);
              	player->learnSpell(35715,false);
              	player->learnSpell(33691,false);
              	player->learnSpell(35717,false);
              	player->learnSpell(6117,false);
              	player->learnSpell(30449,false);
              	player->learnSpell(53140,false);
              	player->learnSpell(53142,false);
              	player->learnSpell(43987,false);
              	player->learnSpell(66,false);
              	player->learnSpell(61316,false);
              	player->learnSpell(86467,false);
              	player->learnSpell(86473,false);
              	player->learnSpell(82731,false);
              	player->learnSpell(82691,false);
              	player->learnSpell(82676,false);
              	player->learnSpell(88345,false);
              	player->learnSpell(88346,false);
              	player->learnSpell(88342,false);
              	player->learnSpell(88344,false);
              	player->learnSpell(80353,false);
              	// dodatek
              	player->learnSpell(30455,false);
              	player->learnSpell(543,false);
              	player->learnSpell(42955,false);
              	}
				break;

              	case CLASS_WARLOCK:
              	{
              	//spec
              	player->learnSpell(SPELL_DAGGERS, true);
              	player->learnSpell(SPELL_ONE_HANDED_SWORDS, true);
              	player->learnSpell(SPELL_SHOOT_WANDS, true);
              	player->learnSpell(SPELL_STAVES, true);
              	player->learnSpell(SPELL_WANDS, true);
				// abylity
              	player->learnSpell(84741,false);
              	player->learnSpell(76277,false);
              	player->learnSpell(76299,false);
              	player->learnSpell(54786,false);
              	player->learnSpell(686,false);
              	player->learnSpell(86213,false);
              	player->learnSpell(688,false);
              	player->learnSpell(348,false);
              	player->learnSpell(172,false);
              	player->learnSpell(1454,false);
              	player->learnSpell(89420,false);
              	player->learnSpell(689,false);
              	player->learnSpell(687,false);
              	player->learnSpell(697,false);
              	player->learnSpell(6201,false);
              	player->learnSpell(80388,false);
              	player->learnSpell(93375,false);
              	player->learnSpell(93376,false);
              	player->learnSpell(1120,false);
              	player->learnSpell(74434,false);
              	player->learnSpell(980,false);
              	player->learnSpell(755,false);
              	player->learnSpell(79268,false);
              	player->learnSpell(5782,false);
              	player->learnSpell(702,false);
              	player->learnSpell(5697,false);
              	player->learnSpell(693,false);
              	player->learnSpell(5740,false);
              	player->learnSpell(5676,false);
              	player->learnSpell(603,false);
              	player->learnSpell(5784,false);
              	player->learnSpell(6353,false);
              	player->learnSpell(19028,false);
              	player->learnSpell(712,false);
              	player->learnSpell(126,false);
              	player->learnSpell(1714,false);
              	player->learnSpell(1098,false);
              	player->learnSpell(85403,false);
              	player->learnSpell(1949,false);
              	player->learnSpell(691,false);
              	player->learnSpell(710,false);
              	player->learnSpell(6229,false);
              	player->learnSpell(23161,false);
              	player->learnSpell(6789,false);
              	player->learnSpell(698,false);
              	player->learnSpell(5484,false);
              	player->learnSpell(22703,false);
              	player->learnSpell(86091,false);
              	player->learnSpell(1122,false);
              	player->learnSpell(1490,false);
              	player->learnSpell(18540,false);
              	player->learnSpell(54785,false);
              	player->learnSpell(50590,false);
              	player->learnSpell(50589,false);
              	player->learnSpell(28176,false);
              	player->learnSpell(29722,false);
              	player->learnSpell(29858,false);
              	player->learnSpell(29893,false);
              	player->learnSpell(27243,false);
              	player->learnSpell(47960,false);
              	player->learnSpell(47897,false);
              	player->learnSpell(48018,false);
              	player->learnSpell(48020,false);
              	player->learnSpell(86478,false);
              	player->learnSpell(87498,false);
              	player->learnSpell(77799,false);
              	player->learnSpell(80398,false);
              	player->learnSpell(77801,false);
              	// dodatek
              	}
              	break;

              	case CLASS_PRIEST:
              	{
              	//spec
              	player->learnSpell(SPELL_DAGGERS, true);
              	player->learnSpell(SPELL_ONE_HANDED_MACES, true);
              	player->learnSpell(SPELL_SHOOT_WANDS, true);
              	player->learnSpell(SPELL_STAVES, true);
              	player->learnSpell(SPELL_WANDS, true);
				// abylity
              	player->learnSpell(76279,false);
              	player->learnSpell(76301,false);
              	player->learnSpell(88685,false);
              	player->learnSpell(585,false);
              	player->learnSpell(2061,false);
              	player->learnSpell(589,false);
              	player->learnSpell(17,false);
              	player->learnSpell(588,false);
              	player->learnSpell(139,false);
              	player->learnSpell(8092,false);
              	player->learnSpell(8122,false);
              	player->learnSpell(21562,false);
              	player->learnSpell(2006,false);
              	player->learnSpell(2050,false);
              	player->learnSpell(14914,false);
              	player->learnSpell(70772,false);
              	player->learnSpell(88684,false);
              	player->learnSpell(528,false);
              	player->learnSpell(586,false);
              	player->learnSpell(527,false);
              	player->learnSpell(2944,false);
              	player->learnSpell(9484,false);
              	player->learnSpell(32379,false);
              	player->learnSpell(1706,false);
              	player->learnSpell(2096,false);
              	player->learnSpell(2060,false);
              	player->learnSpell(605,false);
              	player->learnSpell(596,false);
              	player->learnSpell(32546,false);
              	player->learnSpell(89745,false);
              	player->learnSpell(27683,false);
              	player->learnSpell(6346,false);
              	player->learnSpell(453,false);
              	player->learnSpell(8129,false);
              	player->learnSpell(15237,false);
              	player->learnSpell(64901,false);
              	player->learnSpell(34433,false);
              	player->learnSpell(33076,false);
              	player->learnSpell(32375,false);
              	player->learnSpell(48045,false);
              	player->learnSpell(64843,false);
              	player->learnSpell(86475,false);
              	player->learnSpell(87495,false);
              	player->learnSpell(73510,false);
              	player->learnSpell(73413,false);
              	player->learnSpell(73325,false);
              	// dodatek
              	}
				break;

              	case CLASS_DEATH_KNIGHT:
              	{
              	//spec
              	player->learnSpell(SPELL_DUAL_WIELD, true);
              	player->learnSpell(SPELL_ONE_HANDED_AXES, true);
              	player->learnSpell(SPELL_ONE_HANDED_MACES, true);
              	player->learnSpell(SPELL_ONE_HANDED_SWORDS, true);
              	player->learnSpell(SPELL_PLATE, true);
              	player->learnSpell(SPELL_POLEARMS, true);
              	player->learnSpell(SPELL_RELIC, true);
              	player->learnSpell(SPELL_TWO_HANDED_AXES, true);
              	player->learnSpell(SPELL_TWO_HANDED_MACES, true);
              	player->learnSpell(SPELL_TWO_HANDED_SWORDS, true);
                // abylity
              	player->learnSpell(76282,false);
              	player->learnSpell(59921,false);
                //player->learnSpell(66198,false); http://www.wowhead.com/spell=66198
              	player->learnSpell(76292,false);
              	player->learnSpell(59879,false);
              	player->learnSpell(49410,false);
              	player->learnSpell(82246,false);
              	player->learnSpell(86524,false);
              	player->learnSpell(48778,false);
              	player->learnSpell(45902,false);
              	player->learnSpell(47541,false);
              	player->learnSpell(50977,false);
              	player->learnSpell(49576,false);
              	player->learnSpell(46266,false);
              	player->learnSpell(45477,false);
              	player->learnSpell(45462,false);
              	player->learnSpell(53341,false);
              	player->learnSpell(53343,false);
              	player->learnSpell(53428,false);
              	player->learnSpell(49998,false);
              	player->learnSpell(50842,false);
              	player->learnSpell(46584,false);
              	player->learnSpell(48263,false);
              	player->learnSpell(47528,false);
              	player->learnSpell(54447,false);
              	player->learnSpell(53342,false);
              	player->learnSpell(48721,false);
              	player->learnSpell(45524,false);
              	player->learnSpell(47476,false);
              	player->learnSpell(43265,false);
              	player->learnSpell(53331,false);
              	player->learnSpell(49020,false);
              	player->learnSpell(3714,false);
              	player->learnSpell(48792,false);
              	player->learnSpell(54446,false);
              	player->learnSpell(53323,false);
              	player->learnSpell(45529,false);
              	player->learnSpell(85948,false);
              	player->learnSpell(56222,false);
              	player->learnSpell(57330,false);
              	player->learnSpell(58743,false);
              	player->learnSpell(56815,false);
              	player->learnSpell(48707,false);
              	player->learnSpell(81229,false);
              	player->learnSpell(53344,false);
              	player->learnSpell(48265,false);
              	player->learnSpell(61999,false);
              	player->learnSpell(70164,false);
              	player->learnSpell(62158,false);
              	player->learnSpell(86061,false);
              	player->learnSpell(47568,false);
              	player->learnSpell(42650,false);
              	player->learnSpell(86471,false);
              	player->learnSpell(87492,false);
              	player->learnSpell(77575,false);
              	player->learnSpell(73975,false);
              	player->learnSpell(77606,false);
				//dk complete all quests and spells 
              	player->SetFreeTalentPoints(41);
              	player->SendTalentsInfoData(true);
              	player->learnSpell(50977,false);    //Dark Portal
              	player->learnSpell(53428,false);    //Runen Schmieden
              	player->learnSpell(48778,false);    //DK Mount 
              	player->TeleportTo(0, 2356.03f, -5659.99f, 384.91f, 3.84f, 0);
              	}
				break;
				}
				}

				/*#####################################################################
				# generic defines
				#####################################################################*/

			    if (playerGUID == player->GetGUID())
			    {
				switch(player->getRace())
				{

              	case RACE_DWARF:
              	{
				}
				}

				/*#####################################################################
				# generic defines
				#####################################################################*/
				//gm shit robe start
				player->AddItem(12064, 1);
				player->AddItem(2586, 1);
				player->AddItem(11508, 1);
				player->AddItem(38082, 4);
				player->ModifyMoney(1000000000);
				playerGUID = 0;
				//gm shit robe end
				/* Learn Mounts start*/
				//pozemne
                player->learnSpell(89520,false);
                player->learnSpell(8395,false);
                player->learnSpell(41252,false);
                player->learnSpell(58983,false);
                player->learnSpell(42777,false);
                player->learnSpell(90621,false);
                //vodne
                player->learnSpell(75207,false);
                player->learnSpell(30174,false);
                player->learnSpell(64731,false);
                player->learnSpell(98718,false);
                //letajuce
                player->learnSpell(40192,false);
                player->learnSpell(72808,false);
                player->learnSpell(75614,false);
                player->learnSpell(75973,false);
                player->learnSpell(40192,false);
				/* Learn Mounts  end */
				/* Learn Minions start*/
				player->learnSpell(10713,false);
                player->learnSpell(62562,false);
                player->learnSpell(10685,false);
                player->learnSpell(89670,false);
                player->learnSpell(10696,false);
                player->learnSpell(61855,false);
                player->learnSpell(40549,false);
                player->learnSpell(10714,false);
                player->learnSpell(10675,false);
                player->learnSpell(75134,false);
                player->learnSpell(65358,false);
                player->learnSpell(90523,false);
                player->learnSpell(69452,false);
                player->learnSpell(10674,false);
                player->learnSpell(84263,false);
				/* Learn Minions  end */
				/* 85 lvl start*/
				 player->GiveLevel(85);
				/* 85 lvl end */
				/* end off some learns and items spawns */
				/* Efekts ala abraka-dabraka!? :D start*/
              	player->CastSpell(player,61456,false);
				// in start all buffs 
              	player->CastSpell(player,36880,true);
                player->CastSpell(player,1126,true);
              	player->CastSpell(player,20217,true);
              	player->CastSpell(player,27683,true);
              	player->CastSpell(player,39234,true);
				/* Efekts ala abraka-dabraka!? :D  end */
				/* bla bla server info start*/
				player->PlayDirectSound(11965);
				player->MonsterWhisper("Server Powered by Likan Mod", player->GetGUID());
			    player->MonsterWhisper("Likan Mod 2012-2013", player->GetGUID());
			    player->MonsterWhisper("Project name : Likan Mod", player->GetGUID());
			    player->MonsterWhisper("Author name : Likan", player->GetGUID());
			    player->MonsterWhisper("For updates visit :", player->GetGUID()); 
			    player->MonsterWhisper("https://github.com/ChaosDevLikan/multi_realm_cell", player->GetGUID());
				/* bla bla server info end */
				/* Most enums !!! start*/
			    player->UpdateSkillsToMaxSkillsForLevel();
				player->SaveToDB();
				/* Most enums !!! end */
			    }
				}
			}
		//}
};

void AddSC_gm_login()
{
    new gm_login();
}