cmake_minimum_required(VERSION 3.19)
project(altv_go)

##
# global settings
##

set(PROJECT_MODULE_NAME "altv_go")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ALTV_SDK_ROOT ${CMAKE_SOURCE_DIR}/vendor/sdk)
set(ZPL_ROOT ${CMAKE_SOURCE_DIR}/vendor/zpl)

if(UNIX)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/linux64/${CMAKE_BUILD_TYPE})
	add_definitions(-DLINUX)
else()
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/win64/${CMAKE_BUILD_TYPE})
	add_definitions(-DWIN32)
endif()

if (WIN32 AND NOT MINGW)
	add_compile_options(/MT)
else()
	add_compile_options(-m64)
endif()

##
# go module
##
add_library(${PROJECT_MODULE_NAME} SHARED source/main.cpp source/main.hpp source/runtime.cpp source/runtime.hpp source/resource.cpp source/resource.hpp source/log.hpp)

target_include_directories(${PROJECT_MODULE_NAME} PRIVATE
		${ALTV_SDK_ROOT}
		${ZPL_ROOT}/code
)

target_compile_definitions(${PROJECT_MODULE_NAME} PRIVATE
		-DALT_SERVER_API
		-D_CRT_SECURE_NO_WARNINGS
		-DWIN32_LEAN_AND_MEAN
		-DZPL_NANO
		-DZPL_ENABLE_DLL
		-DMODULE_NAME="${PROJECT_MODULE_NAME}"
)