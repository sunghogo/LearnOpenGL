#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "graphics/shaders.h"
#include "graphics/create.h"
#include "graphics/draw.h"

// Window dimensions
const GLint kWidth = 800, kHeight = 600;

// Shader file paths
const GLchar* kVertexShaderPath = "shaders/vertex.glsl";
const GLchar* kFragmentShaderPath = "shaders/fragment.glsl";

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
  // Initialize GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // Intialize window object
  GLFWwindow* window = glfwCreateWindow(kWidth, kHeight, "Shaders", NULL, NULL);
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

  // Instantiade GL IDs
  GLuint vao, vbo, ebo;

  // Initialize raw vertices data
  GLfloat triangle_vertices[] = {
      // positions        // colors
      -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom left
      0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom right
      0.0f,  0.5f,  0.0f, 0.0f, 0.0f, 1.0f,  // top
  };

  // Create shapes
  graphics::CreateTriangle(vao, vbo, triangle_vertices,
                           sizeof(triangle_vertices), 2);

  // Initialize shader programs
  graphics::Shader shader =
      graphics::Shader(kVertexShaderPath, kFragmentShaderPath);
  shader.Use();

  // Render loop
  while (!glfwWindowShouldClose(window)) {
    process_input(window);

    // Clear image
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Change color over time
    GLfloat time_value = glfwGetTime();
    GLfloat x_offset = sin(time_value) / 2.0f;
    shader.SetFloat("x_offset", x_offset);

        // GLint vertex_color_location = shader.GetUniformLocation("vertex_color");
    // glUniform4f(vertex_color_location, 0.0f, green_value, 0.0f, 1.0f);

    graphics::DrawTriangle(vao);

    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  // Close GLFW
  glfwTerminate();
  return 0;
}
