#ifndef CREATE_H_
#define CREATE_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Creates a triangle primitive at the given raw vertices. Mutates vao, vbo
// referenced parameters with returned ids.
//
// Args:
//  vao: Reference to VAO ID
//  vbo: Reference to VBO ID
//  vertices: Raw vertices data array (for VBO)
//  vertices_size: Size of vertices in bytes
void create_triangle(GLuint& vao, GLuint& vbo, GLfloat* vertices,
                     size_t vertices_size);

// Creates a square primitive at the given raw vertices and indices. Mutates
// vao, vbo, ebo referenced parameters with returned ids.
//
// Args:
//  vao: Reference to VAO ID
//  vbo: Reference to VBO ID
//  ebo: Reference to EBO ID
//  vertices: Raw vertices data array (for VBO)
//  vertices_size: Size of vertices in bytes
//  indices: Raw indices data array (for EBO)
//  indices_size: Size of indices in bytes
void create_square(GLuint& vao, GLuint& vbo, GLuint& ebo, GLfloat* vertices,
                   size_t vertices_size, GLint* indices, size_t indices_size);

#endif
