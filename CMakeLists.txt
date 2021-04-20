cmake_minimum_required(VERSION 3.6)
project(appimage-thumbnailer VERSION 0.1.1)

# used by Debian packaging infrastructure
include(GNUInstallDirs)

add_subdirectory("lib")
add_subdirectory("src")
add_subdirectory("data")
