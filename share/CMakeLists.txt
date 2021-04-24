# == gnome thumbnailer ==
install(
	FILES mime/packages/appimage.xml
	DESTINATION ${CMAKE_INSTALL_DATADIR}/mime/packages/
	COMPONENT appimage-thumbnailer-gnome
	RENAME gnome-appimage-thumbnailer.xml
	EXCLUDE_FROM_ALL
)
install(
	FILES thumbnailers/appimage-thumbnailer.thumbnailer
	DESTINATION ${CMAKE_INSTALL_DATADIR}/thumbnailers/
	COMPONENT appimage-thumbnailer-gnome
	EXCLUDE_FROM_ALL
)

# == kde thumbnailer ==
install(
	FILES mime/packages/appimage.xml
	DESTINATION ${CMAKE_INSTALL_DATADIR}/mime/packages/
	COMPONENT appimage-thumbnailer-kde
	RENAME kde-appimage-thumbnailer.xml
	EXCLUDE_FROM_ALL
)
install(
	FILES kservices5/appimage-thumbnailer.desktop
	DESTINATION ${SERVICES_INSTALL_DIR}
	COMPONENT appimage-thumbnailer-kde
	EXCLUDE_FROM_ALL
)
