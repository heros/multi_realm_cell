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

file(GLOB_RECURSE sources_authentication Authentication/*.cpp Authentication/*.h)
file(GLOB_RECURSE sources_PrecompiledHeaders PrecompiledHeaders/*.cpp PrecompiledHeaders/*.h)
file(GLOB_RECURSE sources_realms Realms/*.cpp Realms/*.h)
file(GLOB_RECURSE sources_server Server/*.cpp Server/*.h)
file(GLOB sources_localdir *.cpp *.h)

source_group(CMake FILES CMakeLists.txt)
source_group(Authentication FILES ${sources_Authentication})
source_group(PrecompiledHeaders FILES ${sources_PrecompiledHeaders})
source_group(Realms FILES ${sources_Realms})
source_group(Server FILES ${sources_Server})

if (USE_COREPCH)
  set(authserver_PCH_HDR PrecompiledHeaders/authPCH.h)
  set(authserver_PCH_SRC PrecompiledHeaders/authPCH.cpp)
endif()

set(authserver_SRCS
  ${authserver_SRCS}
  ${sources_authentication}
  ${sources_realms}
  ${sources_server}
  ${sources_localdir}
)

if( WIN32 )
  if ( MSVC )
    set(authserver_SRCS
      ${authserver_SRCS}
      ${sources_Debugging}
    authserver.rc
    )
  else ( )
    set(authserver_SRCS
      ${authserver_SRCS}
      ${sources_Debugging}
    )
  endif ()
endif()

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Database
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Packets
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Cryptography
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Cryptography/Authentication
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Threading
  ${CMAKE_SOURCE_DIR}/src/src_cata/server/shared/Utilities
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Authentication
  ${CMAKE_CURRENT_SOURCE_DIR}/Realms
  ${CMAKE_CURRENT_SOURCE_DIR}/Server
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
)

 add_executable(authserver
  ${authserver_SRCS}
  ${authserver_PCH_SRC}
)

add_dependencies(authserver revision.h)

if( NOT WIN32 )
  set_target_properties(authserver PROPERTIES
    COMPILE_DEFINITIONS _TRINITY_REALM_CONFIG="${CONF_DIR}/authserver.conf"
  )
endif()

target_link_libraries(authserver
  shared
  ${MYSQL_LIBRARY}
  ${OPENSSL_LIBRARIES}
)

if( WIN32 )
  if ( MSVC )
    add_custom_command(TARGET authserver
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/authserver.conf.dist ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/
    )
  elseif ( MINGW )
    add_custom_command(TARGET authserver
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/authserver.conf.dist ${CMAKE_BINARY_DIR}/bin/
    )
  endif()
endif()

if( UNIX )
  install(TARGETS authserver DESTINATION bin)
  install(FILES  authserver.conf.dist DESTINATION etc)
elseif( WIN32 )
  install(TARGETS authserver DESTINATION "${CMAKE_INSTALL_PREFIX}")
  install(FILES authserver.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()

#fix
# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(authserver ${authserver_PCH_HDR} ${authserver_PCH_SRC})
endif()

#if( USE_COREPCH )
#  if(CMAKE_COMPILER_IS_GNUCXX)
#    add_precompiled_header(authserver ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/authPCH.h)
#  elseif(MSVC)
#    add_native_precompiled_header(authserver ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/authPCH)
#  endif()
#endif()