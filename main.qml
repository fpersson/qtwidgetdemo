import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 450
    height: 150
    title: qsTr("QtTemperaturDemo")
    MainForm {
        width: 150
        height: 150
    }

    SysInfo {
        x: 150
        y: 0
    }
}
