# Hello Triangle Project

# Collect all .cpp files in the src and shaders folders
file(GLOB SRC_FILES src/*.cpp )
file(GLOB SHADER_FILES shaders/*.cpp)

add_executable(hello_triangle ${SRC_FILES} ${SHADER_FILES})

# Include headers
target_include_directories(hello_triangle
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/shaders
)

# Link external libraries
target_link_libraries(hello_triangle
    PRIVATE
        glad
        glfw
)

# Copy shaders to the build directory
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/shaders)

file(GLOB_RECURSE SHADERS "${CMAKE_CURRENT_SOURCE_DIR}/shaders/*.glsl")
foreach(shader ${SHADERS})
  get_filename_component(shader_filename ${shader} NAME)
  configure_file(${shader} ${CMAKE_CURRENT_BINARY_DIR}/shaders/${shader_filename} COPYONLY)
endforeach()

# Platform-specific OpenGL linking
if (WIN32)
    target_link_libraries(hello_triangle PRIVATE opengl32)
elseif (APPLE)
    find_library(OpenGL_LIBRARY OpenGL REQUIRED)
    target_link_libraries(hello_triangle PRIVATE ${OpenGL_LIBRARY})
else()
    target_link_libraries(hello_triangle PRIVATE GL)
endif()
