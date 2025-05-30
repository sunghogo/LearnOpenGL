#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::string load_shader_source(const std::string& filePath) {
  std::ifstream file(filePath);
  if (!file.is_open()) {
    std::cerr << "Failed to open shader file: " << filePath << std::endl;
    return "";
  }

  std::stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}
