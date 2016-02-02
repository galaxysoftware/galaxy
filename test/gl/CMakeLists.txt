# Unit tests for gl.
gxy_add_test(gl.glfw_error
  SOURCES test_glfw_error.cpp
  LIBRARIES
    cppformat
    gtest_main
)

gxy_add_test(gl.environment
  SOURCES
    test_environment.cpp
    ${CMAKE_SOURCE_DIR}/test/gl/mockglfw.cpp
    ${CMAKE_SOURCE_DIR}/src/gl/environment.cpp
  LIBRARIES
    cppformat
    gmock_main
)

