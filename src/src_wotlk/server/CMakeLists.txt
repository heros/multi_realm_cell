# Copyright (C) Likan Mod 2012-2013 <https://github.com/ChaosDevLikan/>
# Copyright (C) 3server 2005-2013 <https://cata.3server>
# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Enforce compileparameters for corebuilds under GCC
# This to stop a few silly crashes that could have been avoided IF people
# weren't doing some -O3 psychooptimizations etc.

#if(CMAKE_COMPILER_IS_GNUCXX)
#  add_definitions(-fno-delete-null-pointer-checks)
#endif()

#if( SERVERS )
#  set(sources_Debugging
#    ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Debugging/WheatyExceptionReport.cpp
#    ${CMAKE_SOURCE_DIR}/src/src_wotlk/server/shared/Debugging/WheatyExceptionReport.h
#  )
#  add_subdirectory(shared)
#  add_subdirectory(game)
#  add_subdirectory(collision)
#  add_subdirectory(authserver)
#  add_subdirectory(scripts)
#  add_subdirectory(worldserver)
#else()
#  if( TOOLS )
#    add_subdirectory(collision)
#  endif()
#endif()
