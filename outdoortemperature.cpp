#include "outdoortemperature.h"

#include <QDebug>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>

OutdoorTemperature::OutdoorTemperature(QObject *parent) : QObject(parent){
    mgr = new QNetworkAccessManager();

    connect(mgr, SIGNAL(finished(QNetworkReply*)), this, SLOT(gotData(QNetworkReply*)));
    mgr->get(QNetworkRequest(QUrl("https://testing-c408e.firebaseio.com/sensors/indoors/current.json")));
}

void OutdoorTemperature::gotData(QNetworkReply *data){
    QByteArray array = data->readAll();
    QString result(array);
    QJsonDocument jDoc = QJsonDocument::fromJson(result.toUtf8());
    QJsonObject obj = jDoc.object();
    qDebug() << "Temp:" << obj["temp"].toString() <<"C at "; //result;
}
