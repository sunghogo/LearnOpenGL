#ifndef DRAW_H_
#define DRAW_H_

#include <glad/glad.h>

namespace graphics {
// Draws a triangle specified at the VAO using the given shader program.
//
// Args:
//  vao: VAO ID used to specify the vertices.
void DrawTriangle(GLuint vao);

// Draws a square specified at the VAO using the given shader program.
//
// Args:
//  vao: VAO ID used to specify the vertices and element buffer.
void DrawSquare(GLuint vao);
}  // namespace graphics

#endif
