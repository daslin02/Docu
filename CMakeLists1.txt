cmake_minimum_required(VERSION 3.5)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Operating System: Linux")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Operating System: Windows")
    
    set(CMAKE_SYSTEM_NAME Windows)
    set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
    set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)

elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Operating System: macOS")
else()
    message(STATUS "Operating System: Unknown")
endif()


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

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

