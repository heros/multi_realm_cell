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

if( USE_COREPCH )
  include_directories(${CMAKE_CURRENT_BINARY_DIR})
endif()

file(GLOB_RECURSE sources_Management Management/*.cpp Management/*.h)
file(GLOB_RECURSE sources_PrecompiledHeaders PrecompiledHeaders/*.cpp PrecompiledHeaders/*.h)
file(GLOB_RECURSE sources_Maps Maps/*.cpp Maps/*.h)
file(GLOB_RECURSE sources_Models Models/*.cpp Models/*.h)
file(GLOB sources_localdir *.cpp *.h)

source_group(CMake FILES CMakeLists.txt)
source_group(Management FILES ${sources_Management})
source_group(PrecompiledHeaders FILES ${sources_PrecompiledHeaders})
source_group(Maps FILES ${sources_Maps})
source_group(Models FILES ${sources_Models})

if (USE_COREPCH)
  set(collision_STAT_PCH_HDR PrecompiledHeaders/collisionPCH.h)
  set(collision_STAT_PCH_SRC PrecompiledHeaders/collisionPCH.cpp)
endif ()

set(collision_STAT_SRCS
  ${collision_STAT_SRCS}
  ${sources_Management}
  ${sources_Maps}
  ${sources_Models}
  ${sources_localdir}
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep_tc/g3dlite/include
  ${CMAKE_SOURCE_DIR}/dep_tc/recastnavigation/Detour
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Configuration
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Database
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Dynamic
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Dynamic/LinkedReference
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Threading
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Packets
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Utilities
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/DataStores
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Addons
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Conditions
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Item
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/GameObject
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Creature
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Object
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Object/Updates
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Unit
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Combat
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Loot
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Miscellaneous
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Grids
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Grids/Cells
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Grids/Notifiers
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Maps
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/DataStores
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Movement/Waypoints
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Movement/Spline
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Movement
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Server
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Server/Protocol
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/World
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Spells
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Spells/Auras
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Management
  ${CMAKE_CURRENT_SOURCE_DIR}/Maps
  ${CMAKE_CURRENT_SOURCE_DIR}/Models
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
)

add_library(collision STATIC
  ${collision_STAT_SRCS}
  ${collision_STAT_PCH_SRC}
)

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(collision ${collision_STAT_PCH_HDR} ${collision_STAT_PCH_SRC})
endif ()