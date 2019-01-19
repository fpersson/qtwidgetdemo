import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 480
    height: 320
    title: qsTr("QtTemperatureDemo")
    color: "#343434"
    MainForm {
        width: 150
        height: 150
    }

    SysInfo {
        x: 180
        y: 0
        height: 150
        anchors.rightMargin: 0
        anchors.verticalCenterOffset: -85
    }

    DigiClock {
        x: 0
        y: 170
        height: 150
   }

}
