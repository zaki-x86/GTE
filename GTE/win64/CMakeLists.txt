cmake_minimum_required(VERSION 3.15)

project(
    "GTE"
    VERSION 0.1.0
    DESCRIPTION "GTE: Graphics Template Engine"
    LANGUAGES CXX
)

set(THIRD_PARTY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../ext")
set(MAIN_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../gte/src")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out)

set(LIB_SDL2 ${THIRD_PARTY_DIR}/sdl-windows/lib/x64/SDL2.lib)
set(LIB_SDL2_MAIN ${THIRD_PARTY_DIR}/sdl-windows/lib/x64/SDL2main.lib)
set(LIB_GLEW ${THIRD_PARTY_DIR}/glew/lib/Release/x64/glew32s.lib)

include_directories(${THIRD_PARTY_DIR}/sdl-windows/include)
include_directories(${THIRD_PARTY_DIR}/glew/include)

file(GLOB_RECURSE CPP_HEADERS ${MAIN_SOURCE_DIR}/*.hpp)
file(GLOB_RECURSE CPP_SOURCES ${MAIN_SOURCE_DIR}/*.cpp)

# If we are generating a release build, then request that we produce a Windows desktop
# application executable by specifying WIN32 as an executable option. This avoids the
# console window from appearing when we launch the .exe file. However for debug builds,
# the console window makes it really easy to view logging output so we'll allow it by
# NOT specifying the WIN32 executable option.
if(CMAKE_BUILD_TYPE MATCHES "Release")
    set(EXECUTABLE_TYPE WIN32)
endif()

add_executable(
    GTE ${EXECUTABLE_TYPE}
    ${CPP_HEADERS}
    ${CPP_SOURCES}
)

set_property(TARGET GTE PROPERTY CXX_STANDARD 17)
set_property(TARGET GTE PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(
    GTE
    opengl32
    ${LIB_GLEW}
    ${LIB_SDL2}
    ${LIB_SDL2_MAIN}
)

add_custom_command(
    TARGET GTE
    POST_BUILD
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND PowerShell -File cmake-post-build.ps1
)