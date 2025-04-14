add_library(controllers)

qt6_add_qml_module(controllers
        URI "${PROJECT_NAME}.controllers"
        RESOURCE_PREFIX /
        VERSION 1.0
        SOURCES
        stdafx.h
        interface/i_settings_controller.hpp
        interface/i_app_info_controller.hpp
        settings_controller.hpp
        settings_controller.cpp
        app_info_controller.hpp
        app_info_controller.cpp
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/controllers
)


target_include_directories(controllers
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

target_include_directories(controllersplugin
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(controllers
        PRIVATE
        rapidfuzz::rapidfuzz
        Qt6::Core
        Qt6::Gui
        adapters
        domain
        application
        data_models
)
