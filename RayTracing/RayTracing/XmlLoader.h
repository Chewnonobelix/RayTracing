#pragma once

#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include <QDebug>
#include "Scene.h"

class XmlLoader
{
public:
	XmlLoader();
	~XmlLoader();

	Scene load(QString filename);
};

