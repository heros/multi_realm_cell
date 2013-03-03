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
# find Readline (terminal input library) includes and library
#
# READLINE_INCLUDE_DIR - where the directory containing the READLINE headers can be found
# READLINE_LIBRARY     - full path to the READLINE library
# READLINE_FOUND       - TRUE if READLINE was found

MACRO(FIND_READLINE)

FIND_PATH(READLINE_INCLUDE_DIR readline/readline.h)
FIND_LIBRARY(READLINE_LIBRARY NAMES readline)

IF (READLINE_INCLUDE_DIR AND READLINE_LIBRARY)
    SET(READLINE_FOUND TRUE)
    MESSAGE(STATUS "Found Readline library: ${READLINE_LIBRARY}")
    MESSAGE(STATUS "Include dir is: ${READLINE_INCLUDE_DIR}")
    INCLUDE_DIRECTORIES(${READLINE_INCLUDE_DIR})
ELSE (READLINE_INCLUDE_DIR AND READLINE_LIBRARY)
    SET(READLINE_FOUND FALSE)
    MESSAGE(FATAL_ERROR "** Readline library not found!\n** Your distro may provide a binary for Readline e.g. for ubuntu try apt-get install libreadline5-dev")
ENDIF (READLINE_INCLUDE_DIR AND READLINE_LIBRARY)

ENDMACRO(FIND_READLINE)
