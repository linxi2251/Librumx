import QtQuick
import QtQuick.Controls
import Librumx.controllers
import Librumx.style
import Librumx.Components

import "views/login"

ApplicationWindow {
  id: rootWindow
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  color: Style.colorBasePurple

  Component.onCompleted: {
    console.log(SettingsController.shortcuts)
    for (let item in SettingsController.shortcuts.keys()) {
      console.log(item)
    }
  }

  MLogo {
    anchors.centerIn: parent
  }

}
