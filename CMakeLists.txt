cmake_minimum_required(VERSION 3.5)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_executable(docu app.cpp)
target_include_directories(docu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/bin/include)
add_subdirectory(bin)
target_link_libraries(docu PRIVATE GuiControl)

