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
# Already set, so only add definition
# IF(PLATFORM)
#   IF(PLATFORM MATCHES X64 AND WIN32)
#     ADD_DEFINITIONS("-D_WIN64")
#   ENDIF()
# ELSE()
  # default to x86 platform.  We'll check for X64 in a bit
  SET(PLATFORM X86)

  # This definition is necessary to work around a bug with Intellisense described
  # here: http://tinyurl.com/2cb428.  Syntax highlighting is important for proper
  # debugger functionality.

  IF(CMAKE_SIZEOF_VOID_P MATCHES 8)
      MESSAGE(STATUS "Detected 64-bit platform.")
      IF(WIN32)
        ADD_DEFINITIONS("-D_WIN64")
      ENDIF()
      SET(PLATFORM X64)
  ELSE()
      MESSAGE(STATUS "Detected 32-bit platform.")
  ENDIF()
# ENDIF()
