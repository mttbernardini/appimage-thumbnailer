/*
 * Copyright (c) 2021 Matteo Bernardini
 */

#include <KIO/ThumbCreator>
#include <QtCore/QtGlobal>
#include <QImage>

extern "C" {
#include "appimage-icon-extract.h"
}

class AppImageThumbnailer : public ThumbCreator
{
public:
	AppImageThumbnailer() {};
	~AppImageThumbnailer() override {};

	bool create(const QString& path, int width, int height, QImage& img) override
	{
		icon_t icon = appimage_thumbnailer_icon_extract(path.toStdString().c_str(), width);
		if (!icon.data)
		{
			return false;
		}

		return img.loadFromData(icon.data, icon.data_size);
	};

	Flags flags() const override
	{
		return (Flags)(0);
	};
};

extern "C"
{
	Q_DECL_EXPORT ThumbCreator* new_creator()
	{
		return new AppImageThumbnailer();
	}
}
