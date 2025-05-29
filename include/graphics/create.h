#ifndef CREATE_H_
#define CREATE_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace graphics {
// Creates a triangle primitive at the given raw vertices. Mutates vao, vbo
// referenced parameters with returned ids.
//
// Args:
//  vao: Reference to VAO ID.
//  vbo: Reference to VBO ID.
//  vertices: Raw vertices data array (for VBO).
//  vertices_size: Size of vertices in bytes.
//  locations: Number of vertex attribute locations.
//  components: Number of components per vertex attribute.
void CreateTriangle(GLuint& vao, GLuint& vbo, GLfloat* vertices,
                    size_t vertices_size, GLint locations = 1,
                    GLint components = 3);

// Creates a square primitive at the given raw vertices and indices. Mutates
// vao, vbo, ebo referenced parameters with returned ids.
//
// Args:
//  vao: Reference to VAO ID.
//  vbo: Reference to VBO ID.
//  ebo: Reference to EBO ID.
//  vertices: Raw vertices data array (for VBO).
//  vertices_size: Size of vertices in bytes.
//  indices: Raw indices data array (for EBO).
//  indices_size: Size of indices in bytes.
//  locations: Number of vertex attribute locations.
//  components: Number of components per vertex attribute.
void CreateSquare(GLuint& vao, GLuint& vbo, GLuint& ebo, GLfloat* vertices,
                  size_t vertices_size, GLint* indices, size_t indices_size,
                  GLint locations = 1, GLint components = 3);
}  // namespace graphics

#endif
