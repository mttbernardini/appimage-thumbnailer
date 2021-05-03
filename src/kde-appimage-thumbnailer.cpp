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
		ait_icon_t* icon = appimage_thumbnailer_icon_extract(path.toStdString().c_str(), width);
		if (!icon)
		{
			return false;
		}

		bool created = img.loadFromData(icon->data, icon->data_size);
		img = img.scaled(width, height, Qt::KeepAspectRatio);
		appimage_thumbnailer_destroy_icon(icon);
		return created;
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
