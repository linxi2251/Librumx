set(qml_singletons
        Fonts.qml
        Icons.qml
        Style.qml
        Globals.qml
        GlobalSettings.qml
)

set_source_files_properties(${qml_singletons} PROPERTIES QT_QML_SINGLETON_TYPE TRUE)
qt_add_qml_module(singletonStyle
        URI "Librumx.style"
        VERSION 1.0
        STATIC
        RESOURCE_PREFIX "/"
        QML_FILES
        Style.qml
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Librumx/style
)

qt_add_qml_module(singletonFonts
        URI "Librumx.fonts"
        VERSION 1.0
        STATIC
        RESOURCE_PREFIX "/"
        QML_FILES
        Fonts.qml
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Librumx/fonts
)

qt_add_qml_module(singletonIcons
        URI "Librumx.icons"
        VERSION 1.0
        STATIC
        RESOURCE_PREFIX "/"
        QML_FILES
        Icons.qml
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Librumx/icons
)

qt_add_qml_module(singletonGlobals
        URI "Librumx.globals"
        VERSION 1.0
        STATIC
        RESOURCE_PREFIX "/"
        QML_FILES
        Globals.qml
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Librumx/globals
)

qt_add_qml_module(singletonGlobalSettings
        URI "Librumx.globalSettings"
        VERSION 1.0
        STATIC
        RESOURCE_PREFIX "/"
        QML_FILES
        GlobalSettings.qml
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Librumx/globalSettings
)