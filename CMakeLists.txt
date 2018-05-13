cmake_minimum_required(VERSION 3.11)
project(ArashiEngine)

set(CMAKE_CXX_STANDARD 17)

include_directories(Projet/Include
    Projet/souces/Engine/Command/
    Projet/souces/Engine/Debug/
    Projet/souces/Engine/Entities/
    Projet/souces/Engine/Events/
    Projet/souces/Engine/Managers/
    Projet/souces/Engine/GameContext/
    Projet/souces/Engine/Logic/
    Projet/souces/Engine/Services/
    Projet/souces/Engine/Stages/)

file(GLOB sources_files
        Projet/souces/*.cpp
        Projet/souces/*/*.cpp
        Projet/souces/*/*/*.cpp
        Projet/souces/*/*/*/*.cpp
        Projet/souces/*/*/*/*.cpp
        Projet/souces/*/*/*/*/*.cpp
        Projet/souces/*/*/*/*/*/*.cpp
        Projet/souces/*/*/*/*/*/*/*.cpp)

#message(STATUS "Loaded sources files : ${sources_files}")
add_executable(ArashiEngine ${sources_files})

# Detect and add SFML
message(STATUS "Detect and add SFML")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(SFML_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Projet)
set(SFML_STATIC_LIBRARIES TRUE)

#Find any version 2.X of SFML
#See the FindSFML.cmake_modules file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if (SFML_FOUND)
    message(STATUS "SFML Found")
    include_directories(${SFML_INCLUDE_DIR})
    message(STATUS "linking : ${SFML_LIBRARIES}")
    target_link_libraries(ArashiEngine ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

# Detect and add BOOST
#set(Boost_DEBUG 1)
set(BOOST_ROOT  "C:/DEV/Boost/boost_1_67_0")
set(Boost_INCLUDE_DIRS "C:/DEV/Boost/boost_1_67_0")
set(Boost_LIBRARY_DIRS "C:/DEV/Boost/boost_1_67_0/lib")

set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.67.0 COMPONENTS date_time filesystem system log iostreams regex)

if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")

    message(STATUS "Linking boost...")
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(ArashiEngine ${Boost_LIBRARIES})
    message(STATUS "Done")
endif()


# Adding Thor
message(STATUS "Linking Thor...")
add_library(libthor STATIC IMPORTED)
target_link_libraries(ArashiEngine libthor)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set_property(TARGET libthor PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/Projet/lib/libthor-s-d.a)
else ()
    set_property(TARGET libthor PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/Projet/lib/libthor-s.a)
endif ()

target_link_libraries(ArashiEngine libthor -Wall -pedantic -lpthread)
