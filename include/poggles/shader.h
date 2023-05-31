#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "poggles/handle.h"
#include "poggles/poggles_export.hpp"

namespace poggles
{

// TODO Rethink this, should be a nicer interface for providing shaders
// Idea: filepath variant and a source() and name function?
// It'd be a class then though, and Lakin would be angry
// Also consider including shader type in here
struct ShaderSource
{
  std::string name;  // Name to identify which shader is being compiled
  std::string text;
};

class POGGLES_EXPORT shader_compile_exception : public std::runtime_error
{
public:
  explicit shader_compile_exception(const char* message)
      : std::runtime_error(message)
  {
  }

  explicit shader_compile_exception(const std::string& message)
      : std::runtime_error(message)
  {
  }
};

auto compileShader(shader_id shader,
                   std::filesystem::path path,
                   // defines provided in the form "NAME [optional value]"
                   std::initializer_list<std::string> const& defines = {})
    -> bool;

auto compileShader(shader_id shader,
                   ShaderSource source,
                   // defines provided in the form "NAME [optional value]"
                   std::initializer_list<std::string> const& defines = {})
    -> bool;

auto addDefinesToShaderSource(std::string source,
                              std::initializer_list<std::string> const& defines)
    -> std::string;

}  // namespace poggles
