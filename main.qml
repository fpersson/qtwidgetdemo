import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 550
    height: 320
    title: qsTr("QtTemperatureDemo")
    color: "#343434"
    MainForm {
        x: 66
        y: 0
        width: 150
        height: 150
    }

    SysInfo {
        x: 230
        y: 0
        height: 150
        anchors.rightMargin: 0
        anchors.verticalCenterOffset: -85
    }

    DigiClock {
        x: 66
        y: 170
        width: 484
        height: 150
   }

    OutdoorTemperature{
        x: 9
        y: 0
        width: 60
        height: 320
        anchors.rightMargin: 0
        anchors.verticalCenterOffset: 0
    }
}
