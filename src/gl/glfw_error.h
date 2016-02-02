#ifndef GL_GLFW_ERROR_H
#define GL_GLFW_ERROR_H

#include <GLFW/glfw3.h>

#include <format.h>

#include <stdexcept>

namespace gxy::gl {

class glfw_error : public std::runtime_error
{
public:
  enum class code : int
  {
    unknown_error = 0,
    not_initialised = GLFW_NOT_INITIALIZED,
    no_current_context = GLFW_NO_CURRENT_CONTEXT,
    invalid_enum = GLFW_INVALID_ENUM,
    invalid_value = GLFW_INVALID_VALUE,
    out_of_memory = GLFW_OUT_OF_MEMORY,
    api_unavailable = GLFW_API_UNAVAILABLE,
    version_unavailable = GLFW_VERSION_UNAVAILABLE,
    platform_error = GLFW_PLATFORM_ERROR,
    format_unavailable = GLFW_FORMAT_UNAVAILABLE
  };

  explicit glfw_error(const char *what);
  explicit glfw_error(code error, const char *what);

  auto what() const noexcept -> const char * override;

private:
  fmt::MemoryWriter out_;
};

inline
glfw_error::glfw_error(const char *what)
: glfw_error(code::unknown_error, what)
{
}

inline
glfw_error::glfw_error(code error, const char *what)
: runtime_error(""),
  out_([=] {
    auto error_code([error] {
      switch(error) {
        case code::unknown_error: return "unknown_error";
        case code::not_initialised: return "not_initialised";
        case code::no_current_context: return "no_current_context";
        case code::invalid_enum: return "invalid_enum";
        case code::invalid_value: return "invalid_value";
        case code::out_of_memory: return "out_of_memory";
        case code::api_unavailable: return "api_unavailable";
        case code::version_unavailable: return "version_unavailable";
        case code::platform_error: return "platform_error";
        case code::format_unavailable: return "format_unavailable";
      };
    });

    static_assert(std::is_same<const char *, decltype(error_code())>{});

    fmt::MemoryWriter out;
    out.write("{}: {}", error_code(), what);
    return out;
  }())
{
}

inline
auto glfw_error::what() const noexcept -> const char *
{
  return out_.c_str();
}

} // namspace gl::gxy

#endif // GL_GLFW_ERROR_H

