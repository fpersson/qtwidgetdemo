#include "mqtt.h"
#include <QtDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUuid>

Mqtt::Mqtt(QObject *parent) :   QObject(parent),
                                mosquittopp(QUuid::createUuid().toByteArray(), true)
{
    qDebug() << "Mqtt called";
    mosqpp::lib_init();
    username_pw_set(uname.c_str(), pwd.c_str());
    mosqpp::mosquittopp::connect(server.c_str(),port);
    loop_start();
}

Mqtt::~Mqtt(){
    loop_stop(true);
    qDebug() << "mqtt loop_stop called";
}

void Mqtt::on_error(){
    qDebug() << "Mqtt error...";

}

void Mqtt::on_connect(int rc){
    qDebug() << "mqtt connected to " << server.c_str();
    if(rc == 0){
        mosqpp::mosquittopp::subscribe(nullptr, topic.c_str(), 2);
        qDebug() << "mqtt subscribe to " << topic.c_str();
    }
}

void Mqtt::on_disconnect(int rc){
    qDebug() << "mqtt disconnected from " << server.c_str();
}

void Mqtt::on_message(const struct mosquitto_message *message){
    qDebug() << "Got message: " << (char*)message->payload;
    QString result((char*)message->payload);
    QJsonDocument jDoc = QJsonDocument::fromJson(result.toUtf8());
    QJsonObject obj = jDoc.object();
    qDebug() << "Temp:" << obj["temp"].toString() <<"C at " << obj["date"].toString(); //result;
    mTemp = obj["temp"].toString().toFloat();
    mDate = obj["time"].toString();

    emit temperatureUpdated();
}
