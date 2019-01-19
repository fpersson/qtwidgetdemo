#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>

namespace fpde {
    class Clock : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString getTime READ getTime NOTIFY timeChanged)
        Q_PROPERTY(QString getDate READ getDate NOTIFY timeChanged)
        //Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    public:
        explicit Clock(QObject *parent = 0);
        QString getTime();
        QString getDate();

    signals:
        void timeChanged();

    public slots:
        void update();
    };
}

#endif // CLOCK_H
