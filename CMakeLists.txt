cmake_minimum_required(VERSION 3.16)
project(AttractionOS LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(attractionos_controller src/AttractionController.cpp)
target_include_directories(attractionos_controller PUBLIC include)

add_executable(AttractionOS src/main.cpp)
target_link_libraries(AttractionOS PRIVATE attractionos_controller)

add_executable(AttractionOSTests tests/ControllerTests.cpp)
target_link_libraries(AttractionOSTests PRIVATE attractionos_controller)

enable_testing()
add_test(NAME ControllerTests COMMAND AttractionOSTests)
