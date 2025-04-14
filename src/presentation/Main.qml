import QtQuick
import QtQuick.Controls
import Librumx.controllers
import Librumx.style
import Librumx.Components

import "views/loginPage"

ApplicationWindow {
  id: baseRoot
  property int defaultMinWidth: 650
  property int sidebarOpenedMinWidth: 810
  property int readingPageMinWidth: 550
  property bool notifyAboutUpdates: true
  property bool rightAlign: AppInfoController.language === "العربية"
  property bool externalBookMode: false

  // Only initalize once at the start
  // Component.onCompleted: externalBookMode = externalBook

  minimumHeight: 400
  minimumWidth: 650
  visible: true
  visibility: Window.Maximized
  title: qsTr("Librum - Your ebook reader")

  Shortcut {
      sequence: SettingsController.shortcuts.ReloadApplication
      // onActivated: internal.reloadApplication()
  }

  MLoginPage {
    anchors.fill: parent
  }

}
