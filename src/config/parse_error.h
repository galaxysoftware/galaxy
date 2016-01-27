#ifndef CONFIG_PARSE_ERROR_H
#define CONFIG_PARSE_ERROR_H

#include <stdexcept>

namespace gxy {

class parse_error : public std::runtime_error
{
public:
  parse_error();
};

inline
parse_error::parse_error()
: runtime_error("parse error")
{
}

} // namespace gxy

#endif // CONFIG_PARSE_ERROR_H

