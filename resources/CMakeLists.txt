# == gnome thumbnailer ==
install(
	FILES appimage-thumbnailer.thumbnailer
	DESTINATION ${CMAKE_INSTALL_DATADIR}/thumbnailers/
	COMPONENT appimage-thumbnailer-gnome
	EXCLUDE_FROM_ALL
)

# == kde thumbnailer ==
install(
	FILES appimage-thumbnailer.desktop
	DESTINATION ${SERVICES_INSTALL_DIR}
	COMPONENT appimage-thumbnailer-kde
	EXCLUDE_FROM_ALL
)
