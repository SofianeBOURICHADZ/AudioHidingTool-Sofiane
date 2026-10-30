cmake_minimum_required(VERSION 3.16)
project(AudioHider LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INSTALL_RPATH "$ORIGIN/lib")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
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

# Install executable
install(TARGETS AudioHider DESTINATION bin)

# Bundle OpenSSL library into bin/lib
install(FILES $<TARGET_FILE:OpenSSL::Crypto> DESTINATION bin/lib)

# Locate and bundle Qt platform plugin robustly
find_path(_qt_platforms_dir 
    NAMES qxcb.so qwindows.dll qoffscreen.so
    PATHS 
        "/usr/lib/qt6/plugins/platforms"
        "/usr/lib/x86_64-linux-gnu/qt6/plugins/platforms"
    DOC "Path to Qt6 platforms plugin directory"
)

if(_qt_platforms_dir)
    install(DIRECTORY "${_qt_platforms_dir}" DESTINATION bin)
endif()

# Bundle Qt core, gui, and widgets runtime libraries into bin/lib
install(FILES 
    $<TARGET_FILE:Qt6::Core> 
    $<TARGET_FILE:Qt6::Gui> 
    $<TARGET_FILE:Qt6::Widgets> 
    DESTINATION bin/lib
    
)