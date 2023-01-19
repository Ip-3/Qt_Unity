import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
Rectangle {
    width:600
    height:600
    visible:true
    anchors.centerIn: parent
    color: "orange"
    property var forwardmodel: myclass.forwardModel
    property var backwardmodel: myclass.backwardModel

    ColumnLayout{
        spacing: 20
        anchors.centerIn:  parent
        Row
        {
            spacing:30
            Layout.alignment: Qt.AlignHCenter
            Repeater{
                model:forwardmodel
                Rectangle{
                    id:righttop
                    width: 120
                    height: 120
                    color: "teal"
                    Text {
                        anchors.centerIn: parent
                        id: righttoptxt
                        text: forwardmodel[index]
                        wrapMode: Text.WordWrap
                        font.pixelSize: 16
                    }
                    MouseArea{
                        anchors.fill: parent
                        onPressed: {
                            myclass.datafromqml(righttoptxt.text)
                        }
                        onReleased: {
                            myclass.stopTimer_axisright()
                        }
                    }
                }

            }

        }
        Row{
            spacing:30
            Layout.alignment: Qt.AlignHCenter
            Rectangle{
                id:rightbut
                width: 120
                height: 120
                color: "teal"
                Text {
                    anchors.centerIn: parent
                    id: righttxt
                    text: "Right"
                    font.pixelSize: 16
                    wrapMode: Text.WordWrap

                }
                MouseArea{
                    anchors.fill: parent
                    onPressed: {
                        myclass.datafromqml(righttxt.text)
                    }
                    onReleased: {
                        myclass.stopTimer_axisright()
                    }
                }
            }
            Rectangle{
                id:leftbut
                width: 120
                height: 120
                color: "teal"
                Text {
                    anchors.centerIn: parent
                    id: lefttxt
                    text: "Left"
                    wrapMode: Text.WordWrap

                    font.pixelSize: 16
                }
                MouseArea{
                    anchors.fill: parent
                    onPressed: {
                        myclass.datafromqml(lefttxt.text)
                    }
                    onReleased: {
                        myclass.stopTimer_axisright()
                    }
                }
            }
        }
        Row
        {
            spacing:30
            Layout.alignment: Qt.AlignHCenter
            Repeater{
                model:forwardmodel
                Rectangle{
                    id:lefttop
                    width: 120
                    height: 120

                    color: "teal"
                    Text {
                        anchors.centerIn: parent
                        id: lefttoptxt
                        text: backwardmodel[index]
                        wrapMode: Text.WordWrap
                        font.pixelSize: 16
                    }
                    MouseArea{
                        anchors.fill: parent
                        onPressed: {
                            myclass.datafromqml(lefttoptxt.text)
                        }
                        onReleased: {
                            myclass.stopTimer_axisright()
                        }
                    }
                }

            }


        }

    }

}
