add_executable(gnome-appimage-thumbnailer "gnome-appimage-thumbnailer.c")
#add_library(kde-appimage-thumbnailer MODULE "kde-appimage-thumbnailer.cpp")
#target_link_libraries(kde-appimage-thumbnailer Qt5::Gui KF5::KIOWidgets KF5::KDcraw KF5::KExiv2)

install(TARGETS gnome-appimage-thumbnailer DESTINATION ${BINARY_DIR})
#install(TARGETS kde-appimage-thumbnailer DESTINATION ${KDE_INSTALL_PLUGINDIR})
