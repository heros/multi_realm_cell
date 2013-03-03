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
# This module defines
# VS_DEVENV, path to devenv.com.

FIND_PATH(VS100_DIR devenv.com
  $ENV{VS100COMNTOOLS}/../IDE
  "C:\\Program Files (x86)\\Microsoft Visual Studio 10.0\\Common7\\IDE"
  "C:\\Program Files\\Microsoft Visual Studio 10.0\\Common7\\IDE"
  "C:\\Programme\\Microsoft Visual Studio 10.0\\Common7\\IDE"
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Wow6432Node\\Microsoft\\VisualStudio\\10.0\\Setup\\VS;EnvironmentDirectory]"
)

SET(VS100_FOUND 0)
IF(VS100_DIR)
  SET(VS100_FOUND 1)
  MESSAGE(STATUS "Found Visual Studion 2010")
ENDIF(VS100_DIR)

MARK_AS_ADVANCED(
  VS100_DIR
)
