#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "create.h"

void create_triangle(GLuint& vao, GLuint& vbo, GLfloat* vertices,
                     size_t vertices_size) {
  // Generate and configure vertex buffer and array objects
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);

  glBindVertexArray(vao);
  // clang-format off
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices_size, vertices, GL_STATIC_DRAW);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
                          (void*)0);
      glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  // clang-format on
  glBindVertexArray(0);
}

void create_square(GLuint& vao, GLuint& vbo, GLuint& ebo, GLfloat* vertices,
                   size_t vertices_size, GLint* indices, size_t indices_size) {
  // Generate and configure vertex buffer and array objects
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);
  glGenBuffers(1, &ebo);

  glBindVertexArray(vao);
  // clang-format off
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices_size, vertices, GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_size, indices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLint),
                            (void*)0);
        glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  // clang-format on
  glBindVertexArray(0);
}
