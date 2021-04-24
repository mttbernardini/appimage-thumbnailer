set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_DEBIAN_COMPRESSION_TYPE xz)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_DEBIAN_PACKAGE_DEPENDS "shared-mime-info") # provides appimage mime type
set(CPACK_DEBIAN_PACKAGE_SUGGESTS "appimagelauncher")

# gnome thumbnailer
set(CPACK_DEBIAN_APPIMAGE-THUMBNAILER-GNOME_PACKAGE_NAME "gnome-appimage-thumbnailer")

# kde thumbnailer
set(CPACK_DEBIAN_APPIMAGE-THUMBNAILER-KDE_PACKAGE_NAME "kde-appimage-thumbnailer")
