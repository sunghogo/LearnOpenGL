#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "shaders_util.h"
#include "shaders.h"
#include "create.h"
#include "draw.h"

// Window dimensions
const GLint kWidth = 800, kHeight = 600;

#include <filesystem>

// Shader sources
const std::string kVertexShaderSource =
    load_shader_source("shaders/vertex.glsl").c_str();
const std::string kFragmentShaderSourceOrange =
    load_shader_source("shaders/fragment_orange.glsl").c_str();
const std::string kFragmentShaderSourceYellow =
    load_shader_source("shaders/fragment_yellow.glsl").c_str();

// Callback to resize viewport
void framebuffer_size_callback(GLFWwindow* window, GLint width, GLint height) {
  (void)window;
  glViewport(0, 0, width, height);
}

// Function to process input
void process_input(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

GLint main() {
  std::cout << "Current working directory: " << std::filesystem::current_path()
            << std::endl;

  // Initialize GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // Intialize window object
  GLFWwindow* window =
      glfwCreateWindow(kWidth, kHeight, "Hello Triangle", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  // Intialized GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to load GLAD" << std::endl;
    glfwTerminate();
    return -1;
  }

  // Initialize and update viewport to actual window size
  GLint framebuffer_width, framebuffer_height;
  glfwGetFramebufferSize(window, &framebuffer_width, &framebuffer_height);
  glViewport(0, 0, framebuffer_width, framebuffer_height);

  // Initalize window to viewport resizing
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // Set to wireframe mode
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  // Instantiade GL IDs
  GLuint vao[3]{}, vbo[3]{}, ebo, shader_program[2];

  // Initialize raw vertices and index data
  GLfloat square_vertices[] = {
      0.5f,  0.5f,  0.0f,  // top right
      0.5f,  -0.5f, 0.0f,  // bottom right
      -0.5f, -0.5f, 0.0f,  // bottom left
      -0.5f, 0.5f,  0.0f   // top left
  };
  GLint square_indices[] = {
      // note that we start from 0!
      0, 1, 3,  // first triangle
      1, 2, 3   // second triangle
  };
  GLfloat triangle_vertices_1[] = {
      -0.5f,  0.5f, 0.0f,  // bottom left
      0.0f,   0.5f, 0.0f,  // bottom right
      -0.25f, 1.0f, 0.0f   // top
  };
  GLfloat triangle_vertices_2[] = {
      0.5f,  0.5f, 0.0f,  // bottom right
      0.0f,  0.5f, 0.0f,  // bottom left
      0.25f, 1.0f, 0.0f   // top
  };

  // Create shapes
  create_square(vao[0], vbo[0], ebo, square_vertices, sizeof(square_vertices),
                square_indices, sizeof(square_indices));
  create_triangle(vao[1], vbo[1], triangle_vertices_1,
                  sizeof(triangle_vertices_1));
  create_triangle(vao[2], vbo[2], triangle_vertices_2,
                  sizeof(triangle_vertices_2));

  // Initialize shader programs
  shader_program[0] = create_shader_program(
      kVertexShaderSource.c_str(), kFragmentShaderSourceOrange.c_str());
  shader_program[1] = create_shader_program(
      kVertexShaderSource.c_str(), kFragmentShaderSourceYellow.c_str());

  // Render loop
  while (!glfwWindowShouldClose(window)) {
    process_input(window);

    glClear(GL_COLOR_BUFFER_BIT);
    draw_square(shader_program[0], vao[0]);
    draw_triangle(shader_program[0], vao[1]);
    draw_triangle(shader_program[1], vao[2]);

    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  // Close GLFW
  glfwTerminate();
  return 0;
}
