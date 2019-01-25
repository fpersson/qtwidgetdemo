import QtQuick 2.0
import QtQuick.Extras 1.4
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import fp.system.outdoortemperature 1.0
Item {
    width: 60
    height: 275
    OutdoorTemperature{
        id: temperature
    }
    Gauge {
        id: gauge
        anchors.fill: parent
        minimumValue: -20
        value: temperature.getTemperature
        maximumValue: 40

        style: GaugeStyle {
            valueBar: Rectangle {
                implicitWidth: 2
                color: "#e34c22" //Qt.rgba(gauge.value / gauge.maximumValue, 0, 1 - gauge.value / gauge.maximumValue, 1)
            }
        }
    }
}
