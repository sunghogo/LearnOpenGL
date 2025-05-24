# Hello Window Project
add_executable(hello_window src/main.cpp)

# Link external libraries
target_link_libraries(hello_window
    PRIVATE
        glad
        glfw
)

# Platform-specific OpenGL linking
if (WIN32)
    target_link_libraries(hello_window PRIVATE opengl32)
elseif (APPLE)
    find_library(OpenGL_LIBRARY OpenGL REQUIRED)
    target_link_libraries(hello_window PRIVATE ${OpenGL_LIBRARY})
else()
    target_link_libraries(hello_window PRIVATE GL)
endif()
