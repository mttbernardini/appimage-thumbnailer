/*
 * Copyright (c) 2021 Matteo Bernardini
 */

#include <stdio.h>
#include <stdbool.h>
#include <appimage/appimage.h>

#include "appimage-icon-extract.h"

FILE* appimage_thumbnailer_icon_extract(char* path_to_appimage, int preferred_size)
{
	/**
	 * Extracts AppImage icon. If an icon of `preferred_size` is found it will be returned, otherwise fallback to `.DirIcon`.
	 * If not found (non-compliant AppImage), `NULL` is returned
	 */

	char* buffer;
	size_t buf_size;
	bool found = appimage_read_file_into_buffer_following_symlinks(path_to_appimage, ".DirIcon", &buffer, &buf_size);

	if (!found)
		return NULL;

	return fmemopen(buffer, buf_size, "r");
}
