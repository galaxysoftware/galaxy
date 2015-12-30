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

  add_executable(${TEST_NAME} ${TEST_SOURCES})
  add_dependencies(check ${TEST_NAME})
  target_link_libraries(${TEST_NAME} ${TEST_LIBRARIES})

  if (GXY_ENABLE_VALGRIND)
    set(TEST_COMMAND ${Valgrind_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME})
  else()
    set(TEST_COMMAND "${TEST_NAME}")
  endif()

  add_test(NAME test.${TEST_NAME} COMMAND ${TEST_COMMAND})
endfunction()

# Sub-folders.
add_subdirectory(config)
add_subdirectory(config/ast)
add_subdirectory(config/yaml)
add_subdirectory(game)
add_subdirectory(components)
add_subdirectory(utils)
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

