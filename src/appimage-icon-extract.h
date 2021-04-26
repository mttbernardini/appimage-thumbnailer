/*
 * Copyright (c) 2021 Matteo Bernardini
 */

#pragma once
#include <stdio.h>
#include <stdint.h>

typedef struct {
	uint8_t* data;
	size_t   data_size;
} icon_t;

icon_t appimage_thumbnailer_icon_extract(char const* path_to_appimage, int const preferred_size);
