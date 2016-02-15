# CMakeLists.txt for component/
add_subdirectory(utils)

add_library(component OBJECT
  background.cpp
  transform.cpp
)

