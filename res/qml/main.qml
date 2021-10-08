import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.1

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true

    ComboBox {
        id: comboBox
        model: back.comboList
        height: parent.height / 10
        width: parent.width / 3
        onActivated: {
            console.log("combomodel activated" + comboBox.currentIndex)
            back.currentIndex = comboBox.currentIndex
        }
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Button {
        id: sendButton
        text: "Send"
        width: parent.width / 5
        height: parent.height / 10
        anchors.top: comboBox.bottom
        anchors.topMargin: parent.height / 10
        anchors.left: comboBox.left 
    }
}
