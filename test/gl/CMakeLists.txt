# Unit tests for gl.
gxy_add_test(gl.glfw_error
  SOURCES test_glfw_error.cpp
  LIBRARIES
    cppformat
    gtest_main
)

gxy_add_test(gl.context
  SOURCES
    test_context.cpp
    ${CMAKE_SOURCE_DIR}/test/gl/mockglfw.cpp
    ${CMAKE_SOURCE_DIR}/src/gl/context.cpp
    ${CMAKE_SOURCE_DIR}/src/gl/environment.cpp
  LIBRARIES
    cppformat
    gmock_main
)

gxy_add_test(gl.environment
  SOURCES
    test_environment.cpp
    ${CMAKE_SOURCE_DIR}/test/gl/mockglfw.cpp
    ${CMAKE_SOURCE_DIR}/test/gl/mockglxw.cpp
    ${CMAKE_SOURCE_DIR}/src/gl/environment.cpp
  LIBRARIES
    cppformat
    gmock_main
)

if(UNIX AND NOT APPLE)
  gxy_add_test(gl.environment.linux
    SOURCES
      test_environment_linux.cpp
      ${CMAKE_SOURCE_DIR}/test/gl/mockglfw.cpp
      ${CMAKE_SOURCE_DIR}/test/gl/mockglxw.cpp
      ${CMAKE_SOURCE_DIR}/src/gl/environment.cpp
    LIBRARIES
      cppformat
      gmock_main
  )
endif()

