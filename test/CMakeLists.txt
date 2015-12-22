# Enable ctest
enable_testing()

# `check` command to run all unit tets.
add_custom_target(check
  COMMAND ctest --output-on-failure
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "Build and then run all the tests and examples."
)

# `gxy_add_test` function for adding new tests.
function(gxy_add_test TEST_NAME)
  cmake_parse_arguments(TEST "" "" "SOURCES;LIBRARIES" ${ARGN})

  add_test(NAME test.${TEST_NAME} COMMAND ${TEST_NAME})
  add_executable(${TEST_NAME} ${TEST_SOURCES})
  target_link_libraries(${TEST_NAME} ${TEST_LIBRARIES})
endfunction()

# Sub-folders.
add_subdirectory(ast)
add_subdirectory(components)
add_subdirectory(utils/meta)

# Unit tests.
gxy_add_test(googletest
  SOURCES test_googletest.cpp
  LIBRARIES gtest_main
)

gxy_add_test(googlemock
  SOURCES test_googletest.cpp
  LIBRARIES gmock_main
)

gxy_add_test(yaml-cpp
  SOURCES test_yamlcpp.cpp
  LIBRARIES
    ${YAMLCPP_LIBRARY}
    gtest_main
)

