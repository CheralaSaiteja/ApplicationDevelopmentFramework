cmake_minimum_required(VERSION 3.8)
project(ADK VERSION 0.1)

add_subdirectory(dep/glfw)
add_subdirectory(dep/glm)

file(GLOB SRC src/*.c src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_link_libraries(${PROJECT_NAME} glfw glm)
