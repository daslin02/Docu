find_package(Qt6 REQUIRED COMPONENTS Core Widgets)


add_library(pyController STATIC src/pyController.cpp)
add_library(GuiControl STATIC src/guiController.cpp src/main.cpp src/suplier.cpp)


target_link_libraries(pyController Qt6::Core)
target_link_libraries(GuiControl  Qt6::Core Qt6::Widgets pyController)

target_include_directories(pyController PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(GuiControl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
