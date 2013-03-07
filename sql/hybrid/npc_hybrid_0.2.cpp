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

/* ScriptData
SDName: Hybrid_2.1
SD%Complete: 55%
SDComment: Hybrid_2.1
...
MENU
...
...
SDCategory: Custom NPC Script
EndScriptData */

/*###
# generic defines
###*/

//Includes
#include "ScriptPCH.h"

//Define Spells
#define SPELL_REPUTATION    61456  //Only Visual Effect
//kecani
#define GOSSIP_PRAVYDLA 50800
//script

class npc_hybrid : public CreatureScript
{
    public:
        npc_hybrid() : CreatureScript("npc_hybrid") { }

                bool OnGossipHello(Player *player, Creature *_creature)
                {
                        if (player->isInCombat())
                        {
                                player->CLOSE_GOSSIP_MENU();
                                _creature->MonsterWhisper("Si v boji , prid pozdeji ! / You are in combat. Come back later!", player->GetGUID());

                        return true;
                        }
                else
                        {

/********** effekty **********/
          player->SetHealth(player->GetMaxHealth());
          player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
          player->RemoveAllSpellCooldown();
          _creature->MonsterSay("Vitaj :) / Hi :)" ,0 , player->GetGUID());
/********** effekty **********/
/********** menu **********/
    player->ADD_GOSSIP_ITEM( 7, "[Info] ->"                    , GOSSIP_SENDER_MAIN, 100000000);
    player->ADD_GOSSIP_ITEM( 7, "[Shoop] ->"                    , GOSSIP_SENDER_MAIN, 8500);
    player->ADD_GOSSIP_ITEM( 7, "[Cities] ->"                    , GOSSIP_SENDER_MAIN, 5576);
    player->ADD_GOSSIP_ITEM( 7, "[Exp. maps] ->"                    , GOSSIP_SENDER_MAIN, 7782);
    player->ADD_GOSSIP_ITEM( 7, "[Instances] ->"      , GOSSIP_SENDER_MAIN, 7781);
    player->ADD_GOSSIP_ITEM( 7, "[Arenas] ->"     , GOSSIP_SENDER_MAIN, 5575);
    player->ADD_GOSSIP_ITEM( 7, "[zones] ->"     , GOSSIP_SENDER_MAIN, 450);
    player->ADD_GOSSIP_ITEM( 7, "[Morph] ->"       , GOSSIP_SENDER_MAIN, 5579);
    player->ADD_GOSSIP_ITEM( 7, "[Reset / Player Tools] ->"       , GOSSIP_SENDER_MAIN, 5580);
    player->ADD_GOSSIP_ITEM( 7, "[Mr.Doctor] ->"       , GOSSIP_SENDER_MAIN, 7777);
    player->ADD_GOSSIP_ITEM( 7, "[Buffs] ->"       , GOSSIP_SENDER_MAIN, 7778);
    player->ADD_GOSSIP_ITEM( 7, "[Sounds] ->"       , GOSSIP_SENDER_MAIN, 401);
    player->ADD_GOSSIP_ITEM( 7, "[Mount Rental] ->"       , GOSSIP_SENDER_MAIN, 7779);
    player->ADD_GOSSIP_ITEM( 7, "[Trainers] ->"       , GOSSIP_SENDER_MAIN, 9000);
    player->ADD_GOSSIP_ITEM( 7, "[Reputation] ->"       , GOSSIP_SENDER_MAIN, 208); 
    player->ADD_GOSSIP_ITEM( 7, "[Gameshoot Aukcia] ->"       , GOSSIP_SENDER_MAIN, 2000); 
    player->ADD_GOSSIP_ITEM( 7, "[Repair] ->"       , GOSSIP_SENDER_MAIN, 550007);
/********** menu **********/                      
                  }

                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                return true;
                 }

                bool GiveReputation(Player *player, unsigned int repID, unsigned int repAMOUNT)
                {
                        player->GetReputationMgr().ModifyReputation(sFactionStore.LookupEntry(repID), repAMOUNT);
                        player->CastSpell(player,SPELL_REPUTATION,false);

                player->CLOSE_GOSSIP_MENU();
                return false;
                }

                bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
                {
                    if (player->isInCombat())
                    {
                                player->CLOSE_GOSSIP_MENU();
                                _creature->MonsterWhisper("Si v boji , prid pozdeji ! / You are in combat. Come back later!", player->GetGUID());
                                return true;
                   }
                    if (sender == GOSSIP_SENDER_MAIN)
                    {
                         player->PlayerTalkClass->ClearMenus();
                      switch(uiAction)
                         {

case 5576: //Cities
if ( player->GetTeam() == ALLIANCE ) //if alliance
                   {
    player->ADD_GOSSIP_ITEM( 5, "Stormwind"                    , GOSSIP_SENDER_MAIN, 1206);
    player->ADD_GOSSIP_ITEM( 5, "Ironforge"                    , GOSSIP_SENDER_MAIN, 1224);
    player->ADD_GOSSIP_ITEM( 5, "Darnassus"                    , GOSSIP_SENDER_MAIN, 1203);
    player->ADD_GOSSIP_ITEM( 5, "Exodar"                       , GOSSIP_SENDER_MAIN, 1216);
 }
                   else if ( player->GetTeam() == HORDE ) //if horde
                   {
    player->ADD_GOSSIP_ITEM( 5, "Orgrimmar"                    , GOSSIP_SENDER_MAIN, 1215);
    player->ADD_GOSSIP_ITEM( 5, "Thunder Bluff"                , GOSSIP_SENDER_MAIN, 1225);
    player->ADD_GOSSIP_ITEM( 5, "Undercity"                    , GOSSIP_SENDER_MAIN, 1213);
    player->ADD_GOSSIP_ITEM( 5, "Silvermoon"                   , GOSSIP_SENDER_MAIN, 1217);
                   }
    player->ADD_GOSSIP_ITEM( 5, "Shattrath City"               , GOSSIP_SENDER_MAIN, 4014);
    player->ADD_GOSSIP_ITEM( 5, "Dalaran"                      , GOSSIP_SENDER_MAIN, 5585);
    player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"          , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 5550: //Instances 1-60
  player->ADD_GOSSIP_ITEM( 5, "The Wailing Caverns"     , GOSSIP_SENDER_MAIN, 1249);
  player->ADD_GOSSIP_ITEM( 5, "Deadmines"               , GOSSIP_SENDER_MAIN, 1250);
  player->ADD_GOSSIP_ITEM( 5, "Shadowfang Keep"         , GOSSIP_SENDER_MAIN, 1251);
  player->ADD_GOSSIP_ITEM( 5, "Blackfathom Deeps"       , GOSSIP_SENDER_MAIN, 1252);
  player->ADD_GOSSIP_ITEM( 5, "Razorfen Kraul"          , GOSSIP_SENDER_MAIN, 1254);
  player->ADD_GOSSIP_ITEM( 5, "Razorfen Downs"          , GOSSIP_SENDER_MAIN, 1256);
  player->ADD_GOSSIP_ITEM( 5, "Scarlet Monastery"       , GOSSIP_SENDER_MAIN, 1257);
  player->ADD_GOSSIP_ITEM( 7, "[More] ->"               , GOSSIP_SENDER_MAIN, 5551);
  player->ADD_GOSSIP_ITEM( 5, "<- [Instances]"      , GOSSIP_SENDER_MAIN, 7781);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"          , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 5560: // Instances 60+
  player->ADD_GOSSIP_ITEM( 5, "Zul'Gurub"               , GOSSIP_SENDER_MAIN, 4000);
  player->ADD_GOSSIP_ITEM( 5, "Onyxia's Lair"           , GOSSIP_SENDER_MAIN, 4001);
  player->ADD_GOSSIP_ITEM( 5, "Molten Core"             , GOSSIP_SENDER_MAIN, 4002);
  player->ADD_GOSSIP_ITEM( 5, "Blackwing Lair"          , GOSSIP_SENDER_MAIN, 4003);
  player->ADD_GOSSIP_ITEM( 5, "Ruins of Ahn'Qiraj"      , GOSSIP_SENDER_MAIN, 4004);
  player->ADD_GOSSIP_ITEM( 5, "Temple of Ahn'Qiraj"     , GOSSIP_SENDER_MAIN, 4005);
  player->ADD_GOSSIP_ITEM( 5, "Naxxramas"               , GOSSIP_SENDER_MAIN, 4006);
  player->ADD_GOSSIP_ITEM( 5, "<- [Instances]"      , GOSSIP_SENDER_MAIN, 7781);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"          , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 5570: // Instances 70+
  player->ADD_GOSSIP_ITEM( 5, "Karazhan"                , GOSSIP_SENDER_MAIN, 4007);
  player->ADD_GOSSIP_ITEM( 5, "Gruul's Lair"            , GOSSIP_SENDER_MAIN, 4008);
  player->ADD_GOSSIP_ITEM( 5, "Hellfire Citadel"        , GOSSIP_SENDER_MAIN, 4009);
  player->ADD_GOSSIP_ITEM( 5, "Coilfang Reservoir"      , GOSSIP_SENDER_MAIN, 4010);
  player->ADD_GOSSIP_ITEM( 5, "Tempest Keep"            , GOSSIP_SENDER_MAIN, 4011);
  player->ADD_GOSSIP_ITEM( 5, "Caverns of Time"         , GOSSIP_SENDER_MAIN, 4012);
  player->ADD_GOSSIP_ITEM( 5, "Zul'Aman"                , GOSSIP_SENDER_MAIN, 4016);
  player->ADD_GOSSIP_ITEM( 5, "Black Temple"            , GOSSIP_SENDER_MAIN, 4013);
  player->ADD_GOSSIP_ITEM( 5, "<- [Instances]"      , GOSSIP_SENDER_MAIN, 7781);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"          , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 5571: // Instances 80+
  player->ADD_GOSSIP_ITEM( 5, "The Culling"             , GOSSIP_SENDER_MAIN, 4019);
  player->ADD_GOSSIP_ITEM( 5, "The Oculus"              , GOSSIP_SENDER_MAIN, 4020);
  player->ADD_GOSSIP_ITEM( 5, "Halls of Lightning"      , GOSSIP_SENDER_MAIN, 4021);
  player->ADD_GOSSIP_ITEM( 5, "Utgarde Pinnacle"        , GOSSIP_SENDER_MAIN, 4022);
  player->ADD_GOSSIP_ITEM( 5, "Halls of Stone"          , GOSSIP_SENDER_MAIN, 4023);
  player->ADD_GOSSIP_ITEM( 5, "Gundrak"                 , GOSSIP_SENDER_MAIN, 4024);
  player->ADD_GOSSIP_ITEM( 5, "The Violet Hold"         , GOSSIP_SENDER_MAIN, 4025);
  player->ADD_GOSSIP_ITEM( 5, "DrakTharon Keep"         , GOSSIP_SENDER_MAIN, 4026);
  player->ADD_GOSSIP_ITEM( 5, "Old Kingdom"             , GOSSIP_SENDER_MAIN, 4027);
  player->ADD_GOSSIP_ITEM( 5, "Azjol Nerub"             , GOSSIP_SENDER_MAIN, 4028);
  player->ADD_GOSSIP_ITEM( 5, "The Nexus"               , GOSSIP_SENDER_MAIN, 4029);
  player->ADD_GOSSIP_ITEM( 5, "Utgarde Keep"            , GOSSIP_SENDER_MAIN, 4030);
  player->ADD_GOSSIP_ITEM( 7, "[More Raids] ->"         , GOSSIP_SENDER_MAIN, 5553);
  player->ADD_GOSSIP_ITEM( 5, "<- [Instances]"      , GOSSIP_SENDER_MAIN, 7781);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"          , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 5551: //More Instances 1-60
  player->ADD_GOSSIP_ITEM( 5, "Uldaman"                   , GOSSIP_SENDER_MAIN, 1258);
  player->ADD_GOSSIP_ITEM( 5, "Zul'Farrak"                , GOSSIP_SENDER_MAIN, 1259);
  player->ADD_GOSSIP_ITEM( 5, "Maraudon"                  , GOSSIP_SENDER_MAIN, 1260);
  player->ADD_GOSSIP_ITEM( 5, "The Sunken Temple"         , GOSSIP_SENDER_MAIN, 1261);
  player->ADD_GOSSIP_ITEM( 5, "Blackrock Depths"          , GOSSIP_SENDER_MAIN, 1262);
  player->ADD_GOSSIP_ITEM( 5, "Dire Maul"                 , GOSSIP_SENDER_MAIN, 1263);
  player->ADD_GOSSIP_ITEM( 5, "Blackrock Spire"           , GOSSIP_SENDER_MAIN, 1264);
  player->ADD_GOSSIP_ITEM( 5, "Stratholme"                , GOSSIP_SENDER_MAIN, 1265);
  player->ADD_GOSSIP_ITEM( 5, "Scholomance"               , GOSSIP_SENDER_MAIN, 1266);
  player->ADD_GOSSIP_ITEM( 7, "<- [Back]"                 , GOSSIP_SENDER_MAIN, 5550);
  player->ADD_GOSSIP_ITEM( 5, "<- [Instances]"      , GOSSIP_SENDER_MAIN, 7781);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"            , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 5553: //Raids 80+
  player->ADD_GOSSIP_ITEM( 5, "Naxxaramas"                , GOSSIP_SENDER_MAIN, 4006);
  player->ADD_GOSSIP_ITEM( 5, "Eye of Eternity"           , GOSSIP_SENDER_MAIN, 4031);
  player->ADD_GOSSIP_ITEM( 5, "Obsidian Sanctum"          , GOSSIP_SENDER_MAIN, 4032);
  player->ADD_GOSSIP_ITEM( 5, "Vault of Archavon"         , GOSSIP_SENDER_MAIN, 4033);
  player->ADD_GOSSIP_ITEM( 5, "Gates of Ulduar"           , GOSSIP_SENDER_MAIN, 4034);
  player->ADD_GOSSIP_ITEM( 5, "The Frozen Halls"          , GOSSIP_SENDER_MAIN, 4036);
  player->ADD_GOSSIP_ITEM( 5, "Trial of the Champion"     , GOSSIP_SENDER_MAIN, 5586);
  player->ADD_GOSSIP_ITEM( 5, "Trial of the Crusader"     , GOSSIP_SENDER_MAIN, 5586);
  player->ADD_GOSSIP_ITEM( 5, "Icecrown Citadel"          , GOSSIP_SENDER_MAIN, 4037);
  player->ADD_GOSSIP_ITEM( 7, "<- [Back]"                 , GOSSIP_SENDER_MAIN, 5550);
  player->ADD_GOSSIP_ITEM( 5, "<- [Instances]"      , GOSSIP_SENDER_MAIN, 7781);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"            , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 5577: //Raids 85+
  player->ADD_GOSSIP_ITEM( 5, "Abyssal Maw: Throne of the Tides"                  , GOSSIP_SENDER_MAIN, 210);
  player->ADD_GOSSIP_ITEM( 5, "Blackrock Caverns"                                 , GOSSIP_SENDER_MAIN, 211);
  player->ADD_GOSSIP_ITEM( 5, "Grim Batol"                                        , GOSSIP_SENDER_MAIN, 213);
  player->ADD_GOSSIP_ITEM( 5, "Halls of Origination"                              , GOSSIP_SENDER_MAIN, 214);
  player->ADD_GOSSIP_ITEM( 5, "Lost City of the Tol'vir"                          , GOSSIP_SENDER_MAIN, 215);
  player->ADD_GOSSIP_ITEM( 5, "The Stonecore"                                     , GOSSIP_SENDER_MAIN, 216);
  player->ADD_GOSSIP_ITEM( 5, "The Vortex Pinnacle"                               , GOSSIP_SENDER_MAIN, 217);
  player->ADD_GOSSIP_ITEM( 5, "Baradin Hold"                                      , GOSSIP_SENDER_MAIN, 220);
  player->ADD_GOSSIP_ITEM( 5, "Blackwing Descent"                                 , GOSSIP_SENDER_MAIN, 221);
  player->ADD_GOSSIP_ITEM( 5, "The Bastion of Twilight"                           , GOSSIP_SENDER_MAIN, 222);
  player->ADD_GOSSIP_ITEM( 5, "<- [Instances]"      , GOSSIP_SENDER_MAIN, 7781);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"            , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;



case 5575: //Arenas
  player->ADD_GOSSIP_ITEM( 5, "Gurubashi Arena"               , GOSSIP_SENDER_MAIN, 4015);
  player->ADD_GOSSIP_ITEM( 5, "Circle of Blood Arena"         , GOSSIP_SENDER_MAIN, 5581);
  player->ADD_GOSSIP_ITEM( 5, "Ring of Trials"                , GOSSIP_SENDER_MAIN, 5582);
  player->ADD_GOSSIP_ITEM( 5, "The Maul"                      , GOSSIP_SENDER_MAIN, 5583);
  player->ADD_GOSSIP_ITEM( 5, "Wintergrasp"                   , GOSSIP_SENDER_MAIN, 5584);
  player->ADD_GOSSIP_ITEM( 5, "Argent Tournament"             , GOSSIP_SENDER_MAIN, 5586);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 5579://Morph
             player->ADD_GOSSIP_ITEM( 3, "Gnome"                    , GOSSIP_SENDER_MAIN, 551);
             player->ADD_GOSSIP_ITEM( 3, "Human"                    , GOSSIP_SENDER_MAIN, 552);
             player->ADD_GOSSIP_ITEM( 3, "Tauren"                   , GOSSIP_SENDER_MAIN, 553);
             player->ADD_GOSSIP_ITEM( 3, "Goblin"                   , GOSSIP_SENDER_MAIN, 554);
             player->ADD_GOSSIP_ITEM( 3, "Blood Elf"                , GOSSIP_SENDER_MAIN, 555);
             player->ADD_GOSSIP_ITEM( 3, "Broken"                   , GOSSIP_SENDER_MAIN, 556);
             player->ADD_GOSSIP_ITEM( 3, "Other"                   , GOSSIP_SENDER_MAIN, 557);
             player->ADD_GOSSIP_ITEM( 9, "Demorph"                  , GOSSIP_SENDER_MAIN, 558);
             player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 551://Gnome
                        player->ADD_GOSSIP_ITEM( 3, "Male"                      , GOSSIP_SENDER_MAIN, 559);
                        player->ADD_GOSSIP_ITEM( 3, "Female"                    , GOSSIP_SENDER_MAIN, 510);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

             case 552://Human
                        player->ADD_GOSSIP_ITEM( 3, "Male"                      , GOSSIP_SENDER_MAIN, 11);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

             case 553://Tauren
                        player->ADD_GOSSIP_ITEM( 3, "Male"                      , GOSSIP_SENDER_MAIN, 12);
                        player->ADD_GOSSIP_ITEM( 3, "Female"                    , GOSSIP_SENDER_MAIN, 13);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

             case 554://Goblin
                        player->ADD_GOSSIP_ITEM( 3, "Male"                      , GOSSIP_SENDER_MAIN, 14);
                        player->ADD_GOSSIP_ITEM( 3, "Female"                    , GOSSIP_SENDER_MAIN, 15);
                         player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

             case 555://Blood Elf
                        player->ADD_GOSSIP_ITEM( 3, "Male"                      , GOSSIP_SENDER_MAIN, 16);
                        player->ADD_GOSSIP_ITEM( 3, "Female"                    , GOSSIP_SENDER_MAIN, 17);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

             case 556://Broken
                        player->ADD_GOSSIP_ITEM( 3, "Male"                      , GOSSIP_SENDER_MAIN, 18);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

             case 557://Other
                        player->ADD_GOSSIP_ITEM( 3, "Champion"                         , GOSSIP_SENDER_MAIN, 20);
                        player->ADD_GOSSIP_ITEM( 3, "Pirate"                            , GOSSIP_SENDER_MAIN, 21);
                        player->ADD_GOSSIP_ITEM( 3, "Arthas"                            , GOSSIP_SENDER_MAIN, 22);
                        player->ADD_GOSSIP_ITEM( 3, "Ghost"                             , GOSSIP_SENDER_MAIN, 23);
                        player->ADD_GOSSIP_ITEM( 3, "Wolf"                              , GOSSIP_SENDER_MAIN, 24);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

              case 20://Champion
                       player->ADD_GOSSIP_ITEM( 3, "Darnassus"                        , GOSSIP_SENDER_MAIN, 25);
                       player->ADD_GOSSIP_ITEM( 3, "Gnomeregan"                       , GOSSIP_SENDER_MAIN, 26);
                       player->ADD_GOSSIP_ITEM( 3, "Ironforge"                        , GOSSIP_SENDER_MAIN, 27);
                       player->ADD_GOSSIP_ITEM( 3, "Orgrimmar"                        , GOSSIP_SENDER_MAIN, 28);
                       player->ADD_GOSSIP_ITEM( 3, "Silvermoon"                       , GOSSIP_SENDER_MAIN, 29);
                       player->ADD_GOSSIP_ITEM( 3, "Stormwind"                        , GOSSIP_SENDER_MAIN, 30);
                       player->ADD_GOSSIP_ITEM( 3, "Exodar"                           , GOSSIP_SENDER_MAIN, 31);
                       player->ADD_GOSSIP_ITEM( 3, "Undercity"                        , GOSSIP_SENDER_MAIN, 32);
                       player->ADD_GOSSIP_ITEM( 3, "Thunder Bluff"                    , GOSSIP_SENDER_MAIN, 33);
                       player->ADD_GOSSIP_ITEM( 3, "Ebon"                               , GOSSIP_SENDER_MAIN, 34);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

              case 21://Pirate
                        player->ADD_GOSSIP_ITEM( 3, "Male"                               , GOSSIP_SENDER_MAIN, 35);
                        player->ADD_GOSSIP_ITEM( 3, "Female"                            , GOSSIP_SENDER_MAIN, 36);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

              case 5580://Reset / Player Tools
                        player->ADD_GOSSIP_ITEM( 9, "Remove PvP Flags"                               , GOSSIP_SENDER_MAIN, 1009);
                        player->ADD_GOSSIP_ITEM( 9, "Unbind All Instances"                            , GOSSIP_SENDER_MAIN, 1010);
                        player->ADD_GOSSIP_ITEM( 9, "Remove All Auras"                               , GOSSIP_SENDER_MAIN, 1011);
                        player->ADD_GOSSIP_ITEM( 9, "Remove Res Sickness"                            , GOSSIP_SENDER_MAIN, 1012);
                        player->ADD_GOSSIP_ITEM( 9, "Zmena vzhledu - cost 1000g"                               , GOSSIP_SENDER_MAIN, 1013);
                        player->ADD_GOSSIP_ITEM( 9, "Faction Change - cost 1000g"                            , GOSSIP_SENDER_MAIN, 1014);
                        player->ADD_GOSSIP_ITEM( 9, "Race Change - cost 1000g"                            , GOSSIP_SENDER_MAIN, 1020);
                        player->ADD_GOSSIP_ITEM( 9, "Name Change - cost 1000g"                , GOSSIP_SENDER_MAIN, 1015);
                        player->ADD_GOSSIP_ITEM( 9, "Reset Talentpoints - cost 1g"                , GOSSIP_SENDER_MAIN, 1016);
                        player->ADD_GOSSIP_ITEM( 9, "Reset Spells - cost 1g"                , GOSSIP_SENDER_MAIN, 1021);
                        player->ADD_GOSSIP_ITEM( 9, "Advance all skills - cost 10g"                , GOSSIP_SENDER_MAIN, 1017);
                        player->ADD_GOSSIP_ITEM( 9, "Save Player to DB"                , GOSSIP_SENDER_MAIN, 1019);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552); 

                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

              case 7777://Mr.Doctor HELP !
                        player->ADD_GOSSIP_ITEM( 3, "Restore Health"                               , GOSSIP_SENDER_MAIN, 7001);
                        player->ADD_GOSSIP_ITEM( 3, "Restore Mana"                            , GOSSIP_SENDER_MAIN, 7002);
                        player->ADD_GOSSIP_ITEM( 3, "Remove Cooldown"                               , GOSSIP_SENDER_MAIN, 7003);
                        player->ADD_GOSSIP_ITEM( 3, "Remove Exhaustion"                            , GOSSIP_SENDER_MAIN, 7004);
                        player->ADD_GOSSIP_ITEM( 3, "Remove Sated"                               , GOSSIP_SENDER_MAIN, 7005);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

              case 7778://Buffs
                        player->ADD_GOSSIP_ITEM( 3, "Arcane Intellect"                               , GOSSIP_SENDER_MAIN, 9001);
                        player->ADD_GOSSIP_ITEM( 3, "Mark of the Wild"                            , GOSSIP_SENDER_MAIN, 9002);
                        player->ADD_GOSSIP_ITEM( 3, "Thorns"                               , GOSSIP_SENDER_MAIN, 9003);
                        player->ADD_GOSSIP_ITEM( 3, "Greater Blessing of Might"                               , GOSSIP_SENDER_MAIN, 9005);
                        player->ADD_GOSSIP_ITEM( 3, "Greater Blessing of Kings"                               , GOSSIP_SENDER_MAIN, 9006);
                        player->ADD_GOSSIP_ITEM( 3, "Greater Blessing of Wisdom"                            , GOSSIP_SENDER_MAIN, 9007);
                        player->ADD_GOSSIP_ITEM( 3, "Divine Spirit"                               , GOSSIP_SENDER_MAIN, 9008);
                        player->ADD_GOSSIP_ITEM( 3, "Shadow Protection"                            , GOSSIP_SENDER_MAIN, 9009);
                        player->ADD_GOSSIP_ITEM( 3, "Power Word: Fortitude"                               , GOSSIP_SENDER_MAIN, 9010);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

              case 7779://Mouth Giver
                        player->ADD_GOSSIP_ITEM( 3, "Kor'kron Annihilator"                               , GOSSIP_SENDER_MAIN, 8009);
                        player->ADD_GOSSIP_ITEM( 3, "Brown Riding Camel"                            , GOSSIP_SENDER_MAIN, 8010);
                        player->ADD_GOSSIP_ITEM( 3, "Drake of the South Wind"                               , GOSSIP_SENDER_MAIN, 8011);
                        player->ADD_GOSSIP_ITEM( 3, "Dark Phoenix"                               , GOSSIP_SENDER_MAIN, 8012);
                        player->ADD_GOSSIP_ITEM( 3, "Sea Turtle"                               , GOSSIP_SENDER_MAIN, 8013);
                        player->ADD_GOSSIP_ITEM( 3, "Abyssal Seahorse"                               , GOSSIP_SENDER_MAIN, 8014);
                        player->ADD_GOSSIP_ITEM( 9, "Dismount"                               , GOSSIP_SENDER_MAIN, 8015);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

              case 7781://Instances
                        player->ADD_GOSSIP_ITEM( 7, "[Instances Lvl 1-60] ->"      , GOSSIP_SENDER_MAIN, 5550);
                        player->ADD_GOSSIP_ITEM( 7, "[Instances Lvl 60+] ->"       , GOSSIP_SENDER_MAIN, 5560);
                        player->ADD_GOSSIP_ITEM( 7, "[Instances Lvl 70+] ->"       , GOSSIP_SENDER_MAIN, 5570);
                        player->ADD_GOSSIP_ITEM( 7, "[Instances Lvl 80+] ->"       , GOSSIP_SENDER_MAIN, 5571);
                        player->ADD_GOSSIP_ITEM( 7, "[Instances Lvl 85+] ->"       , GOSSIP_SENDER_MAIN, 5577);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;


              case 7782://Exp. maps 
                        player->ADD_GOSSIP_ITEM( 7, "Exp. maps Lvl 1-10"      , GOSSIP_SENDER_MAIN, 7783);
                        player->ADD_GOSSIP_ITEM( 7, "Exp. maps Lvl 10-20"       , GOSSIP_SENDER_MAIN, 7784);
                        player->ADD_GOSSIP_ITEM( 7, "Exp. maps Lvl 20-30"       , GOSSIP_SENDER_MAIN, 7785);
                        player->ADD_GOSSIP_ITEM( 7, "Exp. maps Lvl 30-40"       , GOSSIP_SENDER_MAIN, 7786);
                        player->ADD_GOSSIP_ITEM( 7, "Exp. maps Lvl 40-50"       , GOSSIP_SENDER_MAIN, 7787);
                        player->ADD_GOSSIP_ITEM( 7, "Exp. maps Lvl 50-60"      , GOSSIP_SENDER_MAIN, 7788);
                        player->ADD_GOSSIP_ITEM( 7, "Exp. maps Lvl 60-70"       , GOSSIP_SENDER_MAIN, 7789);
                        player->ADD_GOSSIP_ITEM( 7, "Exp. maps Lvl 70-80"       , GOSSIP_SENDER_MAIN, 7790);
                        player->ADD_GOSSIP_ITEM( 7, "Exp. maps Lvl 80-85"       , GOSSIP_SENDER_MAIN, 7791);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;



              case 7783://Exp. maps Lvl 1-10 
                        player->ADD_GOSSIP_ITEM( 5, "The Maelstrom"       , GOSSIP_SENDER_MAIN, 8164);
                        player->ADD_GOSSIP_ITEM( 5, "The Lost Isles"       , GOSSIP_SENDER_MAIN, 8165);
                        player->ADD_GOSSIP_ITEM( 5, "Tirisfal Glades Lvl 1-10"      , GOSSIP_SENDER_MAIN, 8103);
                        player->ADD_GOSSIP_ITEM( 5, "Elwynn Forest Lvl 1-10"      , GOSSIP_SENDER_MAIN, 8104);
                        player->ADD_GOSSIP_ITEM( 5, "Eversong Woods Lvl 1-10"      , GOSSIP_SENDER_MAIN, 8105);
                        player->ADD_GOSSIP_ITEM( 5, "Dun Morogh Lvl 1-10"      , GOSSIP_SENDER_MAIN, 8106);
                        player->ADD_GOSSIP_ITEM( 5, "Azuremyst Isle Lvl 1-10"      , GOSSIP_SENDER_MAIN, 8107);
                        player->ADD_GOSSIP_ITEM( 5, "Durotar Lvl 1-10"      , GOSSIP_SENDER_MAIN, 8108);
                        player->ADD_GOSSIP_ITEM( 5, "Mulgore Lvl 1-10"      , GOSSIP_SENDER_MAIN, 8109);
                        player->ADD_GOSSIP_ITEM( 5, "Teldrassil Lvl 1-10"      , GOSSIP_SENDER_MAIN, 8110);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Exp. maps]"                , GOSSIP_SENDER_MAIN, 7782);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;




              case 7784://Exp. maps Lvl 10-20
                        player->ADD_GOSSIP_ITEM( 5, "Westfall Lvl 10-15"       , GOSSIP_SENDER_MAIN, 8111);
                        player->ADD_GOSSIP_ITEM( 5, "Moonglade Lvl 10-15"       , GOSSIP_SENDER_MAIN, 8112);
                        player->ADD_GOSSIP_ITEM( 5, "Ghostlands Lvl 10-20"       , GOSSIP_SENDER_MAIN, 8113);
                        player->ADD_GOSSIP_ITEM( 5, "Loch Modan Lvl 10-20"       , GOSSIP_SENDER_MAIN, 8114);
                        player->ADD_GOSSIP_ITEM( 5, "Azshara Lvl 10-20"       , GOSSIP_SENDER_MAIN, 8115);
                        player->ADD_GOSSIP_ITEM( 5, "Silverpine Forest Lvl 10-20"       , GOSSIP_SENDER_MAIN, 8016);
                        player->ADD_GOSSIP_ITEM( 5, "Bloodmyst Isle Lvl 10-20"       , GOSSIP_SENDER_MAIN, 8017);
                        player->ADD_GOSSIP_ITEM( 5, "Darkshore Lvl 10-20"       , GOSSIP_SENDER_MAIN, 8018);
                        player->ADD_GOSSIP_ITEM( 5, "Northern Barrens Lvl 10-20"       , GOSSIP_SENDER_MAIN, 8019);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Exp. maps]"                , GOSSIP_SENDER_MAIN, 7782);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;




              case 7785://Exp. maps Lvl 20-30
                        player->ADD_GOSSIP_ITEM( 5, "Wetlands Lvl 20-25"       , GOSSIP_SENDER_MAIN, 8020);
                        player->ADD_GOSSIP_ITEM( 5, "Hillsbrad Foothills Lvl 20-25"       , GOSSIP_SENDER_MAIN, 8021);
                        player->ADD_GOSSIP_ITEM( 5, "Duskwood Lvl 20-25"       , GOSSIP_SENDER_MAIN, 8022);
                        player->ADD_GOSSIP_ITEM( 5, "Ashenvale Lvl 20-25"       , GOSSIP_SENDER_MAIN, 8023);
                        player->ADD_GOSSIP_ITEM( 5, "Arathi Highlands Lvl 25-30"       , GOSSIP_SENDER_MAIN, 8024);
                        player->ADD_GOSSIP_ITEM( 5, "Stonetalon Mountains Lvl 25-30"       , GOSSIP_SENDER_MAIN, 8025);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Exp. maps]"                , GOSSIP_SENDER_MAIN, 7782);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;




              case 7786://Exp. maps Lvl 30-40 
                        player->ADD_GOSSIP_ITEM( 5, "Desolace Lvl 30-40"       , GOSSIP_SENDER_MAIN, 8027);
                        player->ADD_GOSSIP_ITEM( 5, "Southern Barrens Lvl 30-35"       , GOSSIP_SENDER_MAIN, 8028);
                        player->ADD_GOSSIP_ITEM( 5, "The Cape of Stranglethorn Lvl 30-35"       , GOSSIP_SENDER_MAIN, 8029);
                        player->ADD_GOSSIP_ITEM( 5, "The Hinterlands Lvl 30-35"       , GOSSIP_SENDER_MAIN, 8030);
                        player->ADD_GOSSIP_ITEM( 5, "Stranglethorn Vale Lvl 30-50"       , GOSSIP_SENDER_MAIN, 8031);
                        player->ADD_GOSSIP_ITEM( 5, "Dustwallow Marsh Lvl 30-40"       , GOSSIP_SENDER_MAIN, 8032);
                        player->ADD_GOSSIP_ITEM( 5, "Feralas Lvl 30-40"       , GOSSIP_SENDER_MAIN, 8033);
                        player->ADD_GOSSIP_ITEM( 5, "Western Plaguelands Lvl 30-40"       , GOSSIP_SENDER_MAIN, 8034);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Exp. maps]"                , GOSSIP_SENDER_MAIN, 7782);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;




              case 7787://Exp. maps Lvl 40-50 
                        player->ADD_GOSSIP_ITEM( 5, "Thousand Needles Lvl 40-45"       , GOSSIP_SENDER_MAIN, 8035);
                        player->ADD_GOSSIP_ITEM( 5, "Eastern Plaguelands Lvl 40-45"       , GOSSIP_SENDER_MAIN, 8036);
                        player->ADD_GOSSIP_ITEM( 5, "Badlands Lvl 44-48"       , GOSSIP_SENDER_MAIN, 8037);
                        player->ADD_GOSSIP_ITEM( 5, "Felwood Lvl 45-50"       , GOSSIP_SENDER_MAIN, 8038);
                        player->ADD_GOSSIP_ITEM( 5, "Tanaris Lvl 45-50"       , GOSSIP_SENDER_MAIN, 8039);
                        player->ADD_GOSSIP_ITEM( 5, "Searing Gorge Lvl 47-51"       , GOSSIP_SENDER_MAIN, 8040);
                        player->ADD_GOSSIP_ITEM( 5, "Burning Steppes Lvl 49-52"       , GOSSIP_SENDER_MAIN, 8041);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Exp. maps]"                , GOSSIP_SENDER_MAIN, 7782);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;




              case 7788://Exp. maps Lvl 50-60
                        player->ADD_GOSSIP_ITEM( 5, "Blackrock Mountains Lvl 50-60"      , GOSSIP_SENDER_MAIN, 8042);
                        player->ADD_GOSSIP_ITEM( 5, "Deadwind Pass Lvl 50-60"      , GOSSIP_SENDER_MAIN, 8043);
                        player->ADD_GOSSIP_ITEM( 5, "Un'Goro Crater Lvl 50-55"      , GOSSIP_SENDER_MAIN, 8044);
                        player->ADD_GOSSIP_ITEM( 5, "Winterspring Lvl 50-55"      , GOSSIP_SENDER_MAIN, 8045);
                        player->ADD_GOSSIP_ITEM( 5, "Swamp of Sorrows Lvl 51-55"      , GOSSIP_SENDER_MAIN, 8046);
                        player->ADD_GOSSIP_ITEM( 5, "Silithus Lvl 55-60"      , GOSSIP_SENDER_MAIN, 8047);
                        player->ADD_GOSSIP_ITEM( 5, "Blasted Lands Lvl 50-60"      , GOSSIP_SENDER_MAIN, 8048);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Exp. maps]"                , GOSSIP_SENDER_MAIN, 7782);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;




              case 7789://Exp. maps Lvl 60-70
                        player->ADD_GOSSIP_ITEM( 5, "Zangarmarsh Lvl 60-63"       , GOSSIP_SENDER_MAIN, 8050);
                        player->ADD_GOSSIP_ITEM( 5, "Terokkar Forest Lvl 62-70"       , GOSSIP_SENDER_MAIN, 8051);
                        player->ADD_GOSSIP_ITEM( 5, "Nagrand Lvl 64-70"       , GOSSIP_SENDER_MAIN, 8052);
                        player->ADD_GOSSIP_ITEM( 5, "Blade's Edge Mountains Lvl 65-70"       , GOSSIP_SENDER_MAIN, 8053);
                        player->ADD_GOSSIP_ITEM( 5, "Netherstorm 66-70"       , GOSSIP_SENDER_MAIN, 8054);
                        player->ADD_GOSSIP_ITEM( 5, "Shadowmoon Valley Lvl 67-70"       , GOSSIP_SENDER_MAIN, 8055);
                        player->ADD_GOSSIP_ITEM( 5, "Howling Fjord 68-72"       , GOSSIP_SENDER_MAIN, 8056);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Exp. maps]"                , GOSSIP_SENDER_MAIN, 7782);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;




              case 7790://Exp. maps Lvl 70-80
                        player->ADD_GOSSIP_ITEM( 5, "Borean Tundra Lvl 70-72"       , GOSSIP_SENDER_MAIN, 8057);
                        player->ADD_GOSSIP_ITEM( 5, "Dragonblight Lvl 71-80"       , GOSSIP_SENDER_MAIN, 8058);
                        player->ADD_GOSSIP_ITEM( 5, "Grizzly Hills Lvl 73-75"       , GOSSIP_SENDER_MAIN, 8059);
                        player->ADD_GOSSIP_ITEM( 5, "Zul'Drak Lvl 73-77"       , GOSSIP_SENDER_MAIN, 8060);
                        player->ADD_GOSSIP_ITEM( 5, "Sholazar Basin Lvl 75-80"       , GOSSIP_SENDER_MAIN, 8061);
                        player->ADD_GOSSIP_ITEM( 5, "Hrothgar's Landing Lvl 70-80"       , GOSSIP_SENDER_MAIN, 8062);
                        player->ADD_GOSSIP_ITEM( 5, "Icecrown Lvl 70-80"       , GOSSIP_SENDER_MAIN, 8063);
                        player->ADD_GOSSIP_ITEM( 5, "The Storm Peaks Lvl 70-80"       , GOSSIP_SENDER_MAIN, 8064);
                        player->ADD_GOSSIP_ITEM( 5, "Wintergrasp Lvl 80"       , GOSSIP_SENDER_MAIN, 8065);
                        player->ADD_GOSSIP_ITEM( 5, "Crystalsong Forest Lvl 80"       , GOSSIP_SENDER_MAIN, 8066);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Exp. maps]"                , GOSSIP_SENDER_MAIN, 7782);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;



              case 7791://Exp. maps Lvl 80-85 
                        player->ADD_GOSSIP_ITEM( 5, "Mount Hyjal Lvl 80-82"       , GOSSIP_SENDER_MAIN, 8067);
                        player->ADD_GOSSIP_ITEM( 5, "Vashj'ir Lvl 80-82"       , GOSSIP_SENDER_MAIN, 8068);
                        player->ADD_GOSSIP_ITEM( 5, "Uldum Lvl 83-84"       , GOSSIP_SENDER_MAIN, 8069);
                        player->ADD_GOSSIP_ITEM( 5, "Deepholm Lvl 82-83"       , GOSSIP_SENDER_MAIN, 8072);
                        player->ADD_GOSSIP_ITEM( 5, "Twilight Highlands Lvl 84-85"       , GOSSIP_SENDER_MAIN, 8070);
                        player->ADD_GOSSIP_ITEM( 5, "Tol Barad Peninsula Lvl 85"       , GOSSIP_SENDER_MAIN, 8073);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Exp. maps]"                , GOSSIP_SENDER_MAIN, 7782);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

                case  208://Reputation
                        player->ADD_GOSSIP_ITEM( 8, "Wrath of the Lich King"             , GOSSIP_SENDER_MAIN, 209);
                        player->ADD_GOSSIP_ITEM( 8, "Cataclysm"                           , GOSSIP_SENDER_MAIN, 99);



                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;



                case 209: //reputace Wrath of the Lich King
                            if ( player->GetTeam() == ALLIANCE ) //if alliance
                                {
                                        player->ADD_GOSSIP_ITEM( 3, "Alliance Vanguard"           , GOSSIP_SENDER_MAIN, 100);
                                        player->ADD_GOSSIP_ITEM( 3, "Explorers' League"           , GOSSIP_SENDER_MAIN, 101);
                                        player->ADD_GOSSIP_ITEM( 3, "The Frostborn"               , GOSSIP_SENDER_MAIN, 102);
                                        player->ADD_GOSSIP_ITEM( 3, "The Silver Covenant"         , GOSSIP_SENDER_MAIN, 103);
                                        player->ADD_GOSSIP_ITEM( 3, "Valiance Expedition"         , GOSSIP_SENDER_MAIN, 104);
                                }
                                else if ( player->GetTeam() == HORDE ) //if horde
                                {
                                        player->ADD_GOSSIP_ITEM( 3, "Horde Expedition"            , GOSSIP_SENDER_MAIN, 105);
                                        player->ADD_GOSSIP_ITEM( 3, "The Hand of Vengeance"       , GOSSIP_SENDER_MAIN, 106);
                                        player->ADD_GOSSIP_ITEM( 3, "The Sunreavers"              , GOSSIP_SENDER_MAIN, 107);
                                        player->ADD_GOSSIP_ITEM( 3, "The Taunka"                  , GOSSIP_SENDER_MAIN, 108);
                                        player->ADD_GOSSIP_ITEM( 3, "Warsong Offensive"           , GOSSIP_SENDER_MAIN, 109);
                                }
                                player->ADD_GOSSIP_ITEM( 3, "Argent Crusade"                      , GOSSIP_SENDER_MAIN, 110);
                                player->ADD_GOSSIP_ITEM( 3, "Frenzyheart Tribe"                   , GOSSIP_SENDER_MAIN, 111);
                                player->ADD_GOSSIP_ITEM( 3, "Kirin Tor"                           , GOSSIP_SENDER_MAIN, 112);
                                player->ADD_GOSSIP_ITEM( 3, "Knights of the Ebon Blade"           , GOSSIP_SENDER_MAIN, 113);
                                player->ADD_GOSSIP_ITEM( 3, "The Kalu'ak"                         , GOSSIP_SENDER_MAIN, 114);
                                player->ADD_GOSSIP_ITEM( 3, "The Oracles"                         , GOSSIP_SENDER_MAIN, 115);
                                player->ADD_GOSSIP_ITEM( 3, "The Sons of Hodir"                   , GOSSIP_SENDER_MAIN, 116);
                                player->ADD_GOSSIP_ITEM( 3, "The Wyrmrest Accord"                 , GOSSIP_SENDER_MAIN, 117);
                                player->ADD_GOSSIP_ITEM( 3, "The Ashen Verdict"                   , GOSSIP_SENDER_MAIN, 118);
                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                      , GOSSIP_SENDER_MAIN, 5552);



                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                        break;



                         case 99: //reputace Cataclysm
                            if ( player->GetTeam() == ALLIANCE ) //if alliance
                                {
                                        player->ADD_GOSSIP_ITEM( 3, "Baradin's Wardens"           , GOSSIP_SENDER_MAIN, 98);
                                        player->ADD_GOSSIP_ITEM( 3, "Wildhammer Clan"             , GOSSIP_SENDER_MAIN, 97);
                                }
                                else if ( player->GetTeam() == HORDE ) //if horde
                                {
                                        player->ADD_GOSSIP_ITEM( 3, "Dragonmaw Clan"              , GOSSIP_SENDER_MAIN, 202);
                                        player->ADD_GOSSIP_ITEM( 3, "Hellscream's Reach"          , GOSSIP_SENDER_MAIN, 203);
                                }
                                player->ADD_GOSSIP_ITEM( 3, "Guardians of Hyjal"                  , GOSSIP_SENDER_MAIN, 204);
                                player->ADD_GOSSIP_ITEM( 3, "Ramkahen"                            , GOSSIP_SENDER_MAIN, 205);
                                player->ADD_GOSSIP_ITEM( 3, "The Earthen Ring"                    , GOSSIP_SENDER_MAIN, 206);
                                player->ADD_GOSSIP_ITEM( 3, "Therazane"                           , GOSSIP_SENDER_MAIN, 207);
                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                      , GOSSIP_SENDER_MAIN, 5552);



                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                               break;

        case 2000://Auction
                        player->ADD_GOSSIP_ITEM( 5, "Buy lvl"       , GOSSIP_SENDER_MAIN, 2001);
                        player->ADD_GOSSIP_ITEM( 5, "Buy currencies"       , GOSSIP_SENDER_MAIN, 2002);
                        player->ADD_GOSSIP_ITEM( 5, "Buy Vanishing Powder , Dust of.."       , GOSSIP_SENDER_MAIN, 2003);
                        player->ADD_GOSSIP_ITEM( 5, "Mullty Gameshoot packs"                    , GOSSIP_SENDER_MAIN, 2004);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);
                                 

                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

        case 2001://Auction
                        player->ADD_GOSSIP_ITEM( 5, "Buy 85 lvl - cost 200000g"       , GOSSIP_SENDER_MAIN, 2015);
                        player->ADD_GOSSIP_ITEM( 5, "Buy 50 lvl - cost 50000g"       , GOSSIP_SENDER_MAIN, 2013);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

        case 2002://Auction
                        player->ADD_GOSSIP_ITEM( 5, "2x Illustrious Jewelcrafter's Token - cost 20g"       , GOSSIP_SENDER_MAIN, 2034);
                        player->ADD_GOSSIP_ITEM( 5, "2x Valor Points - cost 20g"       , GOSSIP_SENDER_MAIN, 2035);
                        player->ADD_GOSSIP_ITEM( 5, "20x Valor Points - cost 200g"       , GOSSIP_SENDER_MAIN, 2036);
                        player->ADD_GOSSIP_ITEM( 5, "200x Valor Points - cost 2000g"       , GOSSIP_SENDER_MAIN, 2037);
                        player->ADD_GOSSIP_ITEM( 5, "1000x Valor Points - cost 10000g"       , GOSSIP_SENDER_MAIN, 2038);
                        player->ADD_GOSSIP_ITEM( 5, "2x Justice Points - cost 2g"       , GOSSIP_SENDER_MAIN, 2039);
                        player->ADD_GOSSIP_ITEM( 5, "20x Justice Points - cost 20g"       , GOSSIP_SENDER_MAIN, 2040);
                        player->ADD_GOSSIP_ITEM( 5, "200x Justice Points - cost 200g"       , GOSSIP_SENDER_MAIN, 2041);
                        player->ADD_GOSSIP_ITEM( 5, "2000x Justice Points - cost 2000g"       , GOSSIP_SENDER_MAIN, 2042);
                        player->ADD_GOSSIP_ITEM( 5, "2x Conquest Points - cost 20g"       , GOSSIP_SENDER_MAIN, 2043);
                        player->ADD_GOSSIP_ITEM( 5, "20x Conquest Points - cost 200g"       , GOSSIP_SENDER_MAIN, 2044);
                        player->ADD_GOSSIP_ITEM( 5, "200x Conquest Points - cost 2000g"       , GOSSIP_SENDER_MAIN, 2045);
                        player->ADD_GOSSIP_ITEM( 5, "1000x Conquest Points - cost 10000g"       , GOSSIP_SENDER_MAIN, 2046);
                        player->ADD_GOSSIP_ITEM( 7, "[Next site] ->"                , GOSSIP_SENDER_MAIN, 2058);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

        case 2058://Auction
                        player->ADD_GOSSIP_ITEM( 5, "2x Honor Points - cost 2g"       , GOSSIP_SENDER_MAIN, 2047);
                        player->ADD_GOSSIP_ITEM( 5, "20x Honor Points - cost 20g"       , GOSSIP_SENDER_MAIN, 2048);
                        player->ADD_GOSSIP_ITEM( 5, "200x Honor Points - cost 200g"       , GOSSIP_SENDER_MAIN, 2049);
                        player->ADD_GOSSIP_ITEM( 5, "2000x Honor Points - cost 2000g"       , GOSSIP_SENDER_MAIN, 2050);                        
                        player->ADD_GOSSIP_ITEM( 5, "20x Tol Barad Commendation - cost 20g"       , GOSSIP_SENDER_MAIN, 2051);
                        player->ADD_GOSSIP_ITEM( 5, "200x Tol Barad Commendation - cost 200g"       , GOSSIP_SENDER_MAIN, 2052);
                        player->ADD_GOSSIP_ITEM( 5, "2x Champion's Seal - cost 20g"       , GOSSIP_SENDER_MAIN, 2053);
                        player->ADD_GOSSIP_ITEM( 5, "2x Chef's Award - cost 20g"       , GOSSIP_SENDER_MAIN, 2054);
                        player->ADD_GOSSIP_ITEM( 5, "2x Dalaran Cooking Award - cost 20g"       , GOSSIP_SENDER_MAIN, 2055);
                        player->ADD_GOSSIP_ITEM( 5, "2x Dalaran Jewelcrafter's Token - cost 20g"       , GOSSIP_SENDER_MAIN, 2056);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);



                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

        case 2060://Auction
                        player->ADD_GOSSIP_ITEM( 5, "2x Draenei Archaeology Fragment - cost 200g"       , GOSSIP_SENDER_MAIN, 2014);
                        player->ADD_GOSSIP_ITEM( 5, "2x Dwarf Archaeology Fragment - cost 200g"       , GOSSIP_SENDER_MAIN, 2016);
                        player->ADD_GOSSIP_ITEM( 5, "2x Fossil Archaeology Fragment - cost 200g"       , GOSSIP_SENDER_MAIN, 2017);
                        player->ADD_GOSSIP_ITEM( 5, "2x Nerubian Archaeology Fragment - cost 200g"       , GOSSIP_SENDER_MAIN, 2018);
                        player->ADD_GOSSIP_ITEM( 5, "2x Night Elf Archaeology Fragment - cost 200g"       , GOSSIP_SENDER_MAIN, 2019);
                        player->ADD_GOSSIP_ITEM( 5, "2x Orc Archaeology Fragment - cost 200g"       , GOSSIP_SENDER_MAIN, 2020);
                        player->ADD_GOSSIP_ITEM( 5, "2x Tol'vir Archaeology Fragment - cost 200g"       , GOSSIP_SENDER_MAIN, 2021);
                        player->ADD_GOSSIP_ITEM( 5, "2x Troll Archaeology Fragment - cost 200g"       , GOSSIP_SENDER_MAIN, 2022);                        
                        player->ADD_GOSSIP_ITEM( 5, "2x Vrykul Archaeology Fragment - cost 200g"       , GOSSIP_SENDER_MAIN, 2023);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

        case 2003://Auction
                        player->ADD_GOSSIP_ITEM( 5, "1x Vanishing Powder - cost 1g"                    , GOSSIP_SENDER_MAIN, 451);                        
                        player->ADD_GOSSIP_ITEM( 5, "1x Dust of Disappearance - cost 1g"                    , GOSSIP_SENDER_MAIN, 452); 
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

        case 2004://Auction

                        player->ADD_GOSSIP_ITEM( 5, "Archaeology pack - cost 100000g"                    , GOSSIP_SENDER_MAIN, 2100); 
                        player->ADD_GOSSIP_ITEM( 5, "For new players pack - cost 10g "                    , GOSSIP_SENDER_MAIN, 2101);
                        player->ADD_GOSSIP_ITEM( 5, "Mounts pack - cost 10g "                    , GOSSIP_SENDER_MAIN, 2102);
                        player->ADD_GOSSIP_ITEM( 5, "Companions pack - cost 10g "                    , GOSSIP_SENDER_MAIN, 2105);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;



        case 401://sounds
                        player->ADD_GOSSIP_ITEM( 5, "Prehraj menu 1"       , GOSSIP_SENDER_MAIN, 399);
                        player->ADD_GOSSIP_ITEM( 5, "Prehraj menu 2"       , GOSSIP_SENDER_MAIN, 398);
                        player->ADD_GOSSIP_ITEM( 5, "Prehraj menu 3"       , GOSSIP_SENDER_MAIN, 397);
                        player->ADD_GOSSIP_ITEM( 5, "Prehraj menu 4"       , GOSSIP_SENDER_MAIN, 396);
                        player->ADD_GOSSIP_ITEM( 5, "Prehraj menu 5"       , GOSSIP_SENDER_MAIN, 395);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

case 399:

player->ADD_GOSSIP_ITEM(1,"Play Illidan 1", GOSSIP_SENDER_MAIN, 51);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 2", GOSSIP_SENDER_MAIN, 52);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 3", GOSSIP_SENDER_MAIN, 53);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 4", GOSSIP_SENDER_MAIN, 54);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 5", GOSSIP_SENDER_MAIN, 55);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 6", GOSSIP_SENDER_MAIN, 536);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 7", GOSSIP_SENDER_MAIN, 37);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 8", GOSSIP_SENDER_MAIN, 38);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 9", GOSSIP_SENDER_MAIN, 39);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 10", GOSSIP_SENDER_MAIN, 310);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 11", GOSSIP_SENDER_MAIN, 311);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 12", GOSSIP_SENDER_MAIN, 312);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 13", GOSSIP_SENDER_MAIN, 313);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 14", GOSSIP_SENDER_MAIN, 314);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 15", GOSSIP_SENDER_MAIN, 315);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

case 398:

player->ADD_GOSSIP_ITEM(1,"Play Illidan 16", GOSSIP_SENDER_MAIN, 316);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 17", GOSSIP_SENDER_MAIN, 317);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 18", GOSSIP_SENDER_MAIN, 318);
player->ADD_GOSSIP_ITEM(1,"Play Illidan 19", GOSSIP_SENDER_MAIN, 319);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

case 397:
player->ADD_GOSSIP_ITEM(1,"Play Kil Jaeden 1", GOSSIP_SENDER_MAIN, 320);
player->ADD_GOSSIP_ITEM(1,"Play Kil Jaeden 2", GOSSIP_SENDER_MAIN, 321);
player->ADD_GOSSIP_ITEM(1,"Play Kil Jaeden 3", GOSSIP_SENDER_MAIN, 322);
player->ADD_GOSSIP_ITEM(1,"Play Kil Jaeden 4", GOSSIP_SENDER_MAIN, 323);
player->ADD_GOSSIP_ITEM(1,"Play Kil Jaeden 5", GOSSIP_SENDER_MAIN, 324);
player->ADD_GOSSIP_ITEM(1,"Play Kil Jaeden 6", GOSSIP_SENDER_MAIN, 325);
player->ADD_GOSSIP_ITEM(1,"Play Kil Jaeden 7", GOSSIP_SENDER_MAIN, 326);
player->ADD_GOSSIP_ITEM(1,"Play Kil Jaeden 8", GOSSIP_SENDER_MAIN, 327);
player->ADD_GOSSIP_ITEM(1,"Play Aveena 1", GOSSIP_SENDER_MAIN, 328);
player->ADD_GOSSIP_ITEM(1,"Play Aveena 2", GOSSIP_SENDER_MAIN, 329);
player->ADD_GOSSIP_ITEM(1,"Play Aveena 3", GOSSIP_SENDER_MAIN, 330);
player->ADD_GOSSIP_ITEM(1,"Play Kalecgos", GOSSIP_SENDER_MAIN, 331);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;


case 396:
player->ADD_GOSSIP_ITEM(1,"Play MURLOC", GOSSIP_SENDER_MAIN, 332);
player->ADD_GOSSIP_ITEM(1,"Play Shade of Akama", GOSSIP_SENDER_MAIN, 333);
player->ADD_GOSSIP_ITEM(1,"Play Night Elf Female Joke", GOSSIP_SENDER_MAIN, 334);
player->ADD_GOSSIP_ITEM(1,"Play Pissed Orc Peon", GOSSIP_SENDER_MAIN, 335);
player->ADD_GOSSIP_ITEM(1,"Play Thrall Greeting", GOSSIP_SENDER_MAIN, 336);
player->ADD_GOSSIP_ITEM(1,"Play Headless Horseman Laugh", GOSSIP_SENDER_MAIN, 337);
player->ADD_GOSSIP_ITEM(1,"Play Headless Horseman Failed When all of you is dead", GOSSIP_SENDER_MAIN, 338);
player->ADD_GOSSIP_ITEM(1,"Play Headless Horseman He Dies!", GOSSIP_SENDER_MAIN, 339);
player->ADD_GOSSIP_ITEM(1,"Play Mr. Smith Deadmines 1", GOSSIP_SENDER_MAIN, 340);
player->ADD_GOSSIP_ITEM(1,"Play Mr. Smith Deadmines 2", GOSSIP_SENDER_MAIN, 341);
player->ADD_GOSSIP_ITEM(1,"Play Mr. Smith Deadmines 3", GOSSIP_SENDER_MAIN, 342);
player->ADD_GOSSIP_ITEM(1,"Play Mr. Smith Deadmines 4", GOSSIP_SENDER_MAIN, 343);
player->ADD_GOSSIP_ITEM(1,"Play Thrall - Aggroing", GOSSIP_SENDER_MAIN, 344);
player->ADD_GOSSIP_ITEM(1,"Play Thrall - Greeting", GOSSIP_SENDER_MAIN, 345);
player->ADD_GOSSIP_ITEM(1,"Play Jaina Proudmoore", GOSSIP_SENDER_MAIN, 346); 
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 395:
player->ADD_GOSSIP_ITEM(1,"Play Summon Succubus", GOSSIP_SENDER_MAIN, 347);
player->ADD_GOSSIP_ITEM(1,"Play Succubus Buttslap whip", GOSSIP_SENDER_MAIN, 348);
player->ADD_GOSSIP_ITEM(1,"Play Horde Talk", GOSSIP_SENDER_MAIN, 349);
player->ADD_GOSSIP_ITEM(1,"Play Baby Murloc", GOSSIP_SENDER_MAIN, 350);
player->ADD_GOSSIP_ITEM(1,"Play Whissle", GOSSIP_SENDER_MAIN, 351);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;

case 450:
    player->ADD_GOSSIP_ITEM( 5, "[DK zone] ->"     , GOSSIP_SENDER_MAIN, 8525);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;
case 8525:
    player->ADD_GOSSIP_ITEM( 5, "Horne Patro"                    , GOSSIP_SENDER_MAIN, 8526);
    player->ADD_GOSSIP_ITEM( 5, "Dolne Patro"                    , GOSSIP_SENDER_MAIN, 8527);
    player->ADD_GOSSIP_ITEM( 5, "Suteren"      , GOSSIP_SENDER_MAIN, 8528);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;
case 9000:
    player->ADD_GOSSIP_ITEM( 7, "[Learn my Mounts spells - cost 100g] ->"       , GOSSIP_SENDER_MAIN, 7780);
    player->ADD_GOSSIP_ITEM( 7, "[Class Trainer] ->"       , GOSSIP_SENDER_MAIN, 7800);
    player->ADD_GOSSIP_ITEM( 7, "[Races Trainer] ->"       , GOSSIP_SENDER_MAIN, 9500);
    player->ADD_GOSSIP_ITEM( 7, "[Talents Trainer] ->"       , GOSSIP_SENDER_MAIN, 9513);
    player->ADD_GOSSIP_ITEM( 7, "[Reset Talentpoints - cost 1g] ->"       , GOSSIP_SENDER_MAIN, 7801);
    player->ADD_GOSSIP_ITEM( 7, "[Professions] ->"       , GOSSIP_SENDER_MAIN, 9620);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;

case 9620:
                        player->ADD_GOSSIP_ITEM( 5, "Learn my Mining spells - cost 10g"       , GOSSIP_SENDER_MAIN, 9601);
                        player->ADD_GOSSIP_ITEM( 5, "Learn my Herbalism spells - cost 10g"       , GOSSIP_SENDER_MAIN, 9602);
                        player->ADD_GOSSIP_ITEM( 5, "Learn my Skinning spells - cost 10g"       , GOSSIP_SENDER_MAIN, 9603);
                        player->ADD_GOSSIP_ITEM( 5, "Learn my Archaeology spells - cost 10g"       , GOSSIP_SENDER_MAIN, 9604);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 9514:
              	player->ADD_GOSSIP_ITEM( 5, "Learn my Primary Second Talent Spec spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9013);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 7800:
              	player->ADD_GOSSIP_ITEM( 5, "Learn my death_knight spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9011);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my druid spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9012);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my hunter spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9013);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my mage spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9014);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my paladin spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9015);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my priest spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9016);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my rogue spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9017);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my shaman spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9018);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my warlock spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9019);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my warrior spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9020);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;

case 9500:
              	player->ADD_GOSSIP_ITEM( 5, "Learn my Worgen spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9501);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my Undead spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9502);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my Troll spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9503);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my Tauren spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9504);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my Orc spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9505);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my Night Elf spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9506);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my Human spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9507);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my Goblin spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9508);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my Gnome spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9509);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my Dwarf spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9510);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my Draenei spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9511);
              	player->ADD_GOSSIP_ITEM( 5, "Learn my Blood Elf spells - cost 10g "                    , GOSSIP_SENDER_MAIN, 9512);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;

case 8500:

    player->ADD_GOSSIP_ITEM( 5, "Proffesions"                    , GOSSIP_SENDER_MAIN, 8503);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;

case 100000000:
    player->ADD_GOSSIP_ITEM( 7, "Pravydla"                    , GOSSIP_SENDER_MAIN, 50800);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 5552: //Back To Main Menu
   {
    player->ADD_GOSSIP_ITEM( 7, "[Info] ->"                    , GOSSIP_SENDER_MAIN, 100000000);
    player->ADD_GOSSIP_ITEM( 7, "[Shoop] ->"                    , GOSSIP_SENDER_MAIN, 8500);
    player->ADD_GOSSIP_ITEM( 7, "[Cities] ->"                    , GOSSIP_SENDER_MAIN, 5576);
    player->ADD_GOSSIP_ITEM( 7, "[Exp. maps] ->"                    , GOSSIP_SENDER_MAIN, 7782);
    player->ADD_GOSSIP_ITEM( 7, "[Instances] ->"      , GOSSIP_SENDER_MAIN, 7781);
    player->ADD_GOSSIP_ITEM( 7, "[Arenas] ->"     , GOSSIP_SENDER_MAIN, 5575);
    player->ADD_GOSSIP_ITEM( 7, "[zones] ->"     , GOSSIP_SENDER_MAIN, 450);
    player->ADD_GOSSIP_ITEM( 7, "[Morph] ->"       , GOSSIP_SENDER_MAIN, 5579);
    player->ADD_GOSSIP_ITEM( 7, "[Reset / Player Tools] ->"       , GOSSIP_SENDER_MAIN, 5580);
    player->ADD_GOSSIP_ITEM( 7, "[Mr.Doctor] ->"       , GOSSIP_SENDER_MAIN, 7777);
    player->ADD_GOSSIP_ITEM( 7, "[Buffs] ->"       , GOSSIP_SENDER_MAIN, 7778);
    player->ADD_GOSSIP_ITEM( 7, "[Sounds] ->"       , GOSSIP_SENDER_MAIN, 401);
    player->ADD_GOSSIP_ITEM( 7, "[Mount Rental] ->"       , GOSSIP_SENDER_MAIN, 7779);
    player->ADD_GOSSIP_ITEM( 7, "[Trainers] ->"       , GOSSIP_SENDER_MAIN, 9000);
    player->ADD_GOSSIP_ITEM( 7, "[Reputation] ->"       , GOSSIP_SENDER_MAIN, 208); 
    player->ADD_GOSSIP_ITEM( 7, "[Gameshoot Aukcia] ->"       , GOSSIP_SENDER_MAIN, 2000); 
    player->ADD_GOSSIP_ITEM( 7, "[Repair] ->"       , GOSSIP_SENDER_MAIN, 550007);  
                        }


                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 1203: // Teleport to Darnassus
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, 9947.52f, 2482.73f, 1316.21f, 0.0f);
break;

// Teleport to Stormwind
case 1206:
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -8835.877930f, 620.708130f, 95.153793f, 0.0f);
break;

// Teleport to Undercity
case 1213:
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, 1819.71f, 238.79f, 60.5321f, 0.0f);
break;

// Teleport to Orgrimmar
case 1215:
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, 1571.649170f, -4398.892578f, 15.967260, 0.0f);
break;

// Teleport to Exodar
case 1216:
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, -4073.03f, -12020.4f, -1.47f, 0.0f);
break;

// Teleport to Silvermoon
case 1217:
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, 9338.74f, -7277.27f, 13.7895f, 0.0f);
break;

// Teleport to Ironforge
case 1224:
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -4924.07f, -951.95f, 501.55f, 5.40f);
break;

// Teleport to Thunder Bluff
case 1225:
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -1290.0f, 147.033997f, 129.682007f, 4.919000f);
break;

case 4000:// Teleport to Zul'Gurub
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -11916.7f, -1212.82f, 92.2868f, 4.6095f);
break;

case 4001:// Teleport to Onyxia's Lair
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -4707.44f, -3726.82f, 54.6723f, 3.8f);
break;

case 4002:// Teleport to Molten Core
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(230, 1121.451172f, -454.316772f, -101.329536f, 3.5f);
break;

case 4003:// Teleport to Blackwing Lair
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(469, -7665.55f, -1102.49f, 400.679f, 0.0f);
break;

case 4004:// Ruins of Ahn'Qiraj
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -8409.032227f, 1498.830933f, 27.361542f, 2.497567f);
break;

case 4005:// Temple of Ahn'Qiraj
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -8245.837891f, 1983.736206f, 129.071686f, 0.936195f);
break;

case 4006:// Naxxramas
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, 3125.184814f, -3748.024658f, 136.049393f, 0.0f);
break;

case 4007:// Karazhan
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -11118.8f, -2010.84f, 47.0807f, 0.0f);
break;

case 4008:// Gruul's Lair
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, 3539.007568f, 5082.357910f, 1.691071f, 0.0f);
break;

case 4009:// Hellfire Citadel
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, -305.816223f, 3056.401611f, -2.473183f, 2.01f);
break;

case 4010:// Coilfang Reservoir
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, 517.288025f, 6976.279785f, 32.007198f, 0.0f);
break;

case 4011:// Tempest Keep
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, 3089.579346f, 1399.046509f, 187.653458f, 4.794070f);
break;

case 4012:// Caverns of Time
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -8173.66f, -4746.36f, 33.8423f, 4.93989f);
break;

case 4016:// Zul'Aman
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, 6846.95f, -7954.5f, 170.028f, 4.61501f);
break;

case 4013:// Black Temple
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, -3610.719482f, 324.987579f, 37.400028f, 3.282981f);
break;

case 4014:// Shattrath City
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, -1850.209961f, 5435.821777f, -10.961435f, 3.403913f);
break;

case 4015:// Gurubashi
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -13261.3f, 168.294f, 35.0792f, 1.00688f);
break;

case 4017:// Razor Hill
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, 315.721f, -4743.4f, 10.4867f, 0.0f);
break;

case 4018:// Goldshire
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -9464.0f, 62.0f, 56.0f, 0.0f);
break;

case 4019:// Culling
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -8648.95f,-4387.76f,-207.95f,3.5049f);
break;

case 4020:// Oculus
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 3780.6f,6955.63f,104.89f,0.3676f);
break;

case 4021:// Halls of Lightning
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 9105.72f,-1319.86f,1058.39f,5.6502f);
break;

case 4022:// Utgarde Pinnacle
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 1256.96f,-4852.94f,215.55f,3.447f);
break;

case 4023:// Halls of Stone
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 8922.45f,-1012.96f,1039.59f,1.563f);
break;

case 4024:// Gundrak
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 6936.08f,-4436.54f,450.51f,0.7698f);
break;

case 4025:// Violet Hold
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 5705.19f,517.96f,649.78f,4.0307f);
break;

case 4026:// DrakTharon Keep
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 4774.32f,-2036.68f,229.38f,1.567f);
break;

case 4027:// Old Kingdom
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 3700.87f,2152.58f,36.044f,3.5956f);
break;

case 4028:// Azjol Nerub
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 3700.87f,2152.58f,36.044f,3.5956f);
break;

case 4029:// Nexus
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 3780.6f,6955.63f,104.89f,0.3676f);
break;

case 4030:// Utgarde Keep
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 1206.94f,-4868.05f,41.249f,0.2804f);
break;

case 4031:// Eye of Eternity
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 3860.62f,6989.15f,152.042f,5.74598f);
break;

case 4032:// Obsidian Sanctum
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 3483.54f,265.605f,-120.144f,3.23879f);
break;

case 4033:// Vault of Archavon
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 5406.72f,2816.98f,418.675f,1.06982f);
break;

case 4034:// Gates of Ulduar
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 9019.79f,-1111.28f,1165.28f,6.26597f);
break;

case 4036:// The Frozen Halls
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 5693.37f,2167.4f,798.125f,4.63304f);
break;

case 4037:// Icecrown Citadel
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 5867.040527f, 2108.114258f, 635.996704f, 0.0f);
break;

case 1249://teleport player to the Wailing Caverns
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -722.53f,-2226.30f,16.94f,2.71f);
break;

case 1250://teleport player to the Deadmines
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -11212.04f,1658.58f,25.67f,1.45f);
break;

case 1251://teleport player to Shadowfang Keep
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -254.47f,1524.68f,76.89f,1.56f);
break;

case 1252://teleport player to Blackfathom Deeps
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, 4254.58f,664.74f,-29.04f,1.97f);
break;

case 1254://teleport player to Razorfen Kraul
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -4484.04f,-1739.40f,86.47f,1.23f);
break;

case 1256://teleport player to Razorfen Downs
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -4645.08f,-2470.85f,85.53f,4.39f);
break;

case 1257://teleport player to the Scarlet Monastery
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, 2843.89f,-693.74f,139.32f,5.11f);
break;

case 1258://teleport player to Uldaman
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -6119.70f,-2957.30f,204.11f,0.03f);
break;

case 1259://teleport player to Zul'Farrak
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -6839.39f,-2911.03f,8.87f,0.41f);
break;


case 1260://teleport player to Maraudon
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -1433.33f,2955.34f,96.21f,4.82f);
break;

case 1261://teleport player to the Sunken Temple
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -10346.92f,-3851.90f,-43.41f,6.09f);
break;

case 1262://teleport player to Blackrock Depths
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -7301.03f,-913.19f,165.37f,0.08f);
break;

case 1263://teleport player to Dire Maul
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -3982.47f,1127.79f,161.02f,0.05f);
break;

case 1264://teleport player to Blackrock Spire
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -7535.43f,-1212.04f,285.45f,5.29f);
break;

case 1265://teleport player to Stratholme
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, 3263.54f,-3379.46f,143.59f,0.00f);
break;

case 1266://teleport player to Scholomance
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, 1219.01f,-2604.66f,85.61f,0.50f);
break;
case 5581://teleport player to Circle of Blood
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, 2839.44f,5930.17f,11.1002f,3.16284f);
break;

case 5582://teleport player to Ring of Trials
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, -1999.94f,6581.71f,11.32f,2.3f);
break;

case 5583://teleport player to The Maul
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -3761.49f,1133.43f,132.083f,4.57259f);
break;

case 5584://teleport player to Wintergrasp
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 4984.89f,2864.16f,386.797f,2.56767f);
break;

case 5585://teleport player to Dalaran
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 5804.585f,624.726f,647.780f,1.820647f);
break;

case 5586://teleport player to Argent Tournament
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 8385.92f,793.193f,547.293f,1.820647f);
break;

                         /********** Cataclysm - Dungeons **********/

                         case 210: //Abyssal Maw: Throne of the Tides
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(643, -588.956055f, 809.103149f, 244.809586f, 0.0f);
                               break;

                               break;
                         case 211: //Blackrock Caverns
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(0, -7572.09f, -1314.98f, 245.53f, 0.0f);
                               break;
                         case 212: //Firelands nejde pot vubec tam
                                player->CLOSE_GOSSIP_MENU();
                               break;

                         case 213: //Grim Batol
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(0, -4068.742432f, -3453.749756f, 279.000641f, 0.0f);
                               break;

                         case 214: //Halls of Origination
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(1, -10205.358398f, -1838.916748f, 20.128099f, 0.0f);
                               break;

                         case 215: //Lost City of the Tol'vir
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(1, -10662.812500f, -1302.016236f, 15.354200f, 0.0f);
                               break;

                         case 216: //The Stonecore
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(646, 1026.44f, 641.42f, 156.67f, 0.0f);
                               break;

                         case 217: //The Vortex Pinnacle
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(1, -11511.55f, -2308.23f, 608.39f, 0.0f);
                               break;

                         /********** Cataclysm - Raids **********/

                         case 220: //Baradin Hold
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(732, -1259.285767f, 1049.690186f, 106.995003f, 0.0f);
                               break;

                         case 221: //Blackwing Descent
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(0, -7533.914062f, -1209.072388f, 477.728455f, 0.0f);
                               break;

                         case 222: //The Bastion of Twilight
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(0, -4880.834961f, -4258.035645f, 827.763489f, 0.0f);
                               break;

                         case 223: //Throne of the Four Winds
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(1, -11354.738281f, 57.456497f, 723.884705f, 0.0f);
                               break;

 /********** Morph **********/

case 559://Gnome - Male
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(20580);
          player->CastSpell(player,61456,false); 
      break;

      case 10://Gnome - Female
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(20581);
          player->CastSpell(player,61456,false); 
      break;

      case 11://Human - Male
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(19723);
          player->CastSpell(player,61456,false); 
      break;

      case 12://Tauren - Male
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(20585);
          player->CastSpell(player,61456,false); 
      break;

      case 13://Tauren - Female
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(20584);
          player->CastSpell(player,61456,false); 
      break;

      case 14://Goblin - Male
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(20581);
          player->CastSpell(player,61456,false); 
      break;

      case 15://Goblin - Female
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(20583);
          player->CastSpell(player,61456,false); 
      break;

      case 16://Blood Elf - Male
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(20578);
          player->CastSpell(player,61456,false); 
      break;

      case 17://Blood Elf - Female
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(20579);
          player->CastSpell(player,61456,false); 
      break;

      case 18://Broken - Male
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(21105);
          player->CastSpell(player,61456,false); 
      break;

      case 22://Arthas
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(22234);
          player->CastSpell(player,61456,false); 
      break;

      case 23://Ghost
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(14560);
          player->CastSpell(player,61456,false); 
      break;

      case 24://Wolf
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(741);
          player->CastSpell(player,61456,false); 
      break;

      case 35://Pirate - Male
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(4620);
          player->CastSpell(player,61456,false); 
      break;

      case 36://Pirate - Female
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(4619);
          player->CastSpell(player,61456,false); 
      break;

      case 25://Darnassus
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(29007);
          player->CastSpell(player,61456,false); 
      break;

      case 26://Gnomeregan
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(28859);
          player->CastSpell(player,61456,false); 
      break;

      case 27://Ironforge
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(28860);
          player->CastSpell(player,61456,false); 
      break;

      case 28://Orgrimmar
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(29053);
          player->CastSpell(player,61456,false); 
      break;

      case 29://Silvermoon
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(28862);
          player->CastSpell(player,61456,false); 
      break;

      case 30://Stormwind
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(28863);
          player->CastSpell(player,61456,false); 
      break;

      case 31://Exodar
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(30810);
          player->CastSpell(player,61456,false); 
      break;

      case 32://Undercity
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(28858);
          player->CastSpell(player,61456,false); 
      break;

      case 33://Thunder Bluff
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(28597);
          player->CastSpell(player,61456,false); 
      break;

      case 34://Ebon
          player->CLOSE_GOSSIP_MENU();
          player->SetDisplayId(30862);
          player->CastSpell(player,61456,false); 
      break;

       case 558://Demorph
          player->CLOSE_GOSSIP_MENU();
          player->DeMorph();
          player->CastSpell(player,61456,false); 
       break;
/********** Reset - / - Player - Tools **********/

case 1009://Remove PvP Flags
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->CastSpell(player, 20762, true),
          player->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_CONTESTED_PVP),
          player->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_PVP),
          player->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP),
          player->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_PVP_TIMER),
          player->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP);
          player->CastSpell(player,61456,false); 
          player->SaveToDB();
      break;


case 1010://Unbind All Instances
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("All Instance Locks Reset.", player->GetGUID());
          for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
          {
          Player::BoundInstancesMap &binds = player->GetBoundInstances(Difficulty(i));
          for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
          {
          if(itr->first != player->GetMapId())
          {
          player->UnbindInstance(itr, Difficulty(i));

                    }
                    else
                        ++itr;
                }
            }
          player->CastSpell(player,61456,false); 
          player->SaveToDB();
      break;


case 1011://Remove All Auras
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->RemoveAllAuras();
          player->CastSpell(player,61456,false); 
          player->SaveToDB();
      break;


case 1012://Remove Res Sickness
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          //if (player->HasAura(15007,0))
          {
          player->RemoveAurasDueToSpell(15007,0);
          }
          player->CastSpell(player,61456,false); 
          player->SaveToDB();
      break;


case 1013://Character Customize
          player->CLOSE_GOSSIP_MENU();
          if (player->GetMoney() < 10000000)
           {
            _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
             }
            else
          {
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
                               player->ModifyMoney(-10000000);
          player->CastSpell(player,61456,false);
          _creature->MonsterSay("Dakujem za obchod , novy vzhled si nastavis pri relogu :) / Thank for bussines :)" ,0 , player->GetGUID());
          } 
          player->SaveToDB();
          break;


case 1014://Faction Change
          player->CLOSE_GOSSIP_MENU();
          if (player->GetMoney() < 10000000)
           {
            _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
             }
            else
          {
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->SetAtLoginFlag(AT_LOGIN_RESET_TALENTS);
          player->SetAtLoginFlag(AT_LOGIN_RESET_SPELLS);
          player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
                               player->ModifyMoney(-10000000);
          player->CastSpell(player,61456,false); 
          _creature->MonsterSay("Dakujem za obchod , novou rasu u druhe frakce si zvolis pri relogu :) / Thank for bussines :)" ,0 , player->GetGUID());
          } 
          player->SaveToDB();
          break;

case 1020://Race Change
          player->CLOSE_GOSSIP_MENU();
          if (player->GetMoney() < 10000000)
           {
            _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
             }
            else
          {
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->SetAtLoginFlag(AT_LOGIN_RESET_TALENTS);
          player->SetAtLoginFlag(AT_LOGIN_RESET_SPELLS);
          player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
                               player->ModifyMoney(-10000000);
          player->CastSpell(player,61456,false); 
          _creature->MonsterSay("Dakujem za obchod , novou rasu si zvolis pri relogu. :) / Thank for bussines :)" ,0 , player->GetGUID());
          } 
          player->SaveToDB();
          break;


case 1015://Name Change
          player->CLOSE_GOSSIP_MENU();
          if (player->GetMoney() < 10000000)
           {
            _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
             }
            else
          {
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->SetAtLoginFlag(AT_LOGIN_RENAME);
                               player->ModifyMoney(-10000000);
          player->CastSpell(player,61456,false);
          _creature->MonsterSay("Dakujem za obchod , nove jmeno si nastavis po relogu :) / Thank for bussines :)" ,0 , player->GetGUID());
          } 
          player->SaveToDB();
          break;


case 1016://Reset Talentpoints
          player->CLOSE_GOSSIP_MENU();
if (player->GetMoney() < 10000)
           {
            _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
             }
            else
          {
          player->SetAtLoginFlag(AT_LOGIN_RESET_TALENTS);
          _creature->MonsterWhisper("Dakujem za obchod , po relogu se ti resetnou talenty", player->GetGUID());
          player->ModifyMoney(-10000);
          player->CastSpell(player,61456,false);
          } 
          player->SaveToDB();
     break;


case 1017://Advance all skills
          player->CLOSE_GOSSIP_MENU();
          if (player->GetMoney() < 100000)
           {
            _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
             }
            else
          {
          player->UpdateSkillsToMaxSkillsForLevel();
          player->ModifyMoney(-100000);
          player->CastSpell(player,61456,false); 
          _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
          } 
          player->SaveToDB();
          break;


case 1019://Save Player to DB
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo , si uloženy:)", player->GetGUID());
          player->SaveToDB();
          player->CastSpell(player,61456,false);         
    break;

case 1021://Reset spells
          player->CLOSE_GOSSIP_MENU();
if (player->GetMoney() < 10000)
           {
            _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
             }
            else
          {
          player->SetAtLoginFlag(AT_LOGIN_RESET_TALENTS);
          player->SetAtLoginFlag(AT_LOGIN_RESET_SPELLS);
          _creature->MonsterWhisper("Dakujem za obchod , po relogu se ti resetnou spelly", player->GetGUID());
          player->CastSpell(player,61456,false);
player->ModifyMoney(-10000);
                    } 
          player->SaveToDB();
     break;


 /********** Mr - . - Doctor - HELP - ! **********/


case 7001://Restore Health
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->SetHealth(player->GetMaxHealth());
          player->CastSpell(player,61456,false);
     break;


case 7002://Restore Mana
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
          player->CastSpell(player,61456,false);
     break;


case 7003://Remove Cooldown
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->RemoveAllSpellCooldown();
          player->CastSpell(player,75459,false);
     break;


case 7004://Remove Exhaustion
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->RemoveAurasDueToSpell(57723);
          player->CastSpell(player,61456,false);
     break;


case 7005://Remove Sated
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->RemoveAurasDueToSpell(57724);
          player->CastSpell(player,61456,false);          
     break;
 /********** Buffs **********/


            case 9001: // Buff me Arcane Intellect
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,36880,true);
                player->CastSpell(player,61456,false); 
                break;

            case 9002: // Buff me Mark of the Wild
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,1126,true);
                player->CastSpell(player,61456,false); 
                break;

            case 9003: // Buff me Thorns
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,467,true);
                player->CastSpell(player,61456,false); 
                break;

            case 9005: // Buff me Greater Blessing of Might
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,19740,true);
                player->CastSpell(player,61456,false); 
                break;

            case 9006: // Buff me Greater Blessing of Kings
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,20217,true);
                player->CastSpell(player,61456,false); 
                break;

            case 9007: // Buff me Greater Blessing of Wisdom
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,56521,true);
                player->CastSpell(player,61456,false); 
                break;

            case 9008: // Buff me Divine Spirit
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,39234,true);
                player->CastSpell(player,61456,false); 
                break;

            case 9009: // Buff me Power Word: Fortitude
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,21562,true);
                player->CastSpell(player,61456,false); 
                break;

            case 9010: // Buff me Shadow Protection
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,27683,true);
                player->CastSpell(player,61456,false); 
                break;
/********** Mouth - Pujcovna - / - Rental **********/


            case 8009: // Kor'kron Annihilator
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,93644,true);
                player->CastSpell(player,61456,false);
                break;

            case 8010: // Brown Riding Camel
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,88748,true);
                player->CastSpell(player,61456,false);
                break;
  
            case 8011: // Drake of the South Wind
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,88744,true);
                player->CastSpell(player,61456,false);
                break;
            
            case 8012: // Dark Phoenix
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,88990,true);
                player->CastSpell(player,61456,false);
                break;
            
            case 8013: // Sea Turtle
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,64731,true);
                player->CastSpell(player,61456,false);
                break;

            
            case 8014: // Abyssal Seahorse
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->CastSpell(player,75207,true);
                player->CastSpell(player,61456,false);
                break;

            
            case 8015: // Dismount
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->Unmount();
                player->RemoveAurasByType(SPELL_AURA_MOUNTED);
                player->CastSpell(player,61456,false); 
                break;


/********** Class Trainer **********/

           case 9011: // death_knight spelly
              	player->CLOSE_GOSSIP_MENU();
if(player->getClass() != CLASS_DEATH_KNIGHT) 
                     {
                            _creature->MonsterWhisper("You are not death knight!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {
if (player->GetMoney() < 100000)
                                               {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                     player->SaveToDB();
                     player->UpdateSkillsToMaxSkillsForLevel();
                     player->CastSpell(player,61456,false);
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
// dodatek
                               player->ModifyMoney(-100000);
              	_creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        }
                                }
          player->SaveToDB();
              	break;

case 9012: // druid spelly
              	player->CLOSE_GOSSIP_MENU();
if(player->getClass() != CLASS_DRUID) 
                     {
                            _creature->MonsterWhisper("You are not druid!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {

if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                     player->SaveToDB();
                     player->UpdateSkillsToMaxSkillsForLevel();
                     player->CastSpell(player,61456,false);
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
                               player->ModifyMoney(-100000);
              	 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        }
                                     }
          player->SaveToDB();
              	break;

case 9013: // hunter spelly
              	player->CLOSE_GOSSIP_MENU();
 if(player->getClass() != CLASS_HUNTER) 
                     {
                            _creature->MonsterWhisper("You are not hunter!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {

if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                     player->SaveToDB();
                     player->UpdateSkillsToMaxSkillsForLevel();
                     player->CastSpell(player,61456,false);
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
              	
                               player->ModifyMoney(-100000);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        }
                                     }
          player->SaveToDB();
break;

case 9014: // mage spelly
              	player->CLOSE_GOSSIP_MENU();
if(player->getClass() != CLASS_MAGE) 
                     {
                            _creature->MonsterWhisper("You are not mage!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {

if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                     player->SaveToDB();
                     player->UpdateSkillsToMaxSkillsForLevel();
                     player->CastSpell(player,61456,false);
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
                               player->ModifyMoney(-100000);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        }
                                     }
          player->SaveToDB();
              	break;

case 9015: // paladin spelly
              	player->CLOSE_GOSSIP_MENU();
if(player->getClass() != CLASS_PALADIN) 
                     {
                            _creature->MonsterWhisper("You are not paladin!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {

if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                     player->SaveToDB();
                     player->UpdateSkillsToMaxSkillsForLevel();
                     player->CastSpell(player,61456,false);
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
                               player->ModifyMoney(-100000);
              	_creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        }
                                     }
          player->SaveToDB();
              	break;


case 9016: // priest spelly
              	player->CLOSE_GOSSIP_MENU();
if(player->getClass() != CLASS_PRIEST) 
                     {
                            _creature->MonsterWhisper("You are not priest!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {

if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                     player->SaveToDB();
                     player->UpdateSkillsToMaxSkillsForLevel();
                     player->CastSpell(player,61456,false);
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
                               player->ModifyMoney(-100000);
              	 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        }
                                     }
          player->SaveToDB();
              	break;

case 9017: // rogue  spelly
              	player->CLOSE_GOSSIP_MENU();
if(player->getClass() != CLASS_ROGUE) 
                     {
                            _creature->MonsterWhisper("You are not rogue!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {

if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                     player->SaveToDB();
                     player->UpdateSkillsToMaxSkillsForLevel();
                     player->CastSpell(player,61456,false);
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
                               player->ModifyMoney(-100000);
              	 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        }
                                     }
          player->SaveToDB();
              	break;

case 9018: // shaman spelly
              	player->CLOSE_GOSSIP_MENU();
if(player->getClass() != CLASS_SHAMAN) 
                     {
                            _creature->MonsterWhisper("You are not shaman!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {

if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                     player->SaveToDB();
                     player->UpdateSkillsToMaxSkillsForLevel();
                     player->CastSpell(player,61456,false);
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
              	                               player->ModifyMoney(-100000);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        }
                                     }
          player->SaveToDB();
              	break;


case 9019: // warlock spelly
              	player->CLOSE_GOSSIP_MENU();
if(player->getClass() != CLASS_WARLOCK) 
                     {
                            _creature->MonsterWhisper("You are not warlock!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {

if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                     player->SaveToDB();
                     player->UpdateSkillsToMaxSkillsForLevel();
                     player->CastSpell(player,61456,false);
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
              	                               player->ModifyMoney(-100000);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        }
                                     }
          player->SaveToDB();
              	break;


case 9020: // warrior spelly
              	player->CLOSE_GOSSIP_MENU();
if(player->getClass() != CLASS_WARRIOR) 
                     {
                            _creature->MonsterWhisper("You are not warrior!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {

if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                     player->SaveToDB();
                     player->UpdateSkillsToMaxSkillsForLevel();
                     player->CastSpell(player,61456,false);
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
              	                               player->ModifyMoney(-100000);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        }
                                     }
          player->SaveToDB();
              	break;

/********** Reset Talentpoints **********/

           case 7801: //Reset Talentpoints
          player->CLOSE_GOSSIP_MENU();
if (player->GetMoney() < 10000)
           {
            _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
             }
            else
          {

          player->SetAtLoginFlag(AT_LOGIN_RESET_TALENTS);
          _creature->MonsterWhisper("Dakujem za obchod , po relogu se ti resetnou talenty", player->GetGUID());
          player->CastSpell(player,61456,false);
player->ModifyMoney(-10000);
          player->CastSpell(player,61456,false);
          _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
          } 
     break;
      
/********** Mount Trener **********/

            case 7780: // Mount Trener
                player->CLOSE_GOSSIP_MENU();
if (player->GetMoney() < 1000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(33388,false);
                player->learnSpell(34091,false);
                player->learnSpell(54197,false);
                player->learnSpell(34090,false);
                player->learnSpell(90267,false);
                player->learnSpell(33391,false);
                player->learnSpell(90265,false);
                               player->ModifyMoney(-1000000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
          player->SaveToDB();
                break;

/********** RACE Trener**********/


case 9501: // RACE_WORGEN
               player->CLOSE_GOSSIP_MENU();
if(player->getRace() != RACE_WORGEN) 
                     {
                            _creature->MonsterWhisper("You are not worgen!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(68976,false);
                player->learnSpell(68992,false);
                player->learnSpell(94293,false);
                player->learnSpell(68978,false);
                player->learnSpell(87840,false);
                player->learnSpell(68996,false);
                player->learnSpell(68975,false);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                           }
          player->SaveToDB();
                break;



case 9502: // RACE_UNDEAD_PLAYER
               player->CLOSE_GOSSIP_MENU();
if(player->getRace() != RACE_UNDEAD_PLAYER) 
                     {
                            _creature->MonsterWhisper("You are not undead!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(20577,false);
                player->learnSpell(20579,false);
                player->learnSpell(5227,false);
                player->learnSpell(7744,false);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                           }
          player->SaveToDB();
                break;



case 9503: // RACE_TROLL
               player->CLOSE_GOSSIP_MENU();
if(player->getRace() != RACE_TROLL) 
                     {
                            _creature->MonsterWhisper("You are not troll!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(20557,false);
                player->learnSpell(26297,false);
                player->learnSpell(26290,false);
                player->learnSpell(58943,false);
                player->learnSpell(20555,false);
                player->learnSpell(20558,false);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                           }
          player->SaveToDB();
                break;



case 9504: // RACE_TAUREN
               player->CLOSE_GOSSIP_MENU();
if(player->getRace() != RACE_TAUREN) 
                     {
                            _creature->MonsterWhisper("You are not tauren!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(20594,false);
                player->learnSpell(20551,false);
                player->learnSpell(20550,false);
                player->learnSpell(20552,false);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                           }
          player->SaveToDB();
                break;



case 9505: // RACE_ORC
               player->CLOSE_GOSSIP_MENU();
if(player->getRace() != RACE_ORC) 
                     {
                            _creature->MonsterWhisper("You are not orc!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(20574,false);
                player->learnSpell(20572,false);
                player->learnSpell(33702,false);
                player->learnSpell(33697,false);
                player->learnSpell(54562,false);
                player->learnSpell(65222,false);
                player->learnSpell(20575,false);
                player->learnSpell(20573,false);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                           }
          player->SaveToDB();
                break;



case 9506: // RACE_NIGHTELF
               player->CLOSE_GOSSIP_MENU();
if(player->getRace() != RACE_NIGHTELF) 
                     {
                            _creature->MonsterWhisper("You are not nightelf!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(20583,false);
                player->learnSpell(20582,false);
                player->learnSpell(58984,false);
                player->learnSpell(20585,false);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                           }
          player->SaveToDB();
                break;


case 9507: // RACE_HUMAN
               player->CLOSE_GOSSIP_MENU();
if(player->getRace() != RACE_HUMAN) 
                     {
                            _creature->MonsterWhisper("You are not human!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(20599,false);
                player->learnSpell(59752,false);
                player->learnSpell(20864,false);
                player->learnSpell(20597,false);
                player->learnSpell(20598,false);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                           }
          player->SaveToDB();
                break;


case 9508: // RACE_GOBLIN
               player->CLOSE_GOSSIP_MENU();
if(player->getRace() != RACE_GOBLIN) 
                     {
                            _creature->MonsterWhisper("You are not goblin!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(69044,false);
                player->learnSpell(69045,false);
                player->learnSpell(69046,false);
                player->learnSpell(69041,false);
                player->learnSpell(69070,false);
                player->learnSpell(69042,false);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                           }
          player->SaveToDB();
                break;



case 9509: // RACE_GNOME
               player->CLOSE_GOSSIP_MENU();
if(player->getRace() != RACE_GNOME) 
                     {
                            _creature->MonsterWhisper("You are not gnome!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(20592,false);
                player->learnSpell(20593,false);
                player->learnSpell(20589,false);
                player->learnSpell(20591,false);
                player->learnSpell(92680,false);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                           }
          player->SaveToDB();
                break;


case 9510: // RACE_DWARF
               player->CLOSE_GOSSIP_MENU();
if(player->getRace() != RACE_DWARF) 
                     {
                            _creature->MonsterWhisper("You are not dwarf!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(92682,false);
                player->learnSpell(20596,false);
                player->learnSpell(20595,false);
                player->learnSpell(59224,false);
                player->learnSpell(20594,false);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                           }
          player->SaveToDB();
                break;



case 9511: // RACE_DRAENEI
               player->CLOSE_GOSSIP_MENU();
if(player->getRace() != RACE_DRAENEI) 
                     {
                            _creature->MonsterWhisper("You are not draenei!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(28875,false);
                player->learnSpell(59545,false);
                player->learnSpell(59543,false);
                player->learnSpell(59548,false);
                player->learnSpell(59542,false);
                player->learnSpell(59544,false);
                player->learnSpell(59547,false);
                player->learnSpell(28880,false);
                player->learnSpell(28878,false);
                player->learnSpell(6562,false);
                player->learnSpell(59539,false);
                player->learnSpell(59536,false);
                player->learnSpell(59541,false);
                player->learnSpell(59535,false);
                player->learnSpell(59538,false);
                player->learnSpell(59540,false);
                player->learnSpell(59221,false);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                           }
          player->SaveToDB();
                break;



case 9512: // RACE_BLOODELF
               player->CLOSE_GOSSIP_MENU();
if(player->getRace() != RACE_BLOODELF) 
                     {
                            _creature->MonsterWhisper("You are not blood elf!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(28877,false);
                player->learnSpell(822,false);
                player->learnSpell(28730,false);
                player->learnSpell(50613,false);
                player->learnSpell(80483,false);
                player->learnSpell(25046,false);
                player->learnSpell(69179,false);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                           }
          player->SaveToDB();
                break;
/********** talent trener **********/

case 9513: //learn Talentpoints
          player->CLOSE_GOSSIP_MENU();
if (player->GetMoney() < 100000)
           {
            _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
             }
            else
          {
          player->learnSpell(63624,false);
          player->learnSpell(63645,false);
          player->ModifyMoney(-100000);
          player->CastSpell(player,61456,false);
          _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
          } 
     break;


/********** maps - Lvl - 1 - 10 **********/


            case 8165: // The Lost Isles
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(648, 1894.46f, 2374.89f, 106.96f, 0.0f);
                break;

            case 8164: // The Maelstrom
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(730, 848.26f, 1059.02f, -8.72f, 0.0f);
                break;

          
            case 8103: // Tirisfal Glades
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, 1767.014282, 1603.041382f, 109.400269, 0.0f);
                break;

          
            case 8104: // Elwynn Forest
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -8955.480469f, -111.595011f, 83.564697f, 0.0f);
                break;

          
            case 8105: // Eversong Woods
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, 9309.647461f, -7276.179688f, 14.339711f, 0.0f);
                break;

          
            case 8106: // Dun Morogh
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -5198.930176f, -706.850586f, 440.360199f, 0.0f);
                break;

          
            case 8107: // Azuremyst Isle
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, -4082.390381f, -12088.542969f, -0.269195f, 0.0f);
                break;

          
            case 8108: // Durotar
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -620.452454f, -4246.895508f, 38.249516f, 0.0f);
                break;

          
            case 8109: // Mulgore
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -2313.330322f, -599.830994f, -9.423983f, 0.0f);
                break;

          
            case 8110: // Teldrassil
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, 10111.556641f, 1557.459106f, 1324.261719f, 0.0f);
                break;
/********** maps - Lvl - 10 - 20 **********/

         
            case 8111: // Westfall
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -9819.956055f, 853.036926f, 26.700548f, 0.0f);
                break;

         
            case 8112: // Moonglade
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, 7471.103516f, -2192.027100f, 488.634186f, 0.0f);
                break;

         
            case 8113: // Ghostlands
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, 7956.662598f, -6867.772949f, 58.990391f, 0.0f);
                break;

         
            case 8114: // Loch Modan
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -5691.955078f, -2763.297363f, 362.190002f, 0.0f);
                break;

         
            case 8115: // Azshara
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, 2787.967285f, -3822.494141f, 84.157295f, 0.0f);
                break;

         
            case 8016: // Silverpine Forest
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, 688.796997f, 1329.707642f, 79.167076f, 0.0f);
                break;

         
            case 8017: // Bloodmyst Isle
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, -2751.966064f, -12211.155273f, 8.404005f, 0.0f);
                break;

         
            case 8018: // Darkshore
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, 4450.917480f, 244.048279f, 56.799850f, 0.0f);
                break;

         
            case 8019: // Northern Barrens
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, 317.590149f, -3637.057373f, 27.184921f, 0.0f);
                break;
/********** maps - Lvl - 20 - 30 **********/

          
            case 8020: // Wetlands
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -3609.084717f, -2719.246582f, 19.042072f, 0.0f);
                break;

         
            case 8021: // Hillsbrad Foothills
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -380.112152f, -779.572693f, 54.507160f, 0.0f);
                break;

         
            case 8022: // Duskwood
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -9918.702148f, -1701.012573f, 23.108900f, 0.0f);
                break;

         
            case 8023: // Ashenvale
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, 1929.315063f, -2171.898438f, 93.818321f, 0.0f);
                break;

         
            case 8024: // Arathi Highlands
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -920.627380f, -1663.048950f, 44.629242f, 0.0f);
                break;

         
            case 8025: // Stonetalon Mountains
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -212.826401f, -728.093567f, 3.445075f, 0.0f);
                break;
/********** maps - Lvl - 30 - 40 **********/

          
            case 8027: // Desolace
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, 273.152191f, 1834.254272f, 86.195023f, 0.0f);
                break;

         
            case 8028: // Southern Barrens
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -2349.770020f, -1770.589966f, 91.279198f, 0.0f);
                break;

         
            case 8029: // The Cape of Stranglethorn
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -12832.849609f, -341.096100f, 23.280008f, 0.0f);
                break;

         
            case 8030: // The Hinterlands
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, 126.800880f, -2778.366211f, 105.508347f, 0.0f);
                break;

         
            case 8031: // Stranglethorn Vale
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -13319.612305f, 74.760010f, 22.211460f, 0.0f);
                break;

         
            case 8032: // Dustwallow Marsh
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -3668.810791f, -2682.265625f, 38.182007f, 0.0f);
                break;

         
            case 8033: // Feralas
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -2693.983887f, 2317.634766f, 72.958321f, 0.0f);
                break;

         
            case 8034: // Western Plaguelands
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, 1922.893188f, -2638.356689f, 59.484028f, 0.0f);
                break;
/********** maps - Lvl - 40 - 50 **********/

    
            case 8035: // Thousand Needles
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -4642.843262f, -1836.449829f, 87.705566f, 0.0f);
                break;

         
            case 8037: // Badlands
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -6167.138184f, -3384.267090f, 244.136490f, 0.0f);
                break;

        
            case 8039: // Tanaris
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -7180.285156f, -3789.401611f, 9.559776f, 0.0f);
                break;

         
            case 8036: // Eastern Plaguelands
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, 1921.799927f, -2641.765137f, 59.506741f, 0.0f);
                break;


         
            case 8040: // Searing Gorge
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -6900.301270f, -1812.744336f, 240.483109f, 0.0f);
                break;

         
            case 8041: // Burning Steppes
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -7831.495605f, -725.617432f, 166.824081f, 0.0f);
                break;
/********** maps - Lvl - 50 - 60 **********/

         
            case 8042: // Blackrock Mountains
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(230, 462.725433f, 18.054283f, -71.020874f, 0.0f);
                break;

         
            case 8043: // Deadwind Pass
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -10438.817383f, -1932.324829f, 107.523834f, 0.0f);
                break;
 
 
            case 8045: // Winterspring
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, 6914.203613f, -4126.314453f, 693.471497f, 0.0f);
                break;

     
            case 8044: // Un'Goro Crater
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -8061.811523f, -2111.561523f, -173.258545f, 0.0f);
                break;

         
 case 8038: // Felwood
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, 3908.010986f, -1274.867798f, 222.365417f, 0.0f);
                break;


            case 8046: // Swamp of Sorrows
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -9723.984375f, -4026.755127f, 5.819955f, 0.0f);
                break;

         
            case 8047: // Silithus
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -6350.578613f, -297.563232f, -3.856270f, 0.0f);
                break;

         
            case 8048: // Blasted Lands
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -10777.960938f, -2993.870117f, 47.943962f, 0.0f);
                break;
/********** maps - Lvl - 60 - 70 **********/

         
            case 8050: // Zangarmarsh
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, 217.055130f, 7087.371582f, 35.228203f, 0.0f);
                break;

         
            case 8051: // Terokkar Forest
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, -1922.420776f, 4884.705078f, 2.270556f, 0.0f);
                break;

         
            case 8052: // Nagrand
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, -1570.451050f, 7950.109375f, -22.697489f, 0.0f);
                break;

         
            case 8053: // Blade's Edge Mountains
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, 2028.644897f,6044.441895f, 145.960068f, 0.0f);
                break;

         
            case 8054: // Netherstorm
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, 3621.755615f, 3050.173096f, 124.551437f, 0.0f);
                break;

         
            case 8055: // Shadowmoon Valley
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, -3039.413086f, 2932.312256f, 86.359238f, 0.0f);
                break;

         
            case 8056: // Howling Fjord
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 1740.558105f, -4883.295898f, 130.095367f, 0.0f);
                break;
/********** maps - Lvl - 70 - 80 **********/

         
            case 8057: // Borean Tundra
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 3264.701660f, 5291.354004f, 39.191471f, 0.0f);
                break;

         
            case 8058: // Dragonblight
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 3505.863281f, 2882.733398f, 30.775278f, 0.0f);
                break;

         
            case 8059: // Grizzly Hills
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 4391.729980f, -3587.919922f, 238.531006f, 0.0f);
                break;

         
            case 8060: // Zul'Drak
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 5560.229980f, -3211.659912f, 371.709015f, 0.0f);
                break;

         
            case 8061: // Sholazar Basin
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 5485.109375f, 4769.609863f, -198.586761f, 0.0f);
                break;

         
            case 8062: // Hrothgar's Landing
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 9902.225586f, 817.267029f, 20.585936f, 0.0f);
                break;

         
            case 8063: // Icecrown
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 8466.601562f, 470.399780f, 596.071472f, 0.0f);
                break;

         
            case 8064: // The Storm Peaks
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 6121.731445f, -1003.227112f, 406.580536f, 0.0f);
                break;

         
            case 8065: // Wintergrasp
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 4616.524902f, 2843.494385f, 396.896423f, 0.0f);
                break;


         
            case 8066: // Crystalsong Forest
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 5284.730957f, 152.879959f, 184.559692f, 0.0f);
                break;
/********** maps - Lvl - 80 - 85 **********/

         
            case 8067: // Mount Hyjal
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, 4979.109863f, -2603.098145f, 1423.815552f, 0.0f);
                break;

         
            case 8068: // Vashj'ir
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -5616.213867f, 3743.106445f, 2.303459f, 0.0f);
                break;

         
            case 8069: // Uldum
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -9196.900391f, -813.356018f, 136.158997f, 0.0f);
                break;

         
            case 8070: // Twilight Highlands
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -4472.665527f, -6575.234863f, 2.085357f, 0.0f);
                break;


            case 8072: // Deepholm
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(646, 934.949890f, 508.357788f, -49.33029f, 0.0f);
                break;




            case 8073: // Tol Barad Peninsula
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(732, -591.114014f, 1179.050049f, 95.624298f, 0.0f);
                break;
/********** reputace **********/

case 100: //Alliance Vanguard
                                return GiveReputation(player, 1037, 90999);

                         case 101: //Explorers' League
                                return GiveReputation(player, 1068, 90999);

                         case 102: //The Frostborn
                                return GiveReputation(player, 1126, 90999);

                         case 103: //The Silver Covenant
                                return GiveReputation(player, 1094, 90999);

                         case 104: //Valiance Expedition
                                return GiveReputation(player, 1050, 90999);

                         case 105: //Horde Expedition
                                return GiveReputation(player, 1052, 90999);

                         case 106: //The Hand of Vengeance
                                return GiveReputation(player, 1067, 90999);

                         case 107: //The Sunreavers
                                return GiveReputation(player, 1124, 90999);

                         case 108: //The Taunka
                                return GiveReputation(player, 1064, 90999);

                         case 109: //Warsong Offensive
                                return GiveReputation(player, 1085, 90999);

                         case 110: //Argent Crusade
                                return GiveReputation(player, 1106, 90999);

                         case 111: //Frenzyheart Tribe
                                return GiveReputation(player, 1104, 90999);

                         case 112: //Kirin Tor
                                return GiveReputation(player, 1090, 90999);

                         case 113: //Knights of the Ebon Blade
                                return GiveReputation(player, 1098, 90999);

                         case 114: //The Kalu'ak
                                return GiveReputation(player, 1073, 90999);

                         case 115: //The Oracles
                                return GiveReputation(player, 1105, 90999);

                         case 116: //The Sons of Hodir
                                return GiveReputation(player, 1119, 90999);

                         case 117: //The Wyrmrest Accord
                                return GiveReputation(player, 1091, 90999);

                         case 118: //The Ashen Verdict
                                return GiveReputation(player, 1156, 90999);

                         case 98: //Baradin's Wardens
                                return GiveReputation(player, 1177, 90999);

                         case 97: //Wildhammer Clan
                                return GiveReputation(player, 1174, 90999);

                         case 202: //Dragonmaw Clan
                                return GiveReputation(player, 1172, 90999);

                         case 203: //Hellscream's Reach
                                return GiveReputation(player, 1178, 90999);

                         case 204: //Guardians of Hyjal
                                return GiveReputation(player, 1158, 90999);

                         case 205: //Ramkahen
                                return GiveReputation(player, 1173, 90999);

                         case 206: //The Earthen Ring
                                return GiveReputation(player, 1135, 90999);

                         case 207: //Therazane
                                return GiveReputation(player, 1171, 90999);
/********** opravyt itemy **********/

        case 550007: //Opravit
                        player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Si opraveny :) / You are repair :)", player->GetGUID());
                player->DurabilityRepairAll(false, 0, false);
                player->CastSpell(player,61456,false);  
                break;
/********** Sell - 10 - 85 - lvl **********/

case 2013: //Sell 50 lvl -  50000 g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 500000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->GiveLevel(50);
                                        player->SaveToDB();
                                        player->UpdateSkillsToMaxSkillsForLevel();
                                        player->CastSpell(player,61456,false);
                                        player->RemoveAurasDueToSpell(57724);
                                        player->ModifyMoney(-500000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        }
                                     
                                     break;


case 2015: //Sell 85 lvl -  200000 g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->GiveLevel(85);
                                        player->SaveToDB();
                                        player->UpdateSkillsToMaxSkillsForLevel();
                                        player->CastSpell(player,61456,false);
                                        player->RemoveAurasDueToSpell(57724);
                                        player->ModifyMoney(-2000000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

/********** currencies **********/
  



case 2014: // 2x Draenei Archaeology Fragment - cost 200g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(398, 2000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-2000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2016: // 2x Dwarf Archaeology Fragment - cost 200g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(384, 2000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-2000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2017: // 2x Fossil Archaeology Fragment - cost 200g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(393, 2000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-2000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2018: // 2x Nerubian Archaeology Fragment - cost 200g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(400, 2000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-2000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2019: // 2x Night Elf Archaeology Fragment - cost 200g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(394, 2000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-2000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2020: // 2x Orc Archaeology Fragment - cost 200g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(397, 2000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-2000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2021: // 2x Tol'vir Archaeology Fragment - cost 200g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(401, 2000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-2000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2022: // 2x Troll Archaeology Fragment - cost 200g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(385, 2000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-2000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2023: // 2x Vrykul Archaeology Fragment - cost 200g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(399, 2000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-2000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;





case 2034: // 2x Illustrious Jewelcrafter's Token - cost 20g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 200000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(361, 200);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-200000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2035: // 2x Valor Points - cost 20g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 200000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(396, 200);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-200000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2036: // 20x Valor Points - cost 200g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(396, 2000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-2000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2037: // 200x Valor Points - cost 2000g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 20000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(396, 20000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-20000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2038: // 1000x Valor Points - cost 10000g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 100000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(396, 100000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-100000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2039: // 2x Justice Points - cost 2g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 20000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(395, 200);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-20000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2040: // 20x Justice Points - cost 20g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 200000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(395, 2000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-200000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2041: // 200x Justice Points - cost 200g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(395, 20000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-2000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2042: // 2000x Justice Points - cost 2000g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 20000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(395, 200000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-20000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2043: // 2x Conquest Points - cost 20g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 200000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(390, 200);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-200000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2044: // 20x Conquest Points - cost 200g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(390, 2000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-2000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2045: // 200x Conquest Points - cost 2000g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 20000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(390, 20000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-20000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2046: // 1000x Conquest Points - cost 10000g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 100000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(390, 100000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-100000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2047: // 2x Honor Points - cost 2g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 20000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(392, 200);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-20000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2048: // 20x Honor Points - cost 20g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 200000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(392, 2000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-200000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2049: // 200x Honor Points - cost 200g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(392, 20000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-2000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2050: // 2000x Honor Points - cost 2000g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 20000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(392, 200000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-20000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2051: // 20x Tol Barad Commendation - cost 20g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 200000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(391, 2000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-200000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2052: // 200x Tol Barad Commendation - cost 200g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 2000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(391, 20000);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-2000000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;
case 2053: // 2x Champion's Seal - cost 20g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 200000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(241, 200);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-200000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2054: // 2x Chef's Award - cost 20g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 200000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(402, 200);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-200000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2055: // 2x Dalaran Cooking Award - cost 20g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 200000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(81, 200);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-200000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

case 2056: // 2x Dalaran Jewelcrafter's Token - cost 20g
                    player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 200000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->ModifyCurrency(61, 200);
                                        player->SaveToDB();
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-200000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
                                        break;

/********** Vanishing -Dust  **********/

case 451: // 1x Vanishing Powder - cost 1g
player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 10000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->AddItem(64670, 1);
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-10000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        }
                                     
                                     break;

case 452: // 1x Dust of Disappearance - cost 1g
player->CLOSE_GOSSIP_MENU();
                                        if (player->GetMoney() < 10000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                                        player->AddItem(63388, 1);
                                        player->CastSpell(player,61456,false);
                                        player->ModifyMoney(-10000);
                                        _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        }
                                     
                                     break;
/********** Custom Sound Effects   **********/
case 351:

player->PlayDirectSound(10027);
player->MonsterSay("Whisling", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 350: 

player->PlayDirectSound(8475);
player->MonsterSay("Awwww isnt it cute, wait...get it off me!!! KILL IT", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 349: 

player->PlayDirectSound(7120);
player->MonsterSay("Horde Talk", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 348: 

player->PlayDirectSound(7096);
player->MonsterSay("Buttslap - whip", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();
return true;

case 347: 

player->PlayDirectSound(6099);
player->MonsterSay("Summon Succubus - Now What? Mhmmm, you're in trouble now! Don't touch what you can't afford Couldn't resist, Could you?", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();
return true;

case 346: 

player->PlayDirectSound(5882);
player->MonsterSay("You asked for it!/I hate resolving to violence", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();
return true;

case 345: 

player->PlayDirectSound(6004);
player->MonsterSay("Welcome to Orgrimmar, have you come to serve the horde? Lok'Thar fri, What is it you wish?", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();
return true;

case 344: 

player->PlayDirectSound(5880);
player->MonsterSay("Lok'Narosh Your Time has come! For Doomhammer", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();
return true;

case 343: 

player->PlayDirectSound(5779);
player->MonsterSay("Thuh, now you are making me angry!", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();
return true;

case 342: 

player->PlayDirectSound(5778);
player->MonsterSay("...bla...bla... all I have to do is to improvise", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();
return true;

case 341: 

player->PlayDirectSound(5777);
player->MonsterSay("We're under attack...", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();
return true;

case 340:
 
player->PlayDirectSound(5775 );
player->MonsterSay("You there, check you that noise!", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 339: 

player->PlayDirectSound(11964);
player->MonsterSay("Headless Horseman He Dies!", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 338: 

player->PlayDirectSound(11967);
player->MonsterSay("Failed When all of you is dead", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 337: 

player->PlayDirectSound(11965);
player->MonsterSay("HA HA HA HA HA HA HA LOL", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 336: 

player->PlayDirectSound(7214);
player->MonsterSay("Lo Tar Fri What Do you Wish?", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 335: 

player->PlayDirectSound(7195);
player->MonsterSay("Pissed Orc Peon", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 334: 

player->PlayDirectSound(6179);
player->MonsterSay("Your not funny", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 333: 

player->PlayDirectSound(11389);
player->MonsterSay("Shade of Akama", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 332: 

player->PlayDirectSound(11802);
player->MonsterSay("Rgrglrgrlgrl", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 331: 

player->PlayDirectSound(12541);
player->MonsterSay("There is no time to waste The faith of the world hangs in the balance Kil Jaeden must be destroyed!", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 330: 

player->PlayDirectSound(12513);
player->MonsterSay("Kalec? Kalec?!", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 329: 

player->PlayDirectSound(12512);
player->MonsterSay("But I am... lost... I can not find my way back!", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 328: 

player->PlayDirectSound(12511);
player->MonsterSay("I serve only the master now!", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 327: 

player->PlayDirectSound(12501);
player->MonsterSay("Another step towards destruction!", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 326: 

player->PlayDirectSound(12500);
player->MonsterSay("Very long thing, basiclly he tells us that he will take control over the Burning Legion", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;


case 325: 

player->PlayDirectSound(12499);
player->MonsterSay("Drain the girl, drain her power, untill there is nothing but an ...something... shell", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 324: 

player->PlayDirectSound(12498);
player->MonsterSay("Fail me, and suffer for eternity!", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 323: 

player->PlayDirectSound(12497);
player->MonsterSay("I've waited long enough", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 322: 

player->PlayDirectSound(12496);
player->MonsterSay("Stay on task, do not waste time", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 321: 

player->PlayDirectSound(12495);
player->MonsterSay("All my plans have led to this", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 320: 

player->PlayDirectSound(12527);
player->MonsterSay("Kil Jaeden Spawning", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 51: 

player->PlayDirectSound(11463);
player->MonsterSay("Akama your duplicity is hardly surprising I should of slaughtered you and your malformed brethren long ago", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 52:

player->PlayDirectSound(11464);
player->MonsterSay("Boldly said but I remain unconvinced", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 53:

player->PlayDirectSound(11465);
player->MonsterSay("Come my minions, deal with this traitor as he deserves", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 54:

player->PlayDirectSound(11466);
player->MonsterSay("You are not prepared!!", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 55:

player->PlayDirectSound(11467);
player->MonsterSay("I can feel your hatred", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 536:

player->PlayDirectSound(11468 );
player->MonsterSay("Give into your fear", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 37:

player->PlayDirectSound(11469);
player->MonsterSay("You know nothing of power", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 38:

player->PlayDirectSound(11470);
player->MonsterSay("Feel the hatred of 10,000 years", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 39:

player->PlayDirectSound(11471);
player->MonsterSay("Such arrogance", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 310:

player->PlayDirectSound(11472);
player->MonsterSay("This is to easy", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 311:

player->PlayDirectSound(11473);
player->MonsterSay("Who shall be next to taste my blades?", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 312:

player->PlayDirectSound(11474);
player->MonsterSay("You have wasted to much time mortals. Now you shall fall", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 313:

player->PlayDirectSound(11475);
player->MonsterSay("Behold the power of the Demon within", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 314:

player->PlayDirectSound(11476);
player->MonsterSay("Is this it mortals? Is this all the fury you can muster?", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 315:

player->PlayDirectSound(11477);
player->MonsterSay("Maiev. How is it even possible?", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 316:

player->PlayDirectSound(11478);
player->MonsterSay("You have won ... Maiev , but the huntress is nothing without the hunt. You are nothing without me", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 317:

player->PlayDirectSound(11479);
player->MonsterSay("I will not be touched by a rebel such as you", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();

return true;

case 318:

player->PlayDirectSound(11480);
player->MonsterSay("Behold the flames of Azzinoth!", LANG_UNIVERSAL, NULL);
player->CLOSE_GOSSIP_MENU();
return true;
                break;
/********** Shoop tele   **********/


case 8503: // Proffesions 
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, -1852.51f, 5407.94f, -12.42f, 0.0f);
break;


/********** dk zona   **********/
case 8526: // Horne Patro
  player->CLOSE_GOSSIP_MENU();
if(player->getClass() != CLASS_DEATH_KNIGHT) 
                     {
                            _creature->MonsterWhisper("You are not death knight!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {

  player->TeleportTo(609, 2393.52f, -5638.44f, 420.88f, 0.0f);
                                     }
          player->SaveToDB();
              	break;


case 8527: // Dolne Patro
  player->CLOSE_GOSSIP_MENU();
if(player->getClass() != CLASS_DEATH_KNIGHT) 
                     {
                            _creature->MonsterWhisper("You are not death knight!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {

  player->TeleportTo(609, 2400.33f, -5634.36f, 377.02f, 0.0f);
                                     }
          player->SaveToDB();
              	break;


case 8528: // Suteren
  player->CLOSE_GOSSIP_MENU();
if(player->getClass() != CLASS_DEATH_KNIGHT) 
                     {
                            _creature->MonsterWhisper("You are not death knight!", player->GetGUID());
                   		return true;
              	}
			if (player->isInCombat())
            		{
                		player->CLOSE_GOSSIP_MENU();
                		_creature->MonsterWhisper("Combat!", player->GetGUID());
              		return true;
            		return true;
                        }
              	else
                        {

  player->TeleportTo(609, 2346.48f, -5693.17f, 153.92f, 0.0f);
                                     }
          player->SaveToDB();
              	break;

/********** text   **********/
                             
case 50800: // Pravydla text
player->CLOSE_GOSSIP_MENU();
player->SEND_GOSSIP_MENU(GOSSIP_PRAVYDLA, _creature->GetGUID()); 
break;

/********** text   **********/


case 9601: // minig
               player->CLOSE_GOSSIP_MENU();
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(2580,false);
                player->learnSpell(2575,false);
                player->learnSpell(2576,false);
                player->learnSpell(3564,false);
                player->learnSpell(10284,false);
                player->learnSpell(29354,false);
                player->learnSpell(50310,false);
                player->learnSpell(74517,false);
                player->learnSpell(2656,false);
                player->learnSpell(53120,false);
                player->learnSpell(53121,false);
                player->learnSpell(53122,false);
                player->learnSpell(53123,false);
                player->learnSpell(53124,false);
                player->learnSpell(53040,false);
                player->learnSpell(74496,false);
                    //recepty
                player->learnSpell(2657,false);
                player->learnSpell(3304,false);
                player->learnSpell(2659,false);
                player->learnSpell(2658,false);
                player->learnSpell(3307,false);
                player->learnSpell(3308,false);
                player->learnSpell(3569,false);
                player->learnSpell(16153,false);
                player->learnSpell(10098,false);
                player->learnSpell(14891,false);
                player->learnSpell(70524,false);
                player->learnSpell(29356,false);
                player->learnSpell(35750,false);
                player->learnSpell(35751,false);
                player->learnSpell(22967,false);
                player->learnSpell(29358,false);
                player->learnSpell(29359,false);
                player->learnSpell(29360,false);
                player->learnSpell(49252,false);
                player->learnSpell(46353,false);
                player->learnSpell(29361,false);
                player->learnSpell(29686,false);
                player->learnSpell(49258,false);
                player->learnSpell(84038,false);
                player->learnSpell(55211,false);
                player->learnSpell(55208,false);
                player->learnSpell(74530,false);
                player->learnSpell(74537,false);
                player->learnSpell(74529,false);
                player->UpdateSkill (186, 525);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
          player->SaveToDB();
                break;


case 9603: // skyning 
               player->CLOSE_GOSSIP_MENU();
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(53125,false);
                player->learnSpell(53662,false);
                player->learnSpell(53663,false);
                player->learnSpell(53664,false);
                player->learnSpell(53665,false);
                player->learnSpell(53666,false);
                player->learnSpell(74495,false);
                player->learnSpell(8613,false);
                player->learnSpell(8617,false);
                player->learnSpell(8618,false);
                player->learnSpell(10768,false);
                player->learnSpell(32678,false);
                player->learnSpell(50305,false);
                player->learnSpell(74522,false);
                player->UpdateSkill (393, 525);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
          player->SaveToDB();
                break;


case 9602: // herbalism
               player->CLOSE_GOSSIP_MENU();
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(2383,false);
                player->learnSpell(2366,false);
                player->learnSpell(2368,false);
                player->learnSpell(3570,false);
                player->learnSpell(11993,false);
                player->learnSpell(28695,false);
                player->learnSpell(50300,false);
                player->learnSpell(74519,false);
                player->learnSpell(81708,false);
                player->learnSpell(74497,false);
                player->learnSpell(55428,false);
                player->learnSpell(55500,false);
                player->learnSpell(55501,false);
                player->learnSpell(55502,false);
                player->learnSpell(55503,false);
                player->UpdateSkill (182, 525);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
          player->SaveToDB();
                break;

                        

case 9604: // Archaeology
               player->CLOSE_GOSSIP_MENU();
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(78670,false);
                player->learnSpell(88961,false);
                player->learnSpell(89718,false);
                player->learnSpell(89719,false);
                player->learnSpell(89720,false);
                player->learnSpell(89721,false);
                player->learnSpell(89722,false);
                player->learnSpell(73979,false);
                player->learnSpell(80451,false);
                player->learnSpell(74268,false);
                player->UpdateSkill (794, 525);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
          player->SaveToDB();
                break;

/********** nakup packou   **********/

case 2100: // Archaeology
               player->CLOSE_GOSSIP_MENU();
if (player->GetMoney() < 1000000000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->AddItem(64481, 1);
                player->AddItem(64646, 1);
                player->AddItem(60954, 1);
                player->AddItem(64883, 1);
                player->AddItem(64489, 1);
                player->AddItem(64645, 1);
                player->AddItem(64377, 1);
                player->AddItem(60955, 1);
                player->AddItem(64488, 1);
                               player->ModifyMoney(-1000000000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
          player->SaveToDB();
                break;


case 2101: // for new players
               player->CLOSE_GOSSIP_MENU();
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->AddItem(21843, 4); //bagle
                       // itemy
                player->AddItem(48677, 1); 
                player->AddItem(48685, 1); 
                player->AddItem(48691, 1); 

                player->AddItem(42985, 1); 
                player->AddItem(42949, 1); 
                player->AddItem(42950, 1); 

                player->AddItem(42947, 1); 
                player->AddItem(42944, 1); 
                player->AddItem(42946, 1); 
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
          player->SaveToDB();
                break;


case 2102: // packs
               player->CLOSE_GOSSIP_MENU();
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
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
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
          player->SaveToDB();
                break;


case 2105: // packs
               player->CLOSE_GOSSIP_MENU();
if (player->GetMoney() < 100000)
                                                {
                                                        _creature->MonsterSay("Nemas dostatek goldu." ,0 , player->GetGUID());
                                        }
                                        else
                                                {
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
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
                player->learnSpell(36907,false);
                player->learnSpell(10709,false);
                player->learnSpell(65358,false);
                player->learnSpell(90523,false);
                player->learnSpell(69452,false);
                player->learnSpell(10674,false);
                player->learnSpell(84263,false);
                player->learnSpell(100684,false);
                player->learnSpell(65382,false);
                player->learnSpell(67414,false);
                player->learnSpell(25162,false);
                player->learnSpell(62508,false);
                player->learnSpell(40614,false);
                player->learnSpell(93383,false);
                player->learnSpell(62516,false);
                player->learnSpell(93836,false);
                player->learnSpell(45174,false);
                player->learnSpell(99663,false);
                player->learnSpell(66520,false);
                               player->ModifyMoney(-100000);
                player->CastSpell(player,61456,false);
 _creature->MonsterSay("Dakujem za obchod :) / Thank for bussines :)" ,0 , player->GetGUID());
                                        } 
          player->SaveToDB();
                break;


             default:

        break; 
                
    }
   }
  return true;
 }
};
/*###
#
###*/

void AddSC_npc_hybrid()
{
    new npc_hybrid();
}

