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

# Specify tbb lib that was build externally
# add_library(tbb SHARED IMPORTED)
# add_library(tbbmalloc SHARED IMPORTED)
if(WIN32)
  set(LIB_SUFFIX dll)
  if(VS100_FOUND)
    set(VSDIR vs100project)
  else()
    set(VSDIR vsproject)
  endif()
  if(PLATFORM MATCHES X86)
    set(ARCHDIR ia32)
  else()
    set(ARCHDIR intel64)
  endif()
#   set_target_properties(tbb PROPERTIES
#     IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/dep/tbb/build/${VSDIR}/${ARCHDIR}/Release/tbb.dll
#     IMPORTED_LOCATION_DEBUG ${CMAKE_SOURCE_DIR}/dep/tbb/build/${VSDIR}/${ARCHDIR}/Debug/tbb_debug.dll
#     IMPORTED_IMPLIB_RELEASE ${CMAKE_SOURCE_DIR}/dep/tbb/build/${VSDIR}/${ARCHDIR}/Release/tbb.lib
#     IMPORTED_IMPLIB_DEBUG ${CMAKE_SOURCE_DIR}/dep/tbb/build/${VSDIR}/${ARCHDIR}/Debug/tbb_debug.lib
#   )
#   set_target_properties(tbbmalloc PROPERTIES
#     IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/dep/tbb/build/${VSDIR}/${ARCHDIR}/Release/tbbmalloc.dll
#     IMPORTED_LOCATION_DEBUG ${CMAKE_SOURCE_DIR}/dep/tbb/build/${VSDIR}/${ARCHDIR}/Debug/tbbmalloc_debug.dll
#     IMPORTED_IMPLIB_RELEASE ${CMAKE_SOURCE_DIR}/dep/tbb/build/${VSDIR}/${ARCHDIR}/Release/tbbmalloc.lib
#     IMPORTED_IMPLIB_DEBUG ${CMAKE_SOURCE_DIR}/dep/tbb/build/${VSDIR}/${ARCHDIR}/Debug/tbbmalloc_debug.lib
#   )
  set(TBB_LIBRARIES_DIR
    ${CMAKE_SOURCE_DIR}/dep/tbb/build/${VSDIR}/${ARCHDIR}/Release
    ${CMAKE_SOURCE_DIR}/dep/tbb/build/${VSDIR}/${ARCHDIR}/Debug
  )
else()
  if(APPLE)
    set(LIB_SUFFIX dylib)
  else()
    set(LIB_SUFFIX so)
  endif()
#   set_target_properties(tbb PROPERTIES
#     IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/dep/tbb/build/libs_release/libtbb.${LIB_SUFFIX}
#     IMPORTED_LOCATION_DEBUG ${CMAKE_SOURCE_DIR}/dep/tbb/build/libs_debug/libtbb_debug.${LIB_SUFFIX}
#   )
#   set_target_properties(tbbmalloc PROPERTIES
#     IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/dep/tbb/build/libs_release/libtbbmalloc.${LIB_SUFFIX}
#     IMPORTED_LOCATION_DEBUG ${CMAKE_SOURCE_DIR}/dep/tbb/build/libs_debug/libtbbmalloc_debug.${LIB_SUFFIX}
#   )
  set(TBB_LIBRARIES_DIR
    ${CMAKE_SOURCE_DIR}/dep/tbb/build/libs_release
    ${CMAKE_SOURCE_DIR}/dep/tbb/build/libs_debug
  )
endif()
# Sadly doesn't work in current version
# add_dependencies(tbb TBB_Project)
# add_dependencies(tbbmalloc TBB_Project)
# set_target_properties(tbb PROPERTIES DEPENDS TBB_Project)
# set_target_properties(tbbmalloc PROPERTIES DEPENDS TBB_Project)

set(TBB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/dep/tbb/include)
set(TBB_LIBRARIES optimized tbb optimized tbbmalloc debug tbb_debug debug tbbmalloc_debug)

# Little Hack to remove the link warnings because of not found directories
if(XCODE)
  foreach(DIR ${TBB_LIBRARIES_DIR})
    foreach(CONF ${CMAKE_CONFIGURATION_TYPES})
      file(MAKE_DIRECTORY ${DIR}/${CONF})
    endforeach(CONF)
  endforeach(DIR)
  foreach(CONF ${CMAKE_CONFIGURATION_TYPES})
    set(CONFSTR ${CONFSTR} PATTERN "${CONF}" EXCLUDE)
  endforeach(CONF)
endif()

link_directories(
  ${TBB_LIBRARIES_DIR}
)

foreach(DIR ${TBB_LIBRARIES_DIR})
  install(
    DIRECTORY ${DIR}/ DESTINATION ${LIBS_DIR}
    FILES_MATCHING PATTERN "*.${LIB_SUFFIX}*"
    ${CONFSTR}
  )
endforeach(DIR)
