#ifndef MQTT_H
#define MQTT_H

#include <string>
#include <QObject>
#include <mosquittopp.h>

const std::string uname = "foo";
const std::string pwd = "bar";
const std::string server = "m24.cloudmqtt.com";
const std::string topic = "testing";
const int port = 15786;

/**
 * @brief The Mqtt class, simple mqtt implementation
 */
class Mqtt : public QObject, public mosqpp::mosquittopp{
    Q_OBJECT
    Q_PROPERTY(float getTemperature READ getTemperature NOTIFY temperatureUpdated)
    Q_PROPERTY(QString getLastDate READ getLastDate NOTIFY temperatureUpdated)
public:
    explicit Mqtt(QObject *parent = nullptr);
    ~Mqtt() override;

    float getTemperature(){return mTemp;}
    QString getLastDate(){return mDate;}

    void on_connect(int rc) override;
    void on_message(const struct mosquitto_message *message) override;
    void on_error() override;
    void on_disconnect(int rc) override;

signals:
    void temperatureUpdated();

public slots:

private:
    float mTemp;
    QString mDate;
};

#endif // MQTT_H
