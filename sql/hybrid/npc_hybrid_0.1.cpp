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
SDName: npc_hybrid
SD%Complete: 100%
SDComment: Wotlk/Cataclysm Teleporter reset custom
SDCategory: Custom NPC Script
EndScriptData */

/*###
# generic defines
###*/

//Includes
#include "ScriptPCH.h"

//Define Spells
#define SPELL_REPUTATION    61456  //Only Visual Effect

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
     _creature->MonsterWhisper("Dobri den èo si budete pria / Hi my friends :) ?", player->GetGUID());
          player->SetHealth(player->GetMaxHealth());
          player->SetPower(POWER_MANA, 
          player->GetMaxPower(POWER_MANA));
          player->RemoveAllSpellCooldown();
          player->CastSpell(player,61456,false);
          player->CastSpell(player,75669,false);
          player->CastSpell(player,93346,false);
          player->CastSpell(player,1126,true);
          player->CastSpell(player,36880,true);
          player->CastSpell(player,467,true);
          player->CastSpell(player,19740,true);
          player->CastSpell(player,20217,true);
          player->CastSpell(player,56521,true);
          player->CastSpell(player,39234,true);
          player->CastSpell(player,21562,true);
          player->CastSpell(player,27683,true);

    player->ADD_GOSSIP_ITEM( 5, "[Cities] ->"                    , GOSSIP_SENDER_MAIN, 5576);
    player->ADD_GOSSIP_ITEM( 5, "[Exp. maps] ->"                    , GOSSIP_SENDER_MAIN, 7782);
    player->ADD_GOSSIP_ITEM( 5, "[Instances] ->"      , GOSSIP_SENDER_MAIN, 7781);
    player->ADD_GOSSIP_ITEM( 5, "[Arenas] ->"     , GOSSIP_SENDER_MAIN, 5575);
    player->ADD_GOSSIP_ITEM( 7, "[Morph] ->"       , GOSSIP_SENDER_MAIN, 5579);
    player->ADD_GOSSIP_ITEM( 7, "[Reset / Player Tools] ->"       , GOSSIP_SENDER_MAIN, 5580);
    player->ADD_GOSSIP_ITEM( 7, "[Mr.Doctor] ->"       , GOSSIP_SENDER_MAIN, 7777);
    player->ADD_GOSSIP_ITEM( 7, "[Buffs] ->"       , GOSSIP_SENDER_MAIN, 7778);
    player->ADD_GOSSIP_ITEM( 7, "[Mount Pujcovna / Rental] ->"       , GOSSIP_SENDER_MAIN, 7779);
    player->ADD_GOSSIP_ITEM( 7, "[Mount Trainer] ->"       , GOSSIP_SENDER_MAIN, 7780);
    player->ADD_GOSSIP_ITEM( 7, "[Reputation] ->"       , GOSSIP_SENDER_MAIN, 208);
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
  player->ADD_GOSSIP_ITEM( 5, "Throne of the Four Winds"                          , GOSSIP_SENDER_MAIN, 223);
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
             player->ADD_GOSSIP_ITEM( 3, "Gnome"                    , GOSSIP_SENDER_MAIN, 1);
             player->ADD_GOSSIP_ITEM( 3, "Human"                    , GOSSIP_SENDER_MAIN, 2);
             player->ADD_GOSSIP_ITEM( 3, "Tauren"                   , GOSSIP_SENDER_MAIN, 3);
             player->ADD_GOSSIP_ITEM( 3, "Goblin"                   , GOSSIP_SENDER_MAIN, 4);
             player->ADD_GOSSIP_ITEM( 3, "Blood Elf"                , GOSSIP_SENDER_MAIN, 5);
             player->ADD_GOSSIP_ITEM( 3, "Broken"                   , GOSSIP_SENDER_MAIN, 6);
             player->ADD_GOSSIP_ITEM( 3, "Other"                   , GOSSIP_SENDER_MAIN, 7);
             player->ADD_GOSSIP_ITEM( 9, "Demorph"                  , GOSSIP_SENDER_MAIN, 8);
             player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;


case 1://Gnome
                        player->ADD_GOSSIP_ITEM( 3, "Male"                      , GOSSIP_SENDER_MAIN, 9);
                        player->ADD_GOSSIP_ITEM( 3, "Female"                    , GOSSIP_SENDER_MAIN, 10);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

             case 2://Human
                        player->ADD_GOSSIP_ITEM( 3, "Male"                      , GOSSIP_SENDER_MAIN, 11);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

             case 3://Tauren
                        player->ADD_GOSSIP_ITEM( 3, "Male"                      , GOSSIP_SENDER_MAIN, 12);
                        player->ADD_GOSSIP_ITEM( 3, "Female"                    , GOSSIP_SENDER_MAIN, 13);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

             case 4://Goblin
                        player->ADD_GOSSIP_ITEM( 3, "Male"                      , GOSSIP_SENDER_MAIN, 14);
                        player->ADD_GOSSIP_ITEM( 3, "Female"                    , GOSSIP_SENDER_MAIN, 15);
                         player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

             case 5://Blood Elf
                        player->ADD_GOSSIP_ITEM( 3, "Male"                      , GOSSIP_SENDER_MAIN, 16);
                        player->ADD_GOSSIP_ITEM( 3, "Female"                    , GOSSIP_SENDER_MAIN, 17);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

             case 6://Broken
                        player->ADD_GOSSIP_ITEM( 3, "Male"                      , GOSSIP_SENDER_MAIN, 18);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Morph]"                , GOSSIP_SENDER_MAIN, 5579);
                        player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 5552);


                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;

             case 7://Other
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
                        player->ADD_GOSSIP_ITEM( 9, "Character Customize"                               , GOSSIP_SENDER_MAIN, 1013);
                        player->ADD_GOSSIP_ITEM( 9, "Faction Change"                            , GOSSIP_SENDER_MAIN, 1014);
                        player->ADD_GOSSIP_ITEM( 9, "Name Change"                , GOSSIP_SENDER_MAIN, 1015);
                        player->ADD_GOSSIP_ITEM( 9, "Reset Talentpoints"                , GOSSIP_SENDER_MAIN, 1016);
                        player->ADD_GOSSIP_ITEM( 9, "Advance all skills"                , GOSSIP_SENDER_MAIN, 1017);
                        player->ADD_GOSSIP_ITEM( 9, "Give lvl 1 / WARNING !!!"                , GOSSIP_SENDER_MAIN, 1018);
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
                        player->ADD_GOSSIP_ITEM( 5, "Northern Stranglethorn Lvl 25-30"       , GOSSIP_SENDER_MAIN, 8026);
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



                case 209: //Wrath of the Lich King
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



                         case 99: //Cataclysm
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





                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                        break;



case 5552: //Back To Main Menu
   {
    player->ADD_GOSSIP_ITEM( 5, "[Cities] ->"                    , GOSSIP_SENDER_MAIN, 5576);
    player->ADD_GOSSIP_ITEM( 5, "[Exp. maps] ->"                    , GOSSIP_SENDER_MAIN, 7782);
    player->ADD_GOSSIP_ITEM( 5, "[Instances] ->"      , GOSSIP_SENDER_MAIN, 7781);
    player->ADD_GOSSIP_ITEM( 5, "[Arenas] ->"     , GOSSIP_SENDER_MAIN, 5575);
    player->ADD_GOSSIP_ITEM( 7, "[Morph] ->"       , GOSSIP_SENDER_MAIN, 5579);
    player->ADD_GOSSIP_ITEM( 7, "[Reset / Player Tools] ->"       , GOSSIP_SENDER_MAIN, 5580);
    player->ADD_GOSSIP_ITEM( 7, "[Mr.Doctor] ->"       , GOSSIP_SENDER_MAIN, 7777);
    player->ADD_GOSSIP_ITEM( 7, "[Buffs] ->"       , GOSSIP_SENDER_MAIN, 7778);
    player->ADD_GOSSIP_ITEM( 7, "[Mount Pujcovna / Rental] ->"       , GOSSIP_SENDER_MAIN, 7779);
    player->ADD_GOSSIP_ITEM( 7, "[Mount Trainer] ->"       , GOSSIP_SENDER_MAIN, 7780);
    player->ADD_GOSSIP_ITEM( 7, "[Reputation] ->"       , GOSSIP_SENDER_MAIN, 208);
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
                                player->TeleportTo(645, 322.609985f, 561.294006f, 66.021400f, 0.0f);
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
                                player->TeleportTo(646, -11505.250977f, -2309.106445f, 608.393433f, 0.0f);
                               break;

                         case 217: //The Vortex Pinnacle
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(1, 1021.212585f, 649.178284f, 156.672363f, 0.0f);
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

case 9://Gnome - Male
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

       case 8://Demorph
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
      break;


case 1011://Remove All Auras
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->RemoveAllAuras();
          player->CastSpell(player,61456,false); 
      break;


case 1012://Remove Res Sickness
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          //if (player->HasAura(15007,0))
          {
          player->RemoveAurasDueToSpell(15007,0);
          }
          player->CastSpell(player,61456,false); 
      break;


case 1013://Character Customize
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
          player->CastSpell(player,61456,false); 
      break;


case 1014://Faction Change
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
          player->CastSpell(player,61456,false); 
      break;


case 1015://Name Change
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->SetAtLoginFlag(AT_LOGIN_RENAME);
          player->CastSpell(player,61456,false); 
     break;


case 1016://Reset Talentpoints
          player->CLOSE_GOSSIP_MENU();
          player->SendTalentWipeConfirm(player->GetGUID());
          player->CastSpell(player,61456,false); 
     break;


case 1017://Advance all skills
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->UpdateSkillsToMaxSkillsForLevel();
          player->CastSpell(player,61456,false); 
     break;


case 1018://Give lvl 1 / WARNING !!!
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->GiveLevel(1);
          player->CastSpell(player,61456,false); 
     break;


case 1019://Save Player to DB
          player->CLOSE_GOSSIP_MENU();
          _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
          player->SaveToDB();
          player->CastSpell(player,61456,false);         
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
/********** Mount - Trener **********/

          
            case 7780: // Mount Trener
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Hotovo:)", player->GetGUID());
                player->learnSpell(33388,false);
                player->learnSpell(34091,false);
                player->learnSpell(54197,false);
                player->learnSpell(34090,false);
                player->learnSpell(90267,false);
                player->learnSpell(33391,false);
                player->learnSpell(90265,false);
                player->CastSpell(player,61456,false); 
                break;
/********** maps - Lvl - 1 - 10 **********/


          
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
/********** effekty - hybrida **********/
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
