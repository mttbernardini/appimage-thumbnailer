/*
 * Copyright (c) 2021 Matteo Bernardini
 */

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
	int size = 52;

	FILE* icon = appimage_thumbnailer_icon_extract(appimage_path, size);
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
	int ch;
	while ((ch = fgetc(icon)) != EOF)
	{
		fputc(ch, out);
	}

	return 0;
}
