# required for pkg-config module's imported target feature
cmake_minimum_required(VERSION 3.6)

if(USE_SYSTEM_LIBAPPIMAGE)
	find_package(libappimage REQUIRED)
else()
	add_subdirectory(libappimage EXCLUDE_FROM_ALL)
endif()
