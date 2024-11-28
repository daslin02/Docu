cmake_minimum_required(VERSION 3.5)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_TOOLCHAIN_FILE "/home/daslin/.vcpkg/vcpkg-master/scripts/buildsystems/" CACHE STRING "Vcpkg toolchain file")

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
#find_package(nlohmann-json REQUIRED )

set(PY_SCRIPT_DIR "${CMAKE_BINARY_DIR}/script")
file(MAKE_DIRECTORY ${PY_SCRIPT_DIR})

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/save)

set(PY_SCRIPTS 
"script/convertor.py"
"script/genJson.py"
)
foreach(SCRIPT_FILE ${PY_SCRIPTS})
    file(COPY ${SCRIPT_FILE} DESTINATION ${PY_SCRIPT_DIR})
endforeach()


add_executable(docu app.cpp)
target_include_directories(docu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/bin/include)
add_subdirectory(bin)

target_link_libraries(docu PRIVATE GuiControl)
target_link_libraries(docu PRIVATE pyController)
target_link_libraries(docu PRIVATE fileManager )
