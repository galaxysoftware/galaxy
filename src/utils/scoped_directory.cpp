#include "utils/scoped_directory.h"

#include <boost/filesystem/operations.hpp>

namespace gxy {

namespace {

auto remove_if_exists(const boost::filesystem::path &path) -> void
{
  if (boost::filesystem::exists(path)) {
    boost::filesystem::remove_all(path);
  }
}

} // unnamed namespace

scoped_directory::scoped_directory(boost::filesystem::path name)
: name_(std::move(name))
{
  remove_if_exists(name_);
  boost::filesystem::create_directory(name_);
}

scoped_directory::~scoped_directory()
{
  remove_if_exists(name_);
}

auto scoped_directory::name() const -> boost::filesystem::path
{
  return name_;
}

} // namespace gxy

