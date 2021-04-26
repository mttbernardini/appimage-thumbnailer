/*
 * Copyright (c) 2021 Matteo Bernardini
 */

#include <appimage/appimage.h>
#include "appimage-icon-extract.h"

icon_t appimage_thumbnailer_icon_extract(char const* path_to_appimage, int const preferred_size)
{
	/**
	 * Extracts AppImage icon. If an icon of `preferred_size` is found it will be returned, otherwise fallback to `.DirIcon`.
	 * If not found (non-compliant AppImage), `NULL` is returned
	 */

	icon_t icon;
	bool found = appimage_read_file_into_buffer_following_symlinks(path_to_appimage, ".DirIcon", &icon.data, &icon.data_size);

	if (!found)
	{
		icon.data = NULL;
	}

	return icon;
}
