/*
 * Copyright (c) 2021 Matteo Bernardini
 */

#pragma once
#include <stdio.h>
#include <stdint.h>

typedef struct {
	uint8_t* data;
	size_t   data_size;
} ait_icon_t;

ait_icon_t* appimage_thumbnailer_icon_extract(char const* path_to_appimage, unsigned const preferred_size);
void appimage_thumbnailer_destroy_icon(ait_icon_t* icon);
