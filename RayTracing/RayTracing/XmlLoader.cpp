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
		return ret;

	QDomDocument doc;
	if (!doc.setContent(&file))
		return ret;

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
	return ret;
}