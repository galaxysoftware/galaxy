#include "utils/scoped_directory.h"

#include <boost/filesystem/operations.hpp>

namespace gxy {

scoped_directory::scoped_directory(boost::filesystem::path name)
: name_(std::move(name))
{
  assert(! boost::filesystem::exists(name_));
  boost::filesystem::create_directory(name_);
}

scoped_directory::~scoped_directory()
{
  boost::filesystem::remove_all(name_);
}

auto scoped_directory::name() const -> boost::filesystem::path
{
  return name_;
}

} // namespace gxy

