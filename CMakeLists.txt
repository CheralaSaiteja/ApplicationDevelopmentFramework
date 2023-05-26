cmake_minimum_required(VERSION 3.8)
project(ADK VERSION 0.1)

# Add Dependencies
add_subdirectory(dep/glfw)
add_subdirectory(dep/glm)

# Set Sources
file(GLOB SRC src/*.c src/*.cpp)

# Build Info
if(CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/Debug/")
    set(PROJECT_BINARY_DIR "${CMAKE_SOURCE_DIR}/build/Debug/")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/Release/")
    set(PROJECT_BINARY_DIR "${CMAKE_SOURCE_DIR}/build/Release/")
endif()

find_package(glfw3)
if(!glfw3_FOUND)
    message("GLFW NOT FOUND")
endif()

add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_link_libraries(${PROJECT_NAME} glfw glm)
