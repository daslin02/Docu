find_package(Qt6 REQUIRED COMPONENTS Core Widgets)


add_library(pyController STATIC src/pyController.cpp)
add_library(GuiControl STATIC src/main.cpp)


target_link_libraries(pyController Qt6::Core)
target_link_libraries(GuiControl  Qt6::Core Qt6::Widgets)

target_include_directories(pyController PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(GuiControl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
