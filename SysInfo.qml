import QtQuick 2.0
import fp.system.info 1.0
import QtQuick.Layouts 1.3

Item {
    SysInfo{
        id: sysInfo
    }

    TextEdit {
        id: lblHostname
        width: 80
        height: 20
        color: "#999999"
        text: sysInfo.getHostName
        font.capitalization: Font.AllUppercase
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        font.pixelSize: 12
    }

    Rectangle {
        id: rectangle
        height: 1
        color: "#999999"
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 21
    }

    Text {
        id: lblUptime
        width: 300
        height: 15
        color: "#999999"
        text: sysInfo.getUptime
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 26
        font.pixelSize: 12
    }

    Text {
        id: lbmMemory
        x: 0
        width: 300
        height: 15
        color: "#999999"
        text: sysInfo.getMemory
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 47
        font.pixelSize: 12
    }

    Text{
        id: textEdit
        x: 0
        width: 300
        height: 37
        color: "#999999"
        text: sysInfo.getDiskInfo
        anchors.top: parent.top
        anchors.topMargin: 68
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 12
    }
    id: item1
    width: 300
    height: 150
    anchors.right: parent.right
    anchors.rightMargin: 0
    anchors.verticalCenter: parent.verticalCenter
}
