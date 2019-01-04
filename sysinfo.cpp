#include <QHostInfo>
#include <QDebug>
#include <QTimer>
#include <QStorageInfo>

//for uptime
#include <linux/unistd.h>
#include <linux/kernel.h>
#include <sys/sysinfo.h>

#include "sysinfo.h"

SysInfo::SysInfo(QObject *parent) : QObject(parent){
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateData()));
    timer->start(1000);
}

QString SysInfo::getHostName(){
    return QHostInfo::localHostName();
}

void SysInfo::updateData(){
    emit updated();
}

QString SysInfo::getUptime(){
    struct sysinfo si;
    int error = sysinfo(&si);
    if(error != 0){
        qDebug() << "Errror: " << error;
    }

    int d = si.uptime / day;
    int hh = (si.uptime % day) / hour;
    int mm = (si.uptime % hour) / minute;
    int ss = si.uptime % minute;

    QString uptime = QString("<b>Uptime:</b> %1 Day(s) %2:%3:%4")
            .arg(QString::number(d))
            .arg(QString::number(hh), 2, '0')
            .arg(QString::number(mm), 2, '0')
            .arg(QString::number(ss), 2, '0');

    return uptime;
}

QString SysInfo::getMemory(){
    struct sysinfo si;
    int error = sysinfo(&si);
    if(error != 0){
        qDebug() << "Errror: " << error;
    }

    QString totmem = QString::number(si.totalram / gigabyte);
    QString memfree = QString::number((si.totalram / gigabyte) - (si.freeram / gigabyte));
    QString mem = QString("<b>Memory</b>: Total: %1 GB - Used: %2 GB")
            .arg(totmem.mid(0,4))
            .arg(memfree.mid(0,4));

    return mem;
}

QString SysInfo::getProc(){
    struct sysinfo si;
    int error = sysinfo(&si);
    if(error != 0){
        qDebug() << "Errror: " << error;
    }
    QString proc = QString("<b>Proc</b>: %1").arg(si.procs);
    qDebug() << proc;
    return proc;
}

QString SysInfo::getDiskInfo(){
    QStorageInfo storage = QStorageInfo::root();

    QString bytesTotal = QString::number(storage.bytesTotal()/gigabyte);
    QString bytesAvailable = QString::number(storage.bytesAvailable()/gigabyte);

    QString ret = QString("<b>Disk space</b>: %1 free of %2 GB total")
            .arg(bytesAvailable.mid(0,4))
            .arg(bytesTotal.mid(0,4));

   return ret;
}
