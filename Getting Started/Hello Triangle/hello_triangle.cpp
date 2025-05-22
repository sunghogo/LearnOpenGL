#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

const int kWidth = 800, kHeight = 600;
unsigned int VBO, EBO, VAO, shader_program;

const char* kVertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec3 pos;

void main()
{
    gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);
}
)";

const char* kFragmentShaderSource = R"(
#version 330 core
out vec4 frag_color;

void main() {
    frag_color = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
)";

// Callback to resize viewport
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  (void)window;
  glViewport(0, 0, width, height);
}

// Function to process input
void process_input(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

// Function to create vertices for center triangle
void create_triangle() {
  // float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f,
  // 0.0f};
  float vertices[] = {
      0.5f,  0.5f,  0.0f,  // top right
      0.5f,  -0.5f, 0.0f,  // bottom right
      -0.5f, -0.5f, 0.0f,  // bottom left
      -0.5f, 0.5f,  0.0f   // top left
  };
  unsigned int indices[] = {0, 1, 3, 1, 2, 3};

  // Compile vertex shader
  unsigned int vertex_shader;
  vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, &kVertexShaderSource, NULL);
  glCompileShader(vertex_shader);

  // Compile fragment shader
  unsigned int fragment_shader;
  fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader, 1, &kFragmentShaderSource, NULL);
  glCompileShader(fragment_shader);

  // Validate shaders
  int success_vertex, success_fragment;
  char info_log_vertex[512], info_log_fragment[512];
  glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success_vertex);
  glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success_fragment);
  if (!success_vertex) {
    glGetShaderInfoLog(vertex_shader, 512, NULL, info_log_vertex);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED" << info_log_vertex
              << std::endl;
  } else if (!success_fragment) {
    glGetShaderInfoLog(fragment_shader, 512, NULL, info_log_fragment);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED"
              << info_log_fragment << std::endl;
  }

  // Create and link shader program
  shader_program = glCreateProgram();
  glAttachShader(shader_program, vertex_shader);
  glAttachShader(shader_program, fragment_shader);
  glLinkProgram(shader_program);

  // Validate shader program
  int success_shader;
  char info_log_shader[512];
  glGetProgramiv(shader_program, GL_LINK_STATUS, &success_shader);
  if (!success_shader) {
    glGetProgramInfoLog(shader_program, 512, NULL, info_log_shader);
    std::cout << "ERROR::SHADER_PROGRAM::LINKING_FAILED" << info_log_shader
              << std::endl;
  }

  // Delete compiled shaders after linking
  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);

  // Generate and configure vertex buffer and array objects
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
  // clang-format off
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                                (void*)0);
            glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  // clang-format on
  glBindVertexArray(0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Draw triangle
void draw_triangle() {
  glUseProgram(shader_program);
  glBindVertexArray(VAO);
  // glDrawArrays(GL_TRIANGLES, 0, 3);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

int main() {
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
  int framebuffer_width, framebuffer_height;
  glfwGetFramebufferSize(window, &framebuffer_width, &framebuffer_height);
  glViewport(0, 0, framebuffer_width, framebuffer_height);

  // Initalize window to viewport resizing
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // Initialize triangle
  create_triangle();
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  // Render loop
  while (!glfwWindowShouldClose(window)) {
    process_input(window);

    glClear(GL_COLOR_BUFFER_BIT);
    draw_triangle();

    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  // Close GLFW
  glfwTerminate();
  return 0;
}
