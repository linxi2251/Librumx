
file(GLOB components_sources CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.qml" "*.js")
qt_add_qml_module(components
    URI ${PROJECT_NAME}.Components
    VERSION 1.0
    STATIC
    QML_FILES
    ${components_sources}
    RESOURCE_PREFIX /
    OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/Components
)

# qt_add_qml_module(components_comboBox
#     URI ${PROJECT_NAME}.Components.comboBox
#     VERSION 1.0
#     STATIC
#     QML_FILES
#     comboBox/MComboBox.qml
#     comboBox/MComboBoxPopup.qml
#     comboBox/ComboBoxLogic.js
#     RESOURCE_PREFIX /
#     OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/Components/comboBox
#     IMPORT_PATH
#     ${PROJECT_NAME}.Components
# )



