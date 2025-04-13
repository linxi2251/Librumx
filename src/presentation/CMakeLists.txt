add_subdirectory(controllers)
add_subdirectory(data_models)
add_subdirectory(components)
add_subdirectory(singletons)
list(APPEND singleton_targets
        singletonStyleplugin
        singletonFontsplugin
        singletonGlobalsplugin
        singletonIconsplugin
        singletonGlobalSettingsplugin
)

qt_add_qml_module(presentation
        URI ${PROJECT_NAME}
        VERSION 1.0
        STATIC
        RESOURCE_PREFIX /
        QML_FILES
        Main.qml
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
)
qt_target_qml_sources(presentation
        QML_FILES
        views/login/LoginPage.qml
        NO_QMLDIR_TYPES
)

target_link_libraries(presentation
        PUBLIC
        ${singleton_targets}
        data_modelsplugin
        controllersplugin
        componentsplugin
        Qt6::Quick
        Qt6::QuickControls2
)