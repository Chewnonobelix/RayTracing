#include <QtCore/QCoreApplication>
#include "Scene.h"
#include "XmlLoader.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	XmlLoader xml;
	auto scene = xml.load("E:\\Dev\\RayTracing\\scene.xml");

	scene.rayTracing();

	qDebug() << "End";
	return a.exec();
}
