#ifndef SHADERS_UTIL_H_
#define SHADERS_UTIL_H_

#include <string>

namespace graphics {
// Loads raw shader source from GLSL file.
//
// Args:
//  filePath: File path of shader starting from root directory of the lesson
//
// Returns:
//  Raw shader source code as std::string.
std::string load_shader_source(const std::string& filePath);
}  // namespace graphics

#endif
