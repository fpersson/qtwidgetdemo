#include "temperaturesensor.h"

#include <QDebug>
#include <QTimer>
#include <QPointer>
#include <QProcess>

TemperatureSensor::TemperatureSensor(QObject *parent) : QObject(parent), mTemperature(-1){
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

void TemperatureSensor::update(){
    QString cmd = "sensors"; //fulhack
    mProcess = new QProcess(this);
    connect(mProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(gotData()));
    connect(mProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(onExit(int, QProcess::ExitStatus)));

    mProcess->start(cmd);
}

int TemperatureSensor::getTemperature(){
    return mTemperature;
}

void TemperatureSensor::gotData() {
    QByteArray byte = mProcess->readAllStandardOutput();
    parseTemperature(QString(byte));
}

void TemperatureSensor::gotError(QProcess::ProcessError err) {
    //qDebug() << "gotError: " << err;
}

void TemperatureSensor::onExit(int exitCode, QProcess::ExitStatus exitStatus) {
    //qDebug() << "Exit code; " << exitCode << " exit status: " << exitStatus;
}

void TemperatureSensor::parseTemperature(QString data){
    QStringList lines = data.split('\n');
    foreach(const QString &line, lines){
        if(line.contains("Package")){
            QStringList l1 = line.split(" ");
            mTemperature = l1[4].mid(1,2).toInt();
        }
    }
    emit temperatureUpdated();
}
