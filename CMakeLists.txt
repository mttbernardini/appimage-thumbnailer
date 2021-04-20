cmake_minimum_required(VERSION 3.2)
project(appimage-thumbnailer)

# used by Debian packaging infrastructure
include(GNUInstallDirs)

# if there's a system libappimage package on the system, we can use that directly
set(USE_SYSTEM_LIBAPPIMAGE OFF CACHE BOOL "")

add_subdirectory("lib")
add_subdirectory("src")
add_subdirectory("share")
