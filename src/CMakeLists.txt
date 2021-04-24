set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_compile_options(-Wall -Wpedantic)

# icon extractor
add_library(appimage-icon-extract STATIC "appimage-icon-extract.c")
target_link_libraries(appimage-icon-extract libappimage)

# gnome thumbnailer
add_executable(gnome-appimage-thumbnailer "gnome-appimage-thumbnailer.c")
target_link_libraries(gnome-appimage-thumbnailer appimage-icon-extract)
set_target_properties(gnome-appimage-thumbnailer PROPERTIES OUTPUT_NAME "appimage-thumbnailer")
install(TARGETS gnome-appimage-thumbnailer
	DESTINATION ${CMAKE_INSTALL_BINDIR}
	COMPONENT appimage-thumbnailer-gnome
	EXCLUDE_FROM_ALL
)

# kde thumbnailer
add_library(kde-appimage-thumbnailer MODULE "kde-appimage-thumbnailer.cpp")
target_link_libraries(kde-appimage-thumbnailer Qt5::Core KF5::KIOWidgets appimage-icon-extract )
set_target_properties(kde-appimage-thumbnailer PROPERTIES OUTPUT_NAME "appimage-thumbnailer")
install(TARGETS kde-appimage-thumbnailer
	DESTINATION ${KDE_INSTALL_PLUGINDIR}
	COMPONENT appimage-thumbnailer-kde
	EXCLUDE_FROM_ALL
)
