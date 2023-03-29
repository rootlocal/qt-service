cmake_minimum_required(VERSION 3.23)
project(qt_service LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT MSVC)
    add_compile_options(-Wno-deprecated-declarations)
endif ()

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Turn on automatic invocation of the MOC, UIC & RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui")
set(CMAKE_AUTOUIC ON)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib")
find_package(Qt5 COMPONENTS Widgets Core Network REQUIRED)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB_RECURSE SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE UI_FILES "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui")
qt5_wrap_ui(UI_HEADERS "${UI_FILES}")

add_executable(${PROJECT_NAME} ${SRC})

add_dependencies(${PROJECT_NAME} shared_service)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt5::Core
        Qt5::Widgets
        Qt5::Network
        shared_service
        )

