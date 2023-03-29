project(shared_service LANGUAGES C CXX)
message(STATUS "Build: ${PROJECT_NAME}")

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
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(CMAKE_AUTOUIC ON)

set(INCLUDE qtservice.h qtservice_p.h)
set(SRC qtservice.cpp)

if (${WIN32})
    set(SRC_WIN qtservice_win.cpp)
elseif (${UNIX})
    set(INCLUDE_UNIX qtunixsocket.h qtunixserversocket.h)
    set(SRC_UNIX qtservice_unix.cpp qtunixsocket.cpp qtunixserversocket.cpp)
endif ()

find_package(Qt5 COMPONENTS Core Network Widgets REQUIRED)
add_library(${PROJECT_NAME} SHARED ${SRC} ${INCLUDE} ${INCLUDE_UNIX} ${SRC_UNIX} ${SRC_WIN})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Network Qt5::Widgets)