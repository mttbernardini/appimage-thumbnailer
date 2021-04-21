cmake_minimum_required(VERSION 3.2)
project(appimage-thumbnailer)

# standard directories
include(GNUInstallDirs)
include(KDEInstallDirs)

# setup libraries, sources and resources
add_subdirectory("lib")
add_subdirectory("src")
add_subdirectory("share")
