cmake_minimum_required(VERSION 3.10)
project(MyLibrary)


set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML")

include_directories("${SFML_DIR}/include")
link_directories("${SFML_DIR}/lib")



add_library(mylibrary STATIC src/mylibrary.cpp
        include/mylibrary.h)
target_include_directories(mylibrary PUBLIC include)
list(APPEND CMAKE_PREFIX_PATH "${SFML_DIR}/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(
        mylibrary
        PRIVATE
        sfml-system
        sfml-window
        sfml-graphics
        sfml-network
        sfml-audio
)
