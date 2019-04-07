#include <QApplication>
#include <QQmlApplicationEngine>
#include "temperaturesensor.h"
#include "sysinfo.h"
#include "clock.h"
#include "outdoortemperature.h"
#include "mqtt.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<TemperatureSensor>("fp.system.temperaturesensor", 1, 0, "Temperatursensor");
    //qmlRegisterType<OutdoorTemperature>("fp.system.outdoortemperature", 1, 0, "OutdoorTemperature");
    qmlRegisterType<Mqtt>("fp.system.outdoortemperature", 1, 0, "OutdoorTemperature");
    qmlRegisterType<fpde::Clock>("fpde.system.clock", 1, 0, "FPClock");
    qmlRegisterType<SysInfo>("fp.system.info", 1, 0, "SysInfo");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
