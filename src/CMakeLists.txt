set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_compile_options(-Wall -Wpedantic)

# icon extractor
add_library(appimage-icon-extract STATIC "appimage-icon-extract.c")
target_link_libraries(appimage-icon-extract PUBLIC libappimage)

# gnome thumbnailer
add_executable(gnome-appimage-thumbnailer "gnome-appimage-thumbnailer.c")
target_link_libraries(gnome-appimage-thumbnailer PRIVATE appimage-icon-extract)
install(TARGETS gnome-appimage-thumbnailer EXPORT appimage-thumbnailer RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# kde thumbnailer
add_library(kde-appimage-thumbnailer MODULE "kde-appimage-thumbnailer.cpp")
target_link_libraries(kde-appimage-thumbnailer KF5::KIOWidgets)
install(TARGETS kde-appimage-thumbnailer DESTINATION ${KDE_INSTALL_PLUGINDIR})
