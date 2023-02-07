cmake_minimum_required(VERSION 3.15)
project(Snake)

set(CMAKE_CXX_STANDARD 14)

add_executable(Snake main.cpp snake.h fruit.h fruit.cpp menu.h snake.cpp menu.cpp)

# Detect and add SFML
set(SFML_PATH "C:/Users/Arosl/Desktop/C++/ppo/Projekt_1/solutions/Snake/SFML-2.5.1" ${CMAKE_MODULE_PATH})
set(SFML_DIR ${SFML_PATH}/lib/cmake/SFML)
find_package(SFML 2 REQUIRED graphics window system)

if(SFML_FOUND)
    target_link_libraries(Snake sfml-graphics sfml-window sfml-audio)
    include_directories(${SFML_PATH}/include/SFML/)
endif()