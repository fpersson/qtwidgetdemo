#include <QApplication>
#include <QQmlApplicationEngine>
#include "temperaturesensor.h"
#include "sysinfo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<TemperatureSensor>("fp.system.temperaturesensor", 1, 0, "Temperatursensor");
    qmlRegisterType<SysInfo>("fp.system.info", 1, 0, "SysInfo");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
