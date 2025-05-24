cmake_minimum_required(VERSION 3.10)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------------------------------------------------------
# External Dependencies

# GLAD
add_library(glad external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

# GLFW
add_subdirectory(external/glfw)

# -----------------------------------------------------------------------------
# Macro to add subdirectory projects
macro(add_all_subdirectories BASE_DIR)
    file(GLOB CHILD_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/${BASE_DIR} ${BASE_DIR}/*)
    foreach(child ${CHILD_DIRS})
        if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${BASE_DIR}/${child}")
            add_subdirectory(${BASE_DIR}/${child})
        endif()
    endforeach()
endmacro()

# -----------------------------------------------------------------------------
# Add Projects
add_all_subdirectories(lessons/getting_started)
