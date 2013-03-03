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
# Set build-directive (used in core to tell which buildtype we used)
add_definitions(-D_BUILD_DIRECTIVE="${CMAKE_BUILD_TYPE}")

if( USE_SFMT)
  if(PLATFORM EQUAL 32)
    add_definitions(-axSSE2)
  else()
    add_definitions(-xSSE2)
  endif()
  message(STATUS "ICC: SFMT enabled, SSE2 flags forced")
endif()

if( WITH_WARNINGS )
  add_definitions(-w1)
  message(STATUS "ICC All warnings enabled")
else()
  add_definitions(-w)
  message(STATUS "ICC: All warnings disabled")
endif()

if( WITH_COREDEBUG )
  add_definitions(-g)
  message(STATUS "ICC: Debug-flag set (-g)")
endif()
