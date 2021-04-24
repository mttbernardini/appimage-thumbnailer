# general CPack options

set(PROJECT_VERSION ${APPIMAGETHUMBNAILER_VERSION})
set(CPACK_GENERATOR "DEB")
set(CPACK_COMPONENTS_ALL appimage-thumbnailer-gnome appimage-thumbnailer-kde)

# global options
set(CPACK_PACKAGE_CONTACT "Matteo Bernardini")
set(CPACK_PACKAGE_HOMEPAGE "https://github.com/mttbernardini/appimage-thumbnailer")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")

# versioning
set(CPACK_PACKAGE_VERSION ${APPIMAGETHUMBNAILER_VERSION})
