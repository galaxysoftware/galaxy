# Setup Project.
cmake_minimum_required(VERSION 3.0)
project(galaxy CXX)
message("Begin project galaxy.")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

if (CMAKE_BUILD_TYPE STREQUAL "")
  message("Defaulting to debug build.")
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Options
option(GXY_ENABLE_VALGRIND "Run the unit tests and examples under Valgrind if it is found." OFF)

# Required modules.
include(CMakeParseArguments)
include(CTest)
include(ProcessorCount)

include(AddCompilerFlag)
include(CreateSyntasticConfig)

# Required packages.
find_package(Boost 1.60 REQUIRED COMPONENTS system filesystem)
find_package(YamlCpp REQUIRED)

if (GXY_ENABLE_VALGRIND)
  find_package(Valgrind REQUIRED)
endif()

set(GLXW_LIBRARIES "")
if(UNIX AND NOT APPLE)
  add_subdirectory(ext/glxw)
  set(GLXW_LIBRARIES "glxw;dl")
endif()

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

  ${CMAKE_CURRENT_BINARY_DIR}/ext/glxw/include

  ${Boost_INCLUDE_DIRS}
  ${YAMLCPP_INCLUDE_DIR}
)

# Compiler flags.
add_compiler_flag(CXX
  CLANG
    -std=c++1z
#    -fno-rtti
    -fdiagnostics-color=always
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

