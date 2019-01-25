import QtQuick 2.0
import QtQuick.Extras 1.4
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    width: 60
    height: 275
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 60
        height: 275
        color: "#343434"

        Gauge {
            id: gauge
            anchors.fill: parent
            minimumValue: -50
            value: 22
            maximumValue: 50

            style: GaugeStyle {
                valueBar: Rectangle {
                    implicitWidth: 16
                    color: Qt.rgba(gauge.value / gauge.maximumValue, 0, 1 - gauge.value / gauge.maximumValue, 1)
                }
            }
        }
    }
}
