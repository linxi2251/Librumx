

# Language
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Configure and add subdirectories
add_subdirectory(domain/)
get_target_property(DOMAIN_INCLUDES domain INTERFACE_INCLUDE_DIRECTORIES)

add_subdirectory(application/)
get_target_property(APPLICATION_INCLUDES application INTERFACE_INCLUDE_DIRECTORIES)

add_subdirectory(infrastructure/)
get_target_property(INFRASTRUCTURE_INCLUDES infrastructure INTERFACE_INCLUDE_DIRECTORIES)


add_subdirectory(adapters/)
get_target_property(ADAPTERS_INCLUDES adapters INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(ADAPTERS_BIN_DIR adapters CMAKE_BINARY_DIR)

add_subdirectory(presentation)

# Configure and add subdirectories
# Building
set(PROJ_SOURCES
        main.cpp
        dependency_injection.hpp
        message_handler.hpp
        resources.rc
)
qt_add_resources(PROJ_SOURCES
        fonts.qrc
        resources.qrc
)
qt_add_executable(${PROJECT_NAME}
        ${PROJ_SOURCES}
)


# Set WIN32 for windows to avoid console getting opened on start on windows
if (WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE true)
endif ()

target_compile_definitions(${PROJECT_NAME}
        PRIVATE
        $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        adapters
        domain
        application
        infrastructure
        presentation
        presentationplugin
        Qt6::Quick
        Qt6::QuickControls2
)
