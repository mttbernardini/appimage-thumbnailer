# required for pkg-config module's imported target feature
cmake_minimum_required(VERSION 3.6)

if(NOT USE_SYSTEM_LIBAPPIMAGE)
	add_subdirectory(libappimage EXCLUDE_FROM_ALL)
endif()
