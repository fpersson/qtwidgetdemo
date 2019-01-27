import QtQuick 2.0
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4

import fpde.system.clock 1.0

Item {
    width: 400
    id: item_clock
    FPClock{
        id: clock1
    }
    //color: "#343434"
    FontLoader { id: localFont; source: "digital-7.ttf" }
    Rectangle {
        id: column
        Text {
            x: 0
            y: 8
            width: 400
            height: 90
            //width: 480
            //height: 47
            color: "#999999"
            text: clock1.getTime
            horizontalAlignment: Text.AlignHCenter
            font { family: localFont.name; pixelSize: 110; capitalization: Font.Capitalize }

            Text {
                id: text1
                x: 2
                y: 98
                width: 400
                height: 30
                color: "#999999"
                text: clock1.getDate
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 23
            }
        }
    }

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 480
        height: 1
        color: "#999999"
        border.width: 0
    }
}
