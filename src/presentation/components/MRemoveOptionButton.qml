import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import Librumx.style
import Librumx.icons
import Librumx.fonts

Item {
    id: root
    property string text
    signal clicked

    implicitWidth: container.width
    implicitHeight: 36

    Pane {
        id: container
        height: parent.height
        padding: 12
        background: Rectangle {
            color: Style.colorLightHighlight
            border.width: 1
            border.color: Style.colorLightPurple
            radius: 5
        }

        RowLayout {
            anchors.centerIn: parent
            spacing: 6

            Label {
                id: filterByLabel
                Layout.topMargin: -1
                color: Style.colorBasePurple
                text: root.text
                font.pointSize: Fonts.size12
                font.weight: Font.Bold
            }

            Image {
                id: filterByArrowIcon
                Layout.topMargin: 1
                sourceSize.height: 11
                source: Icons.cancelPurple
                fillMode: Image.PreserveAspectFit
            }
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true

        cursorShape: Qt.PointingHandCursor

        onClicked: root.clicked()
    }
}
