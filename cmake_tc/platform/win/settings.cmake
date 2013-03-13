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
# Platform-specfic options
option(USE_MYSQL_SOURCES "Use included MySQL-sources to build libraries" 1)

# Package overloads
set(ACE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/dep_tc/acelite)
set(ACE_LIBRARY "ace")
set(BZIP2_LIBRARIES "bzip2")
set(ZLIB_LIBRARIES "zlib")

if( USE_MYSQL_SOURCES )
  set(MYSQL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/dep_tc/mysqllite/include)
  set(MYSQL_LIBRARY "libmysql")
  set( MYSQL_FOUND 1 )
  message(STATUS "Using supplied MySQL sources")
endif()

# check the CMake preload parameters (commented out by default)

# overload CMAKE_INSTALL_PREFIX if not being set properly
#if( WIN32 )
#  if( NOT CYGWIN )
#    if( NOT CMAKE_INSTALL_PREFIX )
#      set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/bin")
#    endif()
#  endif()
#endif()

if ( MSVC )
  include(${CMAKE_SOURCE_DIR}/cmake_tc/compiler/msvc/settings.cmake)
elseif ( MINGW )
  include(${CMAKE_SOURCE_DIR}/cmake_tc/compiler/mingw/settings.cmake)
endif()
