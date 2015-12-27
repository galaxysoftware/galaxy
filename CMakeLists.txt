# Setup Project.
cmake_minimum_required(VERSION 3.0)
project(galaxy CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

if (CMAKE_BUILD_TYPE STREQUAL "")
  message("Defaulting to debug build.")
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Required modules.
include(CMakeParseArguments)
include(CTest)
include(ProcessorCount)

include(AddCompilerFlag)
include(CreateSyntasticConfig)

# Required packages.
find_package(Boost 1.59 REQUIRED COMPONENTS system filesystem)
find_package(YamlCpp REQUIRED)

# Include path for project headers.
include_directories(
  ${CMAKE_SOURCE_DIR}/src
)

# Include path for system (external) headers.
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
    -Werror
    -Wall
    -Wextra
    -pedantic
)

# Disable unused variable warnings that can be introduced by removing assertions.
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wno-unused-parameter")

# Update .syntastic_cpp_config file.
create_syntastic_config()

# Required subdirectories.
add_subdirectory(ext/googletest)

add_subdirectory(test)

