cmake_minimum_required(VERSION 3.13)
project(Snake)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR "C:/Users/Bartek/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS graphics window system)

add_executable(Snake main.cpp Snake.cpp Snake.h SnakeView.cpp SnakeView.h SnakeController.cpp SnakeController.h)
target_link_libraries(Snake sfml-graphics sfml-window sfml-system)