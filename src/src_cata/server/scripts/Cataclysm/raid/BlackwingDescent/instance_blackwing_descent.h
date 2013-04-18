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

#ifndef DEF_BLACKWING_DESCENT_H
#define DEF_BLACKWING_DESCENT_H

enum SharedSpells
{
    SPELL_BERSERK1 = 26662,
    SPELL_BERSERK2 = 64238,
};

enum Data
{
    //Encounters
    DATA_MAGMAW = 0,
    DATA_OMNOTRON_DEFENSE_SYSTEM = 1,
    DATA_MALORIAK = 2,
    DATA_ATRAMEDES = 3,
    DATA_CHIMAERON = 4,
    DATA_NEFARIAN = 5,

    //Additional Entities
    DATA_ARCANOTRON_GUID = 6,
    DATA_ELECTRON_GUID = 7,
    DATA_MAGMATRON_GUID = 8,
    DATA_TOXITRON_GUID = 9,
    DATA_ONYXIA_GUID = 10,
    DATA_BILE_O_TRON_800 = 11,
    MAX_ENCOUNTER = 12
};

enum Creatures
{
    NPC_MAGMAW = 41570,
    NPC_ARCANOTRON = 42166,
    NPC_ELECTRON = 42179,
    NPC_MAGMATRON = 42178,
    NPC_TOXITRON = 42180,
    NPC_MALORIAK = 41378,
    NPC_ATRAMEDES = 41442,
    NPC_CHIMAERON = 43296,
    NPC_BILE_O_TRON_800 = 44418,
    NPC_NEFARIAN = 41376,
    NPC_ONYXIA = 41270,
    NPC_LORD_VICTOR_NEFARIAN = 41379,
};

#endif
