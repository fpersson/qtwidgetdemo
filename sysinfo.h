#ifndef SYSINFO_H
#define SYSINFO_H

#include <QObject>

const long minute = 60;
const long hour = minute * 60;
const long day = hour * 24;
const double megabyte = 1024 * 1024;
const double gigabyte = megabyte * 1024;

class SysInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString getHostName READ getHostName)
    Q_PROPERTY(QString getUptime READ getUptime NOTIFY updated)
    Q_PROPERTY(QString getMemory READ getMemory NOTIFY updated)
    Q_PROPERTY(QString getProc READ getProc NOTIFY updated)
    Q_PROPERTY(QString getDiskInfo READ getDiskInfo NOTIFY updated)

public:
    explicit SysInfo(QObject *parent = 0);
    QString getHostName();
    QString getUptime();
    QString getMemory();
    QString getProc();
    QString getDiskInfo();
signals:
    //called every second, updates uptime
    void updated();

public slots:
    void updateData();
};

#endif // SYSINFO_H
