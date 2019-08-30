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
		Material m;
		auto el2 = el.elementsByTagName("material").at(0).toElement();
		auto el3 = el2.elementsByTagName("original");
		if (!el3.isEmpty())
		{
			auto ambient = el3.at(0).toElement();
			QColor a;
			a.setRed(ambient.attribute("red").toInt());
			a.setGreen(ambient.attribute("green").toInt());
			a.setBlue(ambient.attribute("blue").toInt());
			m.setOriginal(a);
		}
		m.setDiffuse(el2.attribute("diffuse", "0").toDouble());
		m.setSpecularity(el2.attribute("specularity", "0").toDouble());
		m.setShininess(el2.attribute("shine", "0").toInt());

		s.setMaterial(m);
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
		auto el2 = el.elementsByTagName("position").at(0).toElement();
		Point p;
		p.setX(el2.attribute("x").toInt());
		p.setY(el2.attribute("y").toInt());
		p.setZ(el2.attribute("z").toInt());
		l.setPosition(p);
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