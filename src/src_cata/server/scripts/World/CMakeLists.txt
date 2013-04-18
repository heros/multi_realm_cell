# 
# Copyright (C) Likan Mod   (https://github.com/ChaosDevLikan/)
# Copyright (C) Prydev      (http://sourceforge.net/projects/prydevserver) 
# Copyright (C) TrinityCore (http://www.trinitycore.org)
# Copyright (C) MaNGOS      (http://www.getmangos.com)
# Copyright (C) ArkCORE     (http://www.arkania.net)
# Copyright (C) SkyFireEMU  (http://www.projectskyfire.org)
# 
# World of Warcraft
# You can edit but you can not delete this copyright.
# Genesis Emulator - Genesis Database 
# 
# 
#  By Likan Developer Core C++, SQL (FUN, WoTLK, Cata Realm) of Genesis Server
# 

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  World/achievement_scripts.cpp
  World/areatrigger_scripts.cpp
  World/boss_emerald_dragons.cpp
  World/chat_log.cpp
  World/go_scripts.cpp
  World/guards.cpp
  World/item_scripts.cpp
  World/mob_generic_creature.cpp
  World/npc_innkeeper.cpp
  World/npc_professions.cpp
  World/npc_taxi.cpp
  World/npcs_special.cpp
)

message("  -> Prepared: World")
