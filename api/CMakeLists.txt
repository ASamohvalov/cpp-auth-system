cmake_minimum_required(VERSION 3.10)
project(auth-system-api)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SQLite3 REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(jwt-cpp CONFIG REQUIRED)

pkg_check_modules(libsodium REQUIRED libsodium)

add_executable(api
    src/main.cpp
    src/config/env_config.cpp
    src/config/json_config.cpp

    src/routes/routes.cpp
    src/controllers/auth_controller.cpp
    src/controllers/user_controller.cpp
    src/controllers/admin_controller.cpp

    src/db/migrations.cpp
    src/db/db_connection.cpp
    src/dto/user_dto.cpp
    src/dto/role_dto.cpp
		src/dto/token_dto.cpp
    src/repositories/user_repo.cpp
    src/repositories/role_repo.cpp
		src/repositories/token_repo.cpp
    
    src/exceptions/sql_exception.cpp
    src/errors/error.cpp

    src/utils/password_encoder.cpp
    src/utils/token_provider.cpp
    src/utils/admin_initializer.cpp
    src/utils/role_initializer.cpp

    src/middleware/auth_middleware.cpp
    src/middleware/access_middleware.cpp
)

target_include_directories(api PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
    ${LIBSODIUM_INCLUDE_DIRS}
)

target_compile_options(api PRIVATE -Wall)

target_link_libraries(api PRIVATE
    pthread
    SQLite::SQLite3
    ${LIBSODIUM_LIBRARIES}
    jwt-cpp::jwt-cpp
)
