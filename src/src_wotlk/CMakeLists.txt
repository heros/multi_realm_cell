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

if(CMAKE_COMPILER_IS_GNUCXX)
  add_definitions(-fno-delete-null-pointer-checks)
endif()

if( SERVERS )
  set(sources_Debugging
    ${CMAKE_SOURCE_DIR}/src/shared/Debugging/WheatyExceptionReport.cpp
    ${CMAKE_SOURCE_DIR}/src/shared/Debugging/WheatyExceptionReport.h
  )
#  add_subdirectory(shared)
#  add_subdirectory(game)
#  add_subdirectory(collision)
#  add_subdirectory(authserver)
#  add_subdirectory(scripts)
#  add_subdirectory(worldserver)


else()
  if( TOOLS )
    add_subdirectory(collision)
    add_subdirectory(shared)
  endif()
endif()
