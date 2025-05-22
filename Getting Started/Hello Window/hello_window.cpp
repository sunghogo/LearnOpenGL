#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

const int kWidth = 800, kHeight = 600;

// Callback function to resize viewport according to window
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  (void)window;
  glViewport(0, 0, width, height);
}

// Callback function process inputs
void process_input(GLFWwindow* window) {
  (void)window;
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // Initialize window object
  GLFWwindow* window =
      glfwCreateWindow(kWidth, kHeight, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GFLW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  // Initialize GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // Initialize viewport
  glViewport(0, 0, kWidth, kHeight);

  // Initialize viewport resizing
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // Render Loop
  while (!glfwWindowShouldClose(window)) {
    process_input(window);

    // Set specific turqoise color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}
