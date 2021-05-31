cmake_minimum_required(VERSION 3.19)
project(altv_v)

set(PROJECT_MODULE_NAME "altv_v")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ALTV_SDK_ROOT ${CMAKE_SOURCE_DIR}/vendor/sdk)
set(ZPL_ROOT ${CMAKE_SOURCE_DIR}/vendor/zpl)

if(UNIX)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/linux64/${CMAKE_BUILD_TYPE})
else()
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/win64/${CMAKE_BUILD_TYPE})
endif()

add_library(altv_v SHARED source/main.cpp source/main.hpp source/runtime.cpp source/runtime.hpp source/resource.cpp source/resource.hpp source/log.hpp)

target_include_directories(altv_v PRIVATE
		${ALTV_SDK_ROOT}
		${ZPL_ROOT}/code
)

target_compile_definitions(altv_v PRIVATE
		-DALT_SERVER_API
		-D_CRT_SECURE_NO_WARNINGS
		-DWIN32_LEAN_AND_MEAN
		-DMODULE_NAME="${PROJECT_MODULE_NAME}"
)

if(MSVC)
	target_compile_options(altv_v PRIVATE
			/MD
	)
else()
	target_compile_options(altv_v PRIVATE
			-m64
	)
endif()