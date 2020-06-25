IF(WIN32)
SET(TOOLCHAIN_DIR "C:/MinGW")
SET(ENV{PATH} "${TOOLCHAIN_DIR}/bin;$ENV{PATH}")
SET(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_DIR})
SET(CMAKE_C_COMPILER ${TOOLCHAIN_DIR}/bin/gcc.exe)
SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/g++.exe)
ENDIF()

MACRO(source_group_by_dir source_files)
    SET(sgbd_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
    FOREACH(sgbd_file ${${source_files}})
        STRING(REGEX REPLACE ${sgbd_cur_dir}/\(.*\) \\1 sgbd_fpath ${sgbd_file})
        STRING(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
        STRING(COMPARE EQUAL ${sgbd_fpath} $(sgbd_group_name) sgbd_nogroup)
            IF(MSVC)
                string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
            ENDIF(MSVC)
            IF(sgbd_nogroup)
                SET(sgbd_group_name "\\")
            ENDIF(sgbd_nogroup)
        SOURCE_GROUP(${sgbd_group_name} FILES ${sgbd_file})
    ENDFOREACH(sgbd_file)
ENDMACRO(source_group_by_dir)


CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(uAircraft)

SET(CMAKE_C_FLAGS "-std=c99 -O0 -g3 -Wall -fmessage-length=0")
SET(CMAKE_CXX_FLAGS "-std=c++11 -O0 -g3 -Wall -fmessage-length=0")

SET(CMAKE_VERBOSE_MAKEFILE OFF)

INCLUDE_DIRECTORIES(
    "include"
    "test"
    "lib"
)

FILE(GLOB_RECURSE all_files
src/*.cpp
src/*.cc
src/*.c
src/*.C
test/*.cpp
test/*.cc
test/*.c
test/*.C
)

source_group_by_dir(all_files)
LINK_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/tools/lib")
ADD_EXECUTABLE(${PROJECT_NAME} ${all_files})

IF(WIN32)
#TARGET_LINK_LIBRARIES(${PROJECT_NAME} libgtest.a libmockcpp32.a pthread)
ENDIF()