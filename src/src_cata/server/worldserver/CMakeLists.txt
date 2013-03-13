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

if( USE_SCRIPTPCH )
  include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
  )
endif()

file(GLOB_RECURSE sources_CommandLine CommandLine/*.cpp CommandLine/*.h)
file(GLOB_RECURSE sources_PrecompiledHeaders PrecompiledHeaders/*.cpp PrecompiledHeaders/*.h)
file(GLOB_RECURSE sources_RemoteAccess RemoteAccess/*.cpp RemoteAccess/*.h)
file(GLOB_RECURSE sources_TCSoap TCSoap/*.cpp TCSoap/*.h)
file(GLOB_RECURSE sources_WorldThread WorldThread/*.cpp WorldThread/*.h)
file(GLOB sources_localdir *.cpp *.h)

source_group(CMake FILES CMakeLists.txt)

source_group(CommandLine FILES ${sources_CommandLine})
source_group(PrecompiledHeaders FILES ${sources_PrecompiledHeaders})
source_group(RemoteAccess FILES ${sources_RemoteAccess})
source_group(TCSoap FILES ${sources_TCSoap})
source_group(WorldThread FILES ${sources_WorldThread})

if (USE_COREPCH)
  set(worldserver_PCH_HDR PrecompiledHeaders/worldPCH.h)
  set(worldserver_PCH_SRC PrecompiledHeaders/worldPCH.cpp)
endif()

set(worldserver_SRCS
  ${worldserver_SRCS}
  ${sources_CommandLine}
  ${sources_RemoteAccess}
  ${sources_TCSoap}
  ${sources_WorldThread}
  ${sources_localdir}
)

if( WIN32 )
  if ( MSVC )
    set(worldserver_SRCS
      ${worldserver_SRCS}
      ${sources_Debugging}
      worldserver.rc
    )
  else ( )
    set(worldserver_SRCS
      ${worldserver_SRCS}
      ${sources_Debugging}
    )
  endif ()
endif()

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep_tc/g3dlite/include
  ${CMAKE_SOURCE_DIR}/dep_tc/recastnavigation/Detour
  ${CMAKE_SOURCE_DIR}/dep_tc/gsoap
  ${CMAKE_SOURCE_DIR}/dep_tc/sockets/include
  ${CMAKE_SOURCE_DIR}/dep_tc/SFMT
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/collision
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/collision/Management
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/collision/Models
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Configuration
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Cryptography
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Cryptography/Authentication
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Database
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/DataStores
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Dynamic/LinkedReference
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Dynamic
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Packets
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Threading
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Utilities
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Accounts
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Achievements
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Addons
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/AI
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/AI/CoreAI
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/AI/ScriptedAI
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/AI/SmartScripts
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/AuctionHouse
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/AuctionHouse/AuctionHouseBot
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Battlegrounds
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Battlegrounds/Zones
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Calendar
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Chat
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Chat/Channels
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Combat
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Conditions
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/DataStores
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/DungeonFinding
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Creature
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Corpse
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/DynamicObject
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/GameObject
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Item
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Item/Container
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Object
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Object/Updates
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Pet
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Player
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Totem
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Unit
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Vehicle
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Transport
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Events
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Globals
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Grids/Cells
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Grids/Notifiers
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Grids
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Groups
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Guilds
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Handlers
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Instances
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Loot
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Mails
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Maps
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Miscellaneous
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Movement
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Movement/MovementGenerators
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Movement/Waypoints
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/OutdoorPvP
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Pools
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/PrecompiledHeaders
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Quests
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Reputation
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Scripting
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Server/Protocol
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Server
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Skills
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Spells
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Spells/Auras
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Tools
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Warden
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Warden/Modules
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Weather
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/World
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/authserver/Server
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/authserver/Realms
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/CommandLine
  ${CMAKE_CURRENT_SOURCE_DIR}/RemoteAccess
  ${CMAKE_CURRENT_SOURCE_DIR}/TCSoap
  ${CMAKE_CURRENT_SOURCE_DIR}/WorldThread
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
)

add_executable(worldserver
  ${worldserver_SRCS}
  ${worldserver_PCH_SRC}
)

if( NOT WIN32 )
  set_target_properties(worldserver PROPERTIES
    COMPILE_DEFINITIONS _TRINITY_CORE_CONFIG="${CONF_DIR}/worldserver.conf"
  )
endif()

add_dependencies(worldserver revision.h)

if( UNIX AND NOT NOJEM )
  set(worldserver_LINK_FLAGS "-pthread -lncurses ${worldserver_LINK_FLAGS}")
endif()

set_target_properties(worldserver PROPERTIES LINK_FLAGS "${worldserver_LINK_FLAGS}")

target_link_libraries(worldserver
  game
  shared
  scripts
  collision
  g3dlib
  gsoap
  Detour
  ${JEMALLOC_LIBRARY}
  ${READLINE_LIBRARY}
  ${TERMCAP_LIBRARY}
  ${ACE_LIBRARY}
  ${MYSQL_LIBRARY}
  ${OPENSSL_LIBRARIES}
  ${ZLIB_LIBRARIES}
)

if( WIN32 )
  if ( MSVC )
    add_custom_command(TARGET worldserver
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/worldserver.conf.dist ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/
    )
  elseif ( MINGW )
    add_custom_command(TARGET worldserver
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/worldserver.conf.dist ${CMAKE_BINARY_DIR}/bin/
    )
  endif()
endif()

if( UNIX )
  install(TARGETS worldserver DESTINATION bin)
  install(FILES worldserver.conf.dist DESTINATION etc)
elseif( WIN32 )
  install(TARGETS worldserver DESTINATION "${CMAKE_INSTALL_PREFIX}")
  install(FILES worldserver.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()


# Generate precompiled header
if( USE_COREPCH )
  add_cxx_pch(worldserver ${worldserver_PCH_HDR} ${worldserver_PCH_SRC})
endif()

#if( USE_COREPCH )
#  if(CMAKE_COMPILER_IS_GNUCXX)
#    add_precompiled_header(worldserver ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/worldPCH.h)
#  elseif(MSVC)
#    add_native_precompiled_header(worldserver ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/worldPCH)
#  endif()
#endif()