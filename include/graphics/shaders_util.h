#ifndef SHADERS_UTIL_H_
#define SHADERS_UTIL_H_

#include <glad/glad.h>
#include <string>

namespace graphics {
// Loads raw shader source from GLSL file.
//
// Args:
//  file_path: File path of shader starting from root directory of the lesson.
//
// Returns:
//  Raw shader source code as std::string.
std::string LoadShaderSource(const GLchar* file_path);

// Initializes, compiles, validates a shader.
//
// Args:
//  shader_type: GL defined shader macro.
//  shader_source: GLSL shader source code.
//
// Returns:
//  Shader ID.
GLuint CreateShader(GLuint shader_type, const GLchar* shader_source);

// Creates shader program containing default vertex and fragment shaders.
//
// Args:
//  vertex_source: GLSL vertex shader source file.
//  fragment_source: GLSL fragment shader source file.
//
// Returns:
//  Shader program ID.
GLuint CreateShaderProgram(const GLchar* vertex_source,
                           const GLchar* fragment_source);
}  // namespace graphics

#endif
