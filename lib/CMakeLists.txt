set(LIBAPPIMAGE_DESKTOP_INTEGRATION_ENABLED OFF CACHE BOOL "")
set(LIBAPPIMAGE_THUMBNAILER_ENABLED OFF CACHE BOOL "")

if(NOT USE_SYSTEM_LIBAPPIMAGE)
	add_subdirectory(libappimage EXCLUDE_FROM_ALL)
endif()
