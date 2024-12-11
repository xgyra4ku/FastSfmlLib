cmake_minimum_required(VERSION 3.10)
project(FastSfml)


set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML")

include_directories("${SFML_DIR}/include")
link_directories("${SFML_DIR}/lib")

add_library(FastSfml STATIC
        src/сInputText.cpp
        src/сButton.cpp
        include/FastSfml.hpp
        src/cSwitch.cpp
        src/cSlider.cpp
        src/cMouse.cpp
        src/PhysicsObject.cpp
        src/cPhysicsWorld.cpp)
target_include_directories(FastSfml PUBLIC include)
list(APPEND CMAKE_PREFIX_PATH "${SFML_DIR}/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(
        FastSfml
        PRIVATE
        sfml-system
        sfml-window
        sfml-graphics
        sfml-network
        sfml-audio
)
