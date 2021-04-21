# required for pkg-config module's imported target feature
cmake_minimum_required(VERSION 3.6)

find_package(PkgConfig REQUIRED)

# if there's a system libappimage package on the system, we can use that directly
set(USE_SYSTEM_LIBAPPIMAGE OFF CACHE BOOL "")

if(USE_SYSTEM_LIBAPPIMAGE)
	find_package(libappimage REQUIRED)
else()
	add_subdirectory(libappimage EXCLUDE_FROM_ALL)
endif()

# setup gnome dependencies

# setup kde dependencies
find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS Gui)
find_package(KF5 REQUIRED COMPONENTS KIO)
