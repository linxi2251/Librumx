set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Build
add_library(adapters
        SHARED
        DTOs/login_dto.hpp
        DTOs/register_dto.hpp
        DTOs/book_dto.hpp
        DTOs/tag_dto.hpp
        DTOs/highlight_dto.hpp
        DTOs/rectf_dto.hpp
        DTOs/word_definition_dto.hpp
        DTOs/folder_dto.hpp
)

target_compile_definitions(adapters PRIVATE ADAPTERS_LIBRARY)

target_include_directories(adapters
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/DTOs
)
target_compile_definitions(adapters
        PRIVATE
        $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)

target_link_libraries(adapters
        PRIVATE
        Qt6::Core
        Qt6::Gui
)