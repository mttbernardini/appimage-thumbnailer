cmake_minimum_required(VERSION 3.6)
project(appimage-thumbnailer VERSION 0.1.1)

option(USE_SYSTEM_LIBAPPIMAGE "link againts system provided libappimage instead of bundled one")

# == setup dependencies ==
find_package(PkgConfig REQUIRED)

# system libappimage
if(USE_SYSTEM_LIBAPPIMAGE)
	find_package(libappimage REQUIRED)
endif()

# gnome dependencies
include(GNUInstallDirs)

add_subdirectory("lib")
add_subdirectory("src")
add_subdirectory("data")
