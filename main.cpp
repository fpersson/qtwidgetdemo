#include <QApplication>
#include <QQmlApplicationEngine>
#include "temperaturesensor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<TemperatureSensor>("fp.system.temperaturesensor", 1, 0, "Temperatursensor");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
