
add_library(GuiControl STATIC src/main.cpp)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

target_link_libraries(GuiControl  Qt6::Core Qt6::Widgets)

target_include_directories(GuiControl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

