#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "graphics/shaders.h"
#include "graphics/shaders_util.h"

namespace graphics {
Shader::Shader(const GLchar* vertex_shader_path,
               const GLchar* fragment_shader_path) {
  std::string vertex_shader_code =
      graphics::LoadShaderSource(vertex_shader_path);
  std::string fragment_shader_code =
      graphics::LoadShaderSource(fragment_shader_path);

  const GLchar* vertex_shader_source = vertex_shader_code.c_str();
  const GLchar* fragment_shader_source = fragment_shader_code.c_str();

  id_ = graphics::CreateShaderProgram(vertex_shader_source,
                                      fragment_shader_source);
}

Shader::~Shader() {
  glDeleteProgram(id_);
}

void Shader::Use() const {
  glUseProgram(id_);
}

GLint Shader::GetUniformLocation(const std::string& name) const {
  glGetUniformLocation(id_, name.c_str());
}

void Shader::SetBool(const std::string& name, GLboolean value) const {
  glUniform1i(glGetUniformLocation(id_, name.c_str()), (GLint)value);
}

void Shader::SetInt(const std::string& name, GLint value) const {
  glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, GLfloat value) const {
  glUniform1f(glGetUniformLocation(id_, name.c_str()), value);
}
}  // namespace graphics
