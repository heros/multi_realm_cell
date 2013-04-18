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

#ifndef DEF_THRONE_OF_THE_TIDES
#define DEF_THRONE_OF_THE_TIDES

enum Data64 {
    DATA_LADY_NAZJAR,
    DATA_COMMANDER_ULTHOK,
    DATA_ERUNAK_STONESPEAKER,
    DATA_MINDBENDER_GHURSHA,
    DATA_OZUMAT,
};

enum Data {
    DATA_LADY_NAZJAR_EVENT,
    DATA_COMMANDER_ULTHOK_EVENT,
    DATA_ERUNAK_STONESPEAKER_EVENT,
    DATA_MINDBENDER_GHURSHA_EVENT,
    DATA_OZUMAT_EVENT,
};

enum CreatureIds {
    /* Dungeons Bosses */

    BOSS_LADY_NAZJAR = 40586,
    BOSS_COMMANDER_ULTHOK = 40765,
    BOSS_ERUNAK_STONESPEAKER = 40825,
    BOSS_MINDBENDER_GHURSHA = 40788,
    BOSS_OZUMAT = 42172,

    /* Various NPCs */

    NPC_CAPTAIN_TAYLOR = 50270,
    NPC_LEGIONNAIRE_NAZGRIM = 50272,
    NPC_NEPTULON = 40792,
    NPC_THRONE_TELEPORTER_1 = 51395,
    NPC_THRONE_TELEPORTER_2 = 51391,
};

enum GameObjectIds {
    GO_NEPUTOLON_CACHE = 205216, GO_STRANGE_FOUNTAIN = 207406,
};

#endif
