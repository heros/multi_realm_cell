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

#ifndef DEF_VORTEX_PINNACLE_H
#define DEF_VORTEX_PINNACLE_H

enum Data
{
    DATA_GRAND_VIZIER_ERTAN_EVENT,
    DATA_ALTAIRUS_EVENT,
    DATA_ASAAD_EVENT,
    DATA_TEAM_IN_INSTANCE_EVENT,
};

enum Data64
{
    DATA_GRAND_VIZIER_ERTAN,
    DATA_ALTAIRUS,
    DATA_ASAAD,
};

enum CreatureIds
{
    // Dungeon Bosses

    BOSS_GRAND_VIZIER_ERTAN     = 43878,
    BOSS_ALTAIRUS               = 43873,
    BOSS_ASAAD                  = 43875,

    // Trash mobs

    NPC_ARMORED_MISTRAL         = 45915,
    NPC_CLOUD_PRINCE            = 45917,
    NPC_EMPYREAN_ASSASSIN       = 45922,
    NPC_EXECUTOR_OF_THE_CALIPH  = 45928,
    NPC_GUST_SOLDIER            = 45477,
    NPC_HOWLING_GALE            = 45572,
    NPC_LURKING_TEMPEST         = 45704,
    NPC_MINISTER_OF_AIR         = 45930,
    NPC_TEMPLE_ADEPT            = 45935,
    NPC_YOUNG_STORM_DRAGON      = 45919,
    NPC_WILD_VORTEX             = 45912,
    NPC_SLIPSTREAM              = 45455,
    // Various NPCs

    NPC_GOLDEN_ORB              = 51157,  /*Heroic Mode*/
    NPC_ITESH                   = 49943,
};

enum GameObjectIds
{
    GO_MAGIC_BRAZIER            = 207408,
};

#endif