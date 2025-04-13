set(qml_singletons
        Fonts.qml
        Icons.qml
        Style.qml
        Globals.qml
        GlobalSettings.qml
)

set_source_files_properties(${qml_singletons} PROPERTIES QT_QML_SINGLETON_TYPE TRUE)
qt_add_qml_module(singletonStyle
        URI "${PROJECT_NAME}.style"
        VERSION 1.0
        STATIC
        RESOURCE_PREFIX "/"
        QML_FILES
        Style.qml
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/style
)

qt_add_qml_module(singletonFonts
        URI "${PROJECT_NAME}.fonts"
        VERSION 1.0
        STATIC
        RESOURCE_PREFIX "/"
        QML_FILES
        Fonts.qml
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/fonts
)

qt_add_qml_module(singletonIcons
        URI "${PROJECT_NAME}.icons"
        VERSION 1.0
        STATIC
        RESOURCE_PREFIX "/"
        QML_FILES
        Icons.qml
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/icons
)

qt_add_qml_module(singletonGlobals
        URI "${PROJECT_NAME}.globals"
        VERSION 1.0
        STATIC
        RESOURCE_PREFIX "/"
        QML_FILES
        Globals.qml
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/globals
)

qt_add_qml_module(singletonGlobalSettings
        URI "${PROJECT_NAME}.globalSettings"
        VERSION 1.0
        STATIC
        RESOURCE_PREFIX "/"
        QML_FILES
        GlobalSettings.qml
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/globalSettings
)