cmake_minimum_required(VERSION 3.15)

project(
    "GTE"
    VERSION 1.0.0
    DESCRIPTION "GTE - Graphics Template Engine"
    LANGUAGES CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out)
set(MAIN_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../gte/src")


file(GLOB_RECURSE CPP_HEADERS ${MAIN_SOURCE_DIR}/*.hpp)
file(GLOB_RECURSE CPP_SOURCES ${MAIN_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${CPP_HEADERS} ${CPP_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${MAIN_SOURCE_DIR})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# Find packages
find_package(SDL2 REQUIRED)
find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# Link: SDL2, GLM, GLEW (OpenGL Extension Wrangler)
target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDL2::SDL2 SDL2::SDL2main 
    glm::glm
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
)