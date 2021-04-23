cmake_minimum_required(VERSION 3.6)
project(appimage-thumbnailer)

option(USE_SYSTEM_LIBAPPIMAGE "link againts system provided libappimage instead of bundled one")

# == setup dependencies ==
find_package(PkgConfig REQUIRED)

# system libappimage
if(USE_SYSTEM_LIBAPPIMAGE)
	find_package(libappimage REQUIRED)
endif()

# gnome dependencies
include(GNUInstallDirs)

# kde dependencies
find_package(ECM 1.0.0 REQUIRED NO_MODULE) # needed to be able to find KF5 below
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})
include(KDEInstallDirs)
find_package(Qt5 CONFIG REQUIRED COMPONENTS Core)
find_package(KF5 REQUIRED COMPONENTS KIO)


# == setup sub-dirs ==
add_subdirectory("lib")
add_subdirectory("src")
add_subdirectory("share")
