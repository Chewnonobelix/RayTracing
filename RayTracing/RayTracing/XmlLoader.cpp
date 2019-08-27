#include "XmlLoader.h"



XmlLoader::XmlLoader()
{
}


XmlLoader::~XmlLoader()
{
}

Scene XmlLoader::load(QString filename)
{
	Scene ret;

	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "Cannot open file" << filename;
		return ret;
	}
	QDomDocument doc;
	if (!doc.setContent(&file))
	{
		qDebug() << "cannot set xml content" << filename;
		return ret;
	}

	auto root = doc.documentElement();
	auto list = root.elementsByTagName("sphere");

	for (int i = 0; i < list.size(); i++)
	{
		Sphere s;
		auto el = list.at(i).toElement();
		auto center = el.elementsByTagName("center").at(0).toElement();
		Point c(center.attribute("x").toDouble(), center.attribute("y").toDouble(), center.attribute("z").toDouble());
		s.setCenter(c);
		s.setRadius(el.attribute("radius").toDouble());

		ret.addGeometry(s);
	}

	list = root.elementsByTagName("light");

	for (int i = 0; i < list.size(); i++)
	{
		auto el = list.at(i).toElement();
		Light l;
		l.setRed(el.attribute("red").toInt());
		l.setGreen(el.attribute("green").toInt());
		l.setBlue(el.attribute("blue").toInt());
		l.setPower(el.attribute("power").toDouble());

		ret.addLight(l);
	}

	auto screen = root.elementsByTagName("screen").at(0).toElement();
	Screen s;

	s.setWidth(screen.attribute("width").toInt());
	s.setHeight(screen.attribute("height").toInt());
	s.setDir(screen.attribute("dir").toInt());

	auto pos = screen.elementsByTagName("position").at(0).toElement();
	s.setPosition(Point(pos.attribute("x").toInt(), pos.attribute("y").toInt(), pos.attribute("z").toInt()));
	pos = screen.elementsByTagName("u").at(0).toElement();
	s.setU({ pos.attribute("x").toInt(), pos.attribute("y").toInt(), pos.attribute("z").toInt() });
	pos = screen.elementsByTagName("v").at(0).toElement();
	s.setV({ pos.attribute("x").toInt(), pos.attribute("y").toInt(), pos.attribute("z").toInt() });

	ret.addScreen(s);

	return ret;
}