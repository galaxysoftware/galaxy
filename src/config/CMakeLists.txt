# CMakeLists.txt for config/
add_subdirectory(ast)

add_library(config OBJECT
  load.cpp
)

