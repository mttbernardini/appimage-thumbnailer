/*
 * Copyright (c) 2021 Matteo Bernardini
 */

#include <appimage/appimage.h>
#include "appimage-icon-extract.h"

ait_icon_t* appimage_thumbnailer_icon_extract(char const* path_to_appimage, unsigned const preferred_size)
{
	/**
	 * Extracts AppImage icon. If an icon of `preferred_size` is found it will be returned, otherwise fallback to `.DirIcon`.
	 * If not found (non-compliant AppImage), `NULL` is returned
	 */

	ait_icon_t* icon = malloc(sizeof(ait_icon_t));
	if (!icon)
	{
		return NULL;
	}

	bool found = appimage_read_file_into_buffer_following_symlinks(path_to_appimage, ".DirIcon", &icon->data, &icon->data_size);

	if (!found)
	{
		free(icon);
		return NULL;
	}

	return icon;
}

void appimage_thumbnailer_destroy_icon(ait_icon_t* icon)
{
	free(icon->data);
	free(icon);
}
