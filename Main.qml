import QtQuick


Window {
    width: 1024
    height: 600
    visible: true
    title: "Clock"
    color: "Black"

    Text{
        id: dateText
        font.pixelSize: 35
        font.family: "Courier"
        text: dateProvider.currentDate
        color: "#850601"
        anchors.bottom: timeText.top
        anchors.left: timeText.left
    }

    Text{
        id: timeText
        font.pixelSize: 100
        //font.letterSpacing: 1
        font.family: "Courier"
        text: timeProvider.currentTime
        color: "#850601"
        anchors.centerIn: parent
    }


}
