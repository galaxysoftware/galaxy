# Setup Project.
cmake_minimum_required(VERSION 3.0)
project(galaxy CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Required modules.
include(CMakeParseArguments)
include(CTest)

include(AddCompilerFlag)
include(CreateSyntasticConfig)

# Required packages.
find_package(Boost 1.59 REQUIRED)
find_package(YamlCpp REQUIRED)

# Include path for project headers.
include_directories(
  ${CMAKE_SOURCE_DIR}/src
)

# Include path for system headers.
include_directories(SYSTEM
  ${CMAKE_SOURCE_DIR}/ext/googletest/googletest/include
  ${CMAKE_SOURCE_DIR}/ext/googletest/googlemock/include

  ${CMAKE_SOURCE_DIR}/ext/eggs-variant/include
  ${CMAKE_SOURCE_DIR}/ext/glm

  ${Boost_INCLUDE_DIRS}
  ${YAMLCPP_INCLUDE_DIR}
)

# Compiler flags.
add_compiler_flag(CXX
  CLANG
    -std=c++1z
)

# Update .syntastic_cpp_config file.
create_syntastic_config()

# Required subdirectories.
add_subdirectory(ext/googletest)

add_subdirectory(test)

