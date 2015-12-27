#ifndef UTILS_SCOPED_DIRECTORY_H
#define UTILS_SCOPED_DIRECTORY_H

#include <boost/filesystem/path.hpp>

namespace gxy {

// Wrapper around creating and destroying a directory. Will remove the directory if it
// already exists.
class scoped_directory
{
public:
  scoped_directory(boost::filesystem::path name);
  ~scoped_directory();

  auto name() const -> boost::filesystem::path;

private:
  boost::filesystem::path name_;
};

} // namespace gxy

#endif // UTILS_SCOPED_DIRECTORY_H

