#ifndef OUTDOORTEMPERATURE_H
#define OUTDOORTEMPERATURE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QPointer>

class OutdoorTemperature : public QObject
{
    Q_OBJECT
public:
    explicit OutdoorTemperature(QObject *parent = nullptr);

signals:

public slots:
    void gotData(QNetworkReply *data);

private:
    QPointer<QNetworkAccessManager> mgr;
};

#endif // OUTDOORTEMPERATURE_H
