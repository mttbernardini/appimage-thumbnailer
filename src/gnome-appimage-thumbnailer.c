/*
 * Copyright (c) 2021 Matteo Bernardini
 */

#include <stdio.h>
#include <stdbool.h>
#include <gio/gio.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include "appimage-icon-extract.h"

static GdkPixbuf* rescale_icon(ait_icon_t* icon, unsigned target_size)
{
	GInputStream* icon_stream = NULL;
	GdkPixbuf* icon_pixbuf = NULL;
	GdkPixbuf* rescaled_pixbuf = NULL;
	GError* icon_error = NULL;

	icon_stream = g_memory_input_stream_new_from_data(icon->data, icon->data_size, &appimage_thumbnailer_destroy_icon);
	if (!icon_stream)
	{
		fputs("AIT - cannot allocate GInputStream\n", stderr);
		goto rescale_icon_epilogue;
	}

	icon_pixbuf = gdk_pixbuf_new_from_stream(icon_stream, NULL, &icon_error);
	if (!icon_pixbuf)
	{
		fprintf(stderr, "AIT - error creating GdkPixbuf: %s\n", icon_error->message);
		goto rescale_icon_epilogue;
	}

	rescaled_pixbuf = gdk_pixbuf_scale_simple(icon_pixbuf, target_size, target_size, GDK_INTERP_BILINEAR);

	if (!rescaled_pixbuf)
	{
		fputs("AIT - cannot allocate resized GdkPixbuf\n", stderr);
		goto rescale_icon_epilogue;
	}

rescale_icon_epilogue:
	g_clear_object(&icon_stream);
	g_clear_object(&icon_pixbuf);
	g_clear_error(&icon_error);

	return rescaled_pixbuf;
}


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

	GdkPixbuf* rescaled_icon = rescale_icon(icon, size);
	if (!rescaled_icon)
	{
		return 1;
	}

	bool saved = gdk_pixbuf_save(rescaled_icon, output_path, "png", NULL, NULL);
	g_clear_object(&rescaled_icon);

	return saved ? 0 : 1;
}
