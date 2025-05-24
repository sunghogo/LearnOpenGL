#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "draw.h"

void draw_triangle(GLuint shader_program, GLuint vao) {
  glUseProgram(shader_program);
  glBindVertexArray(vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void draw_square(GLuint shader_program, GLuint vao) {
  glUseProgram(shader_program);
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
