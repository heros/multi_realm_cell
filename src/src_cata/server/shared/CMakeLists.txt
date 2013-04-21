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

#if( USE_COREPCH )
#  include_directories(${CMAKE_CURRENT_BINARY_DIR})
#endif()

#fix
if (USE_COREPCH)
  set(shared_STAT_PCH_HDR PrecompiledHeaders/sharedPCH.h)
  set(shared_STAT_PCH_SRC PrecompiledHeaders/sharedPCH.cpp)
endif()

file(GLOB_RECURSE sources_Configuration Configuration/*.cpp Configuration/*.h)
file(GLOB_RECURSE sources_Cryptography Cryptography/*.cpp Cryptography/*.h)
file(GLOB_RECURSE sources_Database Database/*.cpp Database/*.h)
file(GLOB_RECURSE sources_DataStores DataStores/*.cpp DataStores/*.h)
file(GLOB_RECURSE sources_Dynamic Dynamic/*.cpp Dynamic/*.h)
file(GLOB_RECURSE sources_Logging Logging/*.cpp Logging/*.h)
file(GLOB_RECURSE sources_Packets Packets/*.cpp Packets/*.h)
file(GLOB_RECURSE sources_Threading Threading/*.cpp Threading/*.h)
file(GLOB_RECURSE sources_Utilities Utilities/*.cpp Utilities/*.h)
file(GLOB sources_localdir *.cpp *.h)

source_group(CMake FILES CMakeLists.txt)
source_group(Configuration FILES ${sources_Configuration})
source_group(PrecompiledHeaders FILES ${sources_PrecompiledHeaders})
source_group(Cryptography FILES ${sources_Cryptography})
source_group(Database FILES ${sources_Database})
source_group(Dynamic FILES ${sources_Dynamic})
source_group(Logging FILES ${sources_Logging})
source_group(Packets FILES ${sources_Packets})
source_group(Threading FILES ${sources_Threading})
source_group(Utilities FILES ${sources_Utilities})

#
# Build shared sourcelist
#


if( USE_COREPCH AND MSVC )
  set(shared_STAT_SRCS
    PrecompiledHeaders/sharedPCH.cpp
    PrecompiledHeaders/sharedPCH.h
  )
endif()

set(shared_STAT_SRCS
  ${shared_STAT_SRCS}
  ${sources_Configuration}
  ${sources_Cryptography}
  ${sources_Database}
  ${sources_DataStores}
  ${sources_Dynamic}
  ${sources_Logging}
  ${sources_Packets}
  ${sources_Threading}
  ${sources_Utilities}
  ${sources_localdir}
  Debugging/Errors.h
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep_tc/recastnavigation/Detour
  ${CMAKE_SOURCE_DIR}/dep_tc/SFMT
  ${CMAKE_SOURCE_DIR}/dep_tc/sockets/include
  ${CMAKE_SOURCE_DIR}/dep_tc/utf8cpp
  ${CMAKE_SOURCE_DIR}/src/src_cata/server
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Configuration
  ${CMAKE_CURRENT_SOURCE_DIR}/Cryptography
  ${CMAKE_CURRENT_SOURCE_DIR}/Database
  ${CMAKE_CURRENT_SOURCE_DIR}/DataStores
  ${CMAKE_CURRENT_SOURCE_DIR}/Debugging
  ${CMAKE_CURRENT_SOURCE_DIR}/Dynamic
  ${CMAKE_CURRENT_SOURCE_DIR}/Logging
  ${CMAKE_CURRENT_SOURCE_DIR}/Packets
  ${CMAKE_CURRENT_SOURCE_DIR}/Threading
  ${CMAKE_CURRENT_SOURCE_DIR}/Utilities
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/game/Entities/Object
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
)

add_library(shared STATIC
  ${shared_STAT_SRCS}
  ${shared_STAT_PCH_SRC}
)

target_link_libraries(shared
  ${ACE_LIBRARY}
)

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(shared ${shared_STAT_PCH_HDR} ${shared_STAT_PCH_SRC})
endif ()
