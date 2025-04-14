
add_library(presentation STATIC)
# Translations
set(translation_files
    views/translations/librum_en.ts
    views/translations/librum_de.ts
    views/translations/librum_it.ts
    views/translations/librum_ru.ts
    views/translations/librum_ko.ts
    views/translations/librum_ar.ts
    views/translations/librum_zh.ts
    views/translations/librum_uk.ts
    views/translations/librum_pt.ts
    views/translations/librum_id.ts
    views/translations/librum_bn.ts
)
qt_add_translations(presentation TS_FILES ${translation_files})

target_compile_definitions(presentation
                PRIVATE
                    $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)

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
        URI Librumx
        VERSION 1.0
        RESOURCE_PREFIX /
        QML_FILES
        Main.qml
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Librumx
)
qt_target_qml_sources(presentation
        QML_FILES
        views/loginPage/MLoginPage.qml
        NO_QMLDIR_TYPES
)

target_link_libraries(presentation
        PUBLIC
        ${singleton_targets}
        data_models
        data_modelsplugin
        controllersplugin
        componentsplugin
        Qt6::Quick
        Qt6::QuickControls2
)
