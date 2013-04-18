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

#ifndef DEF_DEADMINES_H
#define DEF_DEADMINES_H

enum CannonState {
    CANNON_NOT_USED,
    CANNON_GUNPOWDER_USED,
    CANNON_BLAST_INITIATED,
    PIRATES_ATTACK,
    EVENT_DONE
};

enum Data {
    EVENT_STATE, EVENT_RHAHKZOR
};

enum Data64 {
    DATA_SMITE_CHEST
};

enum GameObjects {
    GO_FACTORY_DOOR = 13965,
    GO_IRONCLAD_DOOR = 16397,
    GO_DEFIAS_CANNON = 16398,
    GO_DOOR_LEVER = 101833,
    GO_MR_SMITE_CHEST = 144111
};
#endif
