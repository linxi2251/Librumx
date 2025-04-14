 add_library(data_models
         STATIC
         shortcuts_model/shortcuts_model.hpp
         shortcuts_model/shortcuts_model.cpp
         shortcuts_model/shortcuts_proxy_model.hpp
         shortcuts_model/shortcuts_proxy_model.cpp
 )
set_source_files_properties(TranslationsModel.qml PROPERTIES QT_QML_SINGLETON_TYPE TRUE)
qt6_add_qml_module(data_models
        URI "Librumx.models"
        VERSION 1.0
        TYPEINFO models.qmltypes
        QML_FILES
        TranslationsModel.qml
        RESOURCE_PREFIX /
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Librumx/models
)

target_include_directories(data_models
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/shortcuts_model/
)
 target_include_directories(data_modelsplugin
         PUBLIC
         ${CMAKE_CURRENT_LIST_DIR}
         ${CMAKE_CURRENT_LIST_DIR}/shortcuts_model/
 )

target_link_libraries(data_models
        PRIVATE
        rapidfuzz::rapidfuzz
        Qt6::Core
        Qt6::Gui
        adapters
        domain
        application
)
