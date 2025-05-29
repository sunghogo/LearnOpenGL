#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "graphics/create.h"

namespace graphics {
void CreateTriangle(GLuint& vao, GLuint& vbo, GLfloat* vertices,
                    size_t vertices_size, GLint locations, GLint components) {
  // Generate and configure vertex buffer and array objects
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);

  glBindVertexArray(vao);
  // clang-format off
      glBindBuffer(GL_ARRAY_BUFFER, vbo);
      glBufferData(GL_ARRAY_BUFFER, vertices_size, vertices, GL_STATIC_DRAW);
          for (GLint i = 0; i < locations; i ++) {
            GLint stride = components * locations * sizeof(GLfloat);
            void* offset = (void *)(i * components * sizeof(GLfloat));
            glVertexAttribPointer(i, components, GL_FLOAT, GL_FALSE, stride,
                                  offset);
            glEnableVertexAttribArray(i);
          }
      glBindBuffer(GL_ARRAY_BUFFER, 0);
  // clang-format on
  glBindVertexArray(0);
}

void CreateSquare(GLuint& vao, GLuint& vbo, GLuint& ebo, GLfloat* vertices,
                  size_t vertices_size, GLint* indices, size_t indices_size,
                  GLint locations, GLint components) {
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
          for (GLint i = 0; i < locations; i ++) {
            GLint stride = components * locations * sizeof(GLfloat);
            void* offset = (void *)(i * components * sizeof(GLfloat));
            glVertexAttribPointer(i, components, GL_FLOAT, GL_FALSE, stride,
                                  offset);
            glEnableVertexAttribArray(i);
          }
      glBindBuffer(GL_ARRAY_BUFFER, 0);
  // clang-format on
  glBindVertexArray(0);
}
}  // namespace graphics
