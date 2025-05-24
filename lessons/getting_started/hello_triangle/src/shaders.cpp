#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "shaders.h"

GLuint create_shader(GLuint shader_type, const GLchar* shader_source) {
  // Create shader
  GLuint shader = glCreateShader(shader_type);

  // Source and compile shader
  glShaderSource(shader, 1, &shader_source, nullptr);
  glCompileShader(shader);

  // Resolve shader type name
  GLchar* type_name;
  switch (shader_type) {
    case (GL_VERTEX_SHADER):
      type_name = "VERTEX";
      break;
    case (GL_FRAGMENT_SHADER):
      type_name = "FRAGMENT";
      break;
    default:
      type_name = "DEFAULT";
      break;
  }

  // Validate shader
  GLint success;
  GLchar info_log[512];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, 512, nullptr, info_log);
    std::cout << "ERROR::SHADER::" << type_name << "::COMPILATION_FAILED"
              << info_log << std::endl;
  }

  return shader;
}

GLuint create_shader_program(const GLchar* vertex_source,
                             const GLchar* fragment_source) {
  // Create shader program
  GLuint shader_program = glCreateProgram();

  // Create vertex and fragment shaders
  GLuint vertex_shader = create_shader(GL_VERTEX_SHADER, vertex_source);
  GLuint fragment_shader = create_shader(GL_FRAGMENT_SHADER, fragment_source);

  // Link shaders to shader program
  glAttachShader(shader_program, vertex_shader);
  glAttachShader(shader_program, fragment_shader);
  glLinkProgram(shader_program);

  // Validate shader program
  GLint success_shader;
  GLchar info_log_shader[512];
  glGetProgramiv(shader_program, GL_LINK_STATUS, &success_shader);
  if (!success_shader) {
    glGetProgramInfoLog(shader_program, 512, nullptr, info_log_shader);
    std::cout << "ERROR::SHADER_PROGRAM::LINKING_FAILED" << info_log_shader
              << std::endl;
  }

  // Delete compiled shaders after linking
  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);

  return shader_program;
}
