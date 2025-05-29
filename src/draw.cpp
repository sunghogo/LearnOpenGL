#include <glad/glad.h>
#include "graphics/draw.h"

namespace graphics {
void DrawTriangle(GLuint vao) {
  glBindVertexArray(vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void DrawSquare(GLuint vao) {
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
}  // namespace graphics
