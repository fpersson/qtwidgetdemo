#include "clock.h"

#include <QDebug>
#include <QTimer>
#include <QDateTime>

namespace fpde {
    Clock::Clock(QObject *parent) : QObject(parent){
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->start(1000);
    }

    void Clock::update(){
        emit timeChanged();
    }

    /**
     * @todo implement
     * @brief Clock::getTime
     * @return
     */
    QString Clock::getTime(){
        return QDateTime::currentDateTime().toString("HH:mm") ;
    }

    QString Clock::getDate(){
        return QDateTime::currentDateTime().toString("dddd dd MMMM - yyyy") ;
    }
}
