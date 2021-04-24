set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_DEBIAN_COMPRESSION_TYPE xz)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_DEBIAN_PACKAGE_PROVIDES "appimage-mimetype") # in the future it might be better to have a unified mime provider as a separate package
set(CPACK_DEBIAN_PACKAGE_SUGGESTS "appimagelauncher")

# gnome thumbnailer
set(CPACK_DEBIAN_APPIMAGE-THUMBNAILER-GNOME_PACKAGE_NAME "gnome-appimage-thumbnailer")
#set(CPACK_DEBIAN_APPIMAGE-THUMBNAILER-GNOME_PACKAGE_DEPENDS "libgdk-pixbuf-2.0-0")

# kde thumbnailer
set(CPACK_DEBIAN_APPIMAGE-THUMBNAILER-KDE_PACKAGE_NAME "kde-appimage-thumbnailer")
#set(CPACK_DEBIAN_APPIMAGE-THUMBNAILER-KDE_PACKAGE_DEPENDS "libkf5kiocore5 libqt5core5a")
