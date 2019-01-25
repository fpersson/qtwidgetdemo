#ifndef OUTDOORTEMPERATURE_H
#define OUTDOORTEMPERATURE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QPointer>
#include <QTimer>

class OutdoorTemperature : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float getTemperature READ getTemperature NOTIFY temperatureUpdated)
    Q_PROPERTY(QString getLastDate READ getLastDate NOTIFY temperatureUpdated)
public:
    explicit OutdoorTemperature(QObject *parent = nullptr);
    float getTemperature();
    QString getLastDate();

signals:
    void temperatureUpdated();

public slots:
    void gotData(QNetworkReply *data);
    void update();

private:
    QPointer<QNetworkAccessManager> mNetworkManager = nullptr;
    QPointer<QTimer> mTimer = nullptr;

    float mTemp;
    QString mDate;

};

#endif // OUTDOORTEMPERATURE_H
