#include <QApplication>
#include <QQmlApplicationEngine>
#include "temperatursensor/src/temperaturesensor.h"
#include "sysinfo/src/sysinfo.h"
#include "clock/src/clock.h"
#include "mqtt/src/mqtt.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<TemperatureSensor>("fp.system.temperaturesensor", 1, 0, "Temperatursensor");
    qmlRegisterType<Mqtt>("fp.system.outdoortemperature", 1, 0, "OutdoorTemperature");
    qmlRegisterType<fpde::Clock>("fpde.system.clock", 1, 0, "FPClock");
    qmlRegisterType<SysInfo>("fp.system.info", 1, 0, "SysInfo");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
