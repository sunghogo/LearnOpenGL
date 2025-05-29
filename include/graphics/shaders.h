#ifndef SHADERS_H_
#define SHADERS_H_

#include <glad/glad.h>
#include <string>

namespace graphics {
// Manages a GLSL shader program.
//
// Loads vertex and fragment shaders from file paths, compiles them,
// links them into a program, and provides utility functions to use
// the program and set uniform variables.
class Shader {
 public:
  // Constructs a Shader object from vertex and fragment shader file paths.
  Shader(const GLchar* vertex_shader_path, const GLchar* fragment_shader_path);

  // Destructor for Shader object.
  ~Shader();

  // Activates the shader program for use.
  void Use() const;

  // Gets uniform location from shader.
  GLint GetUniformLocation(const std::string& name) const;

  // Sets a bool uniform.
  void SetBool(const std::string& name, GLboolean value) const;

  // Sets an int uniform.
  void SetInt(const std::string& name, GLint value) const;

  // Sets a float uniform.
  void SetFloat(const std::string& name, GLfloat value) const;

 private:
  // OpenGL shader program ID.
  GLuint id_;
};
}  // namespace graphics

#endif
