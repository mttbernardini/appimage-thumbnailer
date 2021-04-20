/*
 * Copyright (c) 2021 Matteo Bernardini
 */

#include <stdio.h>
#include <appimage/appimage++.h>
#include <appimage/utils/ResourcesExtractor.h>

#include "appimage-icon-extract.h"

using namespace appimage::core;
using namespace appimage::utils;

FILE* appimage_thumbnailer_icon_extract(char* path_to_appimage, int preferred_size)
{
	/**
	 * Extracts AppImage icon. If an icon of `preferred_size` is found it will be returned, otherwise fallback to `.DirIcon`.
	 * If not found (non-compliant AppImage), `NULL` is returned
	 */

	AppImage appimage(path_to_appimage);
	ResourcesExtractor extractor(appimage);

	try
	{
		std::vector<char> icon_vector = extractor.extract(".DirIcon");
		return fmemopen(&icon_vector[0], icon_vector.size(), "r");
	}
	catch (const PayloadIteratorError& e)
	{
		return nullptr;
	}

}
