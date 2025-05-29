#ifndef DRAW_H_
#define DRAW_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace graphics {
// Draws a triangle specified at the VAO using the given shader program
//
// Args:
//  shader_program: Shader program ID used to draw the triangle
//  vao: VAO ID used to specify the vertices
void draw_triangle(GLuint shader_program, GLuint vao);

// Draws a square specified at the VAO using the given shader program
//
// Args:
//  shader_program: Shader program ID used to draw the square
//  vao: VAO ID used to specify the vertices and element buffer
void draw_square(GLuint shader_program, GLuint vao);
}  // namespace graphics

#endif
