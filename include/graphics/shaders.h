#ifndef SHADERS_H_
#define SHADERS_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace graphics {

// Initializes, compiles, validates a shader
//
// Args:
//  shader_type: GL defined shader macro
//  shader_source: GLSL shader source code
//
// Returns:
//  Shader ID
GLuint create_shader(GLuint shader_type, const GLchar* shader_source);

// Creates shader program containing default vertex and fragment shaders.
//
// Args:
//  vertex_source: GLSL vertex shader source file
//  fragment_source: GLSL fragment shader source file
//
// Returns:
//  Shader program ID
GLuint create_shader_program(const GLchar* vertex_source,
                             const GLchar* fragment_source);
}  // namespace graphics

#endif
