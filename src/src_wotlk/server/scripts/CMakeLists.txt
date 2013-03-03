# Copyright (C) Likan Mod 2012-2013 <https://github.com/ChaosDevLikan/>
# Copyright (C) 3server 2005-2013 <https://cata.3server>

if( USE_SCRIPTPCH )
  include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
  )
endif()

file(GLOB_RECURSE sources_Bots Bots/*.cpp Bots/*.h)
file(GLOB_RECURSE sources_Mody Mody/*.cpp Mody/*.h)
file(GLOB_RECURSE sources_PrecompiledHeaders PrecompiledHeaders/*.cpp PrecompiledHeaders/*.h)
file(GLOB_RECURSE sources_Custom Custom/*.cpp Custom/*.h)
#file(GLOB_RECURSE sources_EasternKingdoms EasternKingdoms/*.cpp EasternKingdoms/*.h)
#file(GLOB_RECURSE sources_Kalimdor Kalimdor/*.cpp Kalimdor/*.h)
#file(GLOB_RECURSE sources_Outland Outland/*.cpp Outland/*.h)
#file(GLOB_RECURSE sources_Northrend Northrend/*.cpp Northrend/*.h)

file(GLOB_RECURSE sources_Commands Commands/*.cpp Commands/*.h)
file(GLOB_RECURSE sources_Examples Examples/*.cpp Examples/*.h)
file(GLOB_RECURSE sources_OutdoorPvP OutdoorPvP/*.cpp OutdoorPvP/*.h)
file(GLOB_RECURSE sources_Spells Spells/*.cpp Spells/*.h)
file(GLOB_RECURSE sources_World World/*.cpp World/*.h)

source_group(CMake FILES CMakeLists.txt)
source_group(Bots FILES ${sources_Bots})
source_group(Mody FILES ${sources_Mody})
source_group(PrecompiledHeaders FILES ${sources_PrecompiledHeaders})
source_group(Custom FILES ${sources_Custom})
#source_group(EasternKingdoms FILES ${sources_EasternKingdoms})
#source_group(Kalimdor FILES ${sources_Kalimdor})
#source_group(Outland FILES ${sources_Outland})
#source_group(Northrend FILES ${sources_Northrend})

source_group(OutdoorPvP FILES ${sources_OutdoorPvP})
source_group(Commands FILES ${sources_Commands})
source_group(Examples FILES ${sources_Examples})
source_group(Spells FILES ${sources_Spells})
source_group(World FILES ${sources_World})

if( USE_SCRIPTPCH AND MSVC )
  set(scripts_STAT_src/src_wotlkS
    PrecompiledHeaders/ScriptPCH.cpp
    PrecompiledHeaders/ScriptPCH.h
  )
endif()

message(STATUS "SCRIPT PREPARATIONS")
include(Spells/CMakeLists.txt)

include(Commands/CMakeLists.txt)

include(Examples/CMakeLists.txt)

set(scripts_STAT_srcS
  ${scripts_STAT_srcS}
  ../game/AI/ScriptedAI/sc_npc_teleport.cpp
  ../game/AI/ScriptedAI/sc_npc_teleport.h
  ../game/AI/ScriptedAI/ScriptedEscortAI.cpp
  ../game/AI/ScriptedAI/ScriptedCreature.cpp
  ../game/AI/ScriptedAI/ScriptedFollowerAI.cpp
  ../game/AI/ScriptedAI/ScriptedGuardAI.cpp
  ../game/AI/ScriptedAI/ScriptedSimpleAI.cpp
)

if(SCRIPTS)
  include(Custom/CMakeLists.txt)
  include(Bots/CMakeLists.txt)
  include(World/CMakeLists.txt)
  include(OutdoorPvP/CMakeLists.txt)
  include(Mody/CMakeLists.txt)
endif()

message(STATUS "SCRIPT PREPARATION COMPLETE")
message("")

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep_tc/SFMT
  ${CMAKE_SOURCE_DIR}/dep_tc/mersennetwister
  ${CMAKE_SOURCE_DIR}/dep_tc/zlib
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/src/src_wotlk_wotlk/server/shared
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/src/src_wotlk_wotlk/server/shared/Configuration
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Cryptography
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Database
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/DataStores
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Dynamic/CountedReference
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Dynamic/LinkedReference
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Dynamic
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Packets
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Policies
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Threading
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Utilities
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/collision
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/collision/Management
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Database
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Accounts
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Achievements
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Addons
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/AI
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/AI/CoreAI
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/AI/EventAI
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/AI/ScriptedAI
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/AI/SmartScripts
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/AuctionHouse
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Battlegrounds
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Battlegrounds/Zones
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Calendar
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Chat
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Chat/Channels
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Conditions
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Configuration
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Combat
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/DataStores
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/DungeonFinding
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Entities/Corpse
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Entities/Creature
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Entities/DynamicObject
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Entities/Item
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Entities/Item/Container
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Entities/GameObject
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Entities/Object
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Entities/Object/Updates
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Entities/Pet
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Entities/Player
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Entities/Transport
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Entities/Unit
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Entities/Vehicle
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Events
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Globals
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Grids
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Grids/Cells
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Grids/Notifiers
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Groups
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Guilds
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Instances
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/LookingForGroup
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Loot
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Mails
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Miscellaneous
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Maps
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Movement
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Movement/MovementGenerators
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Movement/Waypoints
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Opcodes
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/OutdoorPvP
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Pools
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/PrecompiledHeaders
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Quests
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Reputation
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Scripting
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Server
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Server/Protocol
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Server/Protocol/Handlers
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Skills
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Spells
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Spells/Auras
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Texts
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Tickets
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Tools
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/Weather
  ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/game/World
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
)

add_library(scripts STATIC ${scripts_STAT_SRCS})

add_dependencies(scripts revision.h)

# Generate precompiled header
if( USE_SCRIPTPCH )
  if(CMAKE_COMPILER_IS_GNUCXX)
    add_precompiled_header(scripts ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/ScriptPCH.h)
  elseif(MSVC)
    add_native_precompiled_header(scripts ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/ScriptPCH)
  endif()
endif()
