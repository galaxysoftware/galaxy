# Enable ctest
enable_testing()

# Count the cores available (for paralellising the unit tests).
set(J 1)
if (NOT DEFINED ENV{TRAVIS})
  ProcessorCount(J)
  message("Found ${J} cores.")
endif()

# `check` command to run all unit tets.
add_custom_target(check
  COMMAND ctest --output-on-failure -j ${J}
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "Build and then run all the tests and examples."
)

# `gxy_add_test` function for adding new tests.
function(gxy_add_test TEST_NAME)
  cmake_parse_arguments(TEST "" "" "SOURCES;LIBRARIES" ${ARGN})

  # Come up with a name for the binary.
  set(TEST_EXECUTABLE "test.${TEST_NAME}")

  add_executable("${TEST_EXECUTABLE}" ${TEST_SOURCES})
  add_dependencies(check "${TEST_EXECUTABLE}")

  target_include_directories("${TEST_EXECUTABLE}" PUBLIC ${CMAKE_SOURCE_DIR}/test)
  target_link_libraries("${TEST_EXECUTABLE}" ${TEST_LIBRARIES})

  if (GXY_ENABLE_VALGRIND)
    set(TEST_COMMAND ${Valgrind_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/${TEST_EXECUTABLE})
  else()
    set(TEST_COMMAND "${TEST_EXECUTABLE}")
  endif()

  set(ARGS "")
  if (CMAKE_BUILD_TYPE STREQUAL "Release")
    # Skip death tests on release mode as assertions have been removed.
    set(ARGS "--gtest_filter=-*DeathTest.*")
  endif()

  add_test(NAME "${TEST_EXECUTABLE}" COMMAND ${TEST_COMMAND} ${ARGS})
endfunction()

# Sub-folders.
add_subdirectory(component)
add_subdirectory(config)
add_subdirectory(game)
add_subdirectory(gl)
add_subdirectory(utils)

# Unit tests.
gxy_add_test(boost.version
  SOURCES test_boost_version.cpp
  LIBRARIES gtest_main
)

if(UNIX AND NOT APPLE)
  gxy_add_test(glxw.init
    SOURCES test_glxw.cpp
    LIBRARIES
      ${OPENGL_LIBRARIES}
      ${GLXW_LIBRARY}
      gtest_main
  )
endif()

gxy_add_test(glfw
  SOURCES test_glfw.cpp
  LIBRARIES
    ${OPENGL_LIBRARIES}
    ${GLFW_LIBRARY}
    ${XINERAMA_LIBRARIES}
    gtest_main
)

if(NOT DEFINED ENV{TRAVIS})
  gxy_add_test(opengl
    SOURCES
      test_opengl.cpp
      ${CMAKE_SOURCE_DIR}/src/gl/context.cpp
      ${CMAKE_SOURCE_DIR}/src/gl/environment.cpp
    LIBRARIES
      cppformat
      ${OPENGL_LIBRARIES}
      ${GLFW_LIBRARY}
      gtest_main
  )
endif()

