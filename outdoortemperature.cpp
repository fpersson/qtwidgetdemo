#include "outdoortemperature.h"

#include <QDebug>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>

OutdoorTemperature::OutdoorTemperature(QObject *parent) : QObject(parent){
    mNetworkManager = new QNetworkAccessManager(this);
    mTimer = new QTimer(this);
    connect(mNetworkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(gotData(QNetworkReply*)));
    connect(mTimer, SIGNAL(timeout()), this, SLOT(update()));
    ///doing init check
    update();

    mTimer->start(1000);
}

void OutdoorTemperature::gotData(QNetworkReply *data){
    QByteArray array = data->readAll();
    QString result(array);
    QJsonDocument jDoc = QJsonDocument::fromJson(result.toUtf8());
    QJsonObject obj = jDoc.object();
    //qDebug() << "Temp:" << obj["temp"].toString() <<"C at " << obj["time"].toString(); //result;
    mTemp = obj["temp"].toString().toFloat();
    mDate = obj["time"].toString();

    emit temperatureUpdated();
}

void OutdoorTemperature::update(){
    ///@todo implement
    if(mNetworkManager){
        mNetworkManager->get(QNetworkRequest(QUrl("https://testing-c408e.firebaseio.com/sensors/indoors/current.json")));
    }else{
        ///@todo handle error
        qDebug() << "Checking temp [failed]";
    }
}

float OutdoorTemperature::getTemperature(){
    return mTemp;
}

QString OutdoorTemperature::getLastDate(){
    return mDate;
}
