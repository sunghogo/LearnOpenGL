# Shaders Lesson Project

# Collect all .cpp files in the src and shaders folders
file(GLOB SRC_FILES src/*.cpp )
file(GLOB SHADER_FILES shaders/*.cpp)

add_executable(shaders_lesson ${SRC_FILES} ${SHADER_FILES})

# Include headers
target_include_directories(shaders_lesson
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/shaders
)

# Link external libraries
target_link_libraries(shaders_lesson
    PRIVATE
        glad
        glfw
        graphics
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
    target_link_libraries(shaders_lesson PRIVATE opengl32)
elseif (APPLE)
    find_library(OpenGL_LIBRARY OpenGL REQUIRED)
    target_link_libraries(shaders_lesson PRIVATE ${OpenGL_LIBRARY})
else()
    target_link_libraries(shaders_lesson PRIVATE GL)
endif()
