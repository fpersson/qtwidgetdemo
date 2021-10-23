#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include <QObject>
#include <QPointer>
#include <QProcess>

class TemperatureSensor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int getTemperature READ getTemperature NOTIFY temperatureUpdated)
public:
    explicit TemperatureSensor(QObject *parent = 0);
    int getTemperature();

signals:
    void temperatureUpdated();
    void dataAvialable(const QString &data);

public slots:
    void update();
    void gotData();
    void gotError(QProcess::ProcessError err);
    void onExit(int exitCode, QProcess::ExitStatus exitStatus);


private:
    QPointer<QProcess> mProcess;
    void parseTemperature(QString data);
    int mTemperature;
};

#endif // TEMPERATURESENSOR_H
