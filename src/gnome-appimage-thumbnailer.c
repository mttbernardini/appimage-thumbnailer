/*
 * Copyright (c) 2021 Matteo Bernardini
 */

#include <stdio.h>
#include "appimage-icon-extract.h"

int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		fputs("usage: appimage-thumbnailer <path-to-appimage> <path-to-output-icon> <size>\n", stderr);
		return 1;
	}

	char* appimage_path = argv[1];
	char* output_path = argv[2];
	// TODO: this is a workaround to avoid ugly frame rendering on icon (tested on Cinnamon).
	//       there has to be a better way to do this without affecting image quality.
	// NB: size < 128 has no frame, but we want to avoid having bigger icons
	//     than default ones, which are sized 52.
	unsigned size = 52;

	ait_icon_t* icon = appimage_thumbnailer_icon_extract(appimage_path, size);
	if (!icon)
	{
		return 1;
	}

	FILE* out = fopen(output_path, "w");
	if (!out)
	{
		return 1;
	}

	// TODO: resize icon and write to png
	fwrite(icon->data, 1, icon->data_size, out);
	appimage_thumbnailer_destroy_icon(icon);
	fclose(out);

	return 0;
}
