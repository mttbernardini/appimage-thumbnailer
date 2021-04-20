/*
 * Copyright (c) 2021 Matteo Bernardini
 */

#include <KIO/ThumbCreator>
#include <QtCore/QtGlobal>

#include "appimage-icon-extract.h"

class AppImageThumbnailer : public ThumbCreator
{
public:
	AppImageThumbnailer() {};
	~AppImageThumbnailer() override {};

	bool create(const QString& path, int width, int height, QImage& img) override
	{
		// TODO: implement
		return false;
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
