#include "utils/scoped_directory.h"

#include <boost/filesystem/operations.hpp>

#include <iostream>

namespace gxy {

namespace {

auto remove_if_exists(const boost::filesystem::path &path) -> void
{
  std::cerr << " - checking if already exists...";
  if (boost::filesystem::exists(path)) {
    std::cerr << "does and now removing." << std::endl;
    boost::filesystem::remove_all(path);
  } else {
    std::cerr << "doesn't." << std::endl;
  }
}

} // unnamed namespace

scoped_directory::scoped_directory(boost::filesystem::path name)
: name_(std::move(name))
{
  std::cerr << "construct scoped_directory for " << name.string() << std::endl;
  remove_if_exists(name_);
  std::cerr << " - creating directory." << std::endl;
  boost::filesystem::create_directory(name_);
  std::cerr << " - finished constructing." << std::endl;
}

scoped_directory::~scoped_directory()
{
  std::cerr << "beginning destruction." << std::endl;
  remove_if_exists(name_);
  std::cerr << " - finished destruction." << std::endl;
}

auto scoped_directory::name() const -> boost::filesystem::path
{
  return name_;
}

} // namespace gxy

