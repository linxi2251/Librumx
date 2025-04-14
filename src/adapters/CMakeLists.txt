set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Build
add_library(adapters
        SHARED

        interfaces/persistance/i_free_books_storage_access.hpp
        interfaces/persistance/i_user_storage_access.hpp
        interfaces/persistance/i_library_storage_access.hpp
        interfaces/persistance/i_authentication_access.hpp
        interfaces/persistance/i_app_info_access.hpp
        interfaces/persistance/i_dictionary_access.hpp
        interfaces/persistance/i_ai_explanation_access.hpp
        interfaces/persistance/i_folder_storage_access.hpp

        DTOs/login_dto.hpp
        DTOs/register_dto.hpp
        DTOs/book_dto.hpp
        DTOs/tag_dto.hpp
        DTOs/highlight_dto.hpp
        DTOs/rectf_dto.hpp
        DTOs/word_definition_dto.hpp
        DTOs/folder_dto.hpp

        gateways/user_storage_gateway.cpp
        gateways/user_storage_gateway.hpp
        gateways/authentication_gateway.cpp
        gateways/authentication_gateway.hpp
        gateways/free_books_storage_gateway.cpp
        gateways/free_books_storage_gateway.hpp
        gateways/library_storage_gateway.cpp
        gateways/library_storage_gateway.hpp
        gateways/app_info_gateway.cpp
        gateways/app_info_gateway.hpp
        gateways/dictionary_gateway.hpp
        gateways/dictionary_gateway.cpp
        gateways/ai_explanation_gateway.cpp
        gateways/ai_explanation_gateway.hpp
        gateways/folder_storage_gateway.hpp
        gateways/folder_storage_gateway.cpp
)

target_compile_definitions(adapters PRIVATE ADAPTERS_LIBRARY)

target_include_directories(adapters
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/DTOs
        ${CMAKE_CURRENT_SOURCE_DIR}/gateways
        ${CMAKE_CURRENT_SOURCE_DIR}/interfaces/persistance
        PRIVATE
        ${DOMAIN_INCLUDES}
        ${APPLICATION_INCLUDES}
)
target_compile_definitions(adapters
        PRIVATE
        $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)

target_link_libraries(adapters
        PRIVATE
        domain
        application
        Qt6::Core
        Qt6::Gui
)