cmake_minimum_required(VERSION 3.16)
project(AudioHider LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INSTALL_RPATH "$ORIGIN/lib")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(OpenSSL REQUIRED)

add_executable(AudioHider
    main.cpp
    Window.cpp
    Engine.cpp
    
)

target_include_directories(AudioHider PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(AudioHider PRIVATE 
    Qt6::Widgets 
    OpenSSL::Crypto
)

install(TARGETS AudioHider DESTINATION bin)