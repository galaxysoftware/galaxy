# Unit tests for components/utils
gxy_add_test(components.utils.empty_data
  SOURCES
    test_empty_data.cpp
    ${CMAKE_SOURCE_DIR}/src/components/utils/empty_data.cpp
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

gxy_add_test(components.utils.for_each
  SOURCES test_for_each.cpp
  LIBRARIES gtest_main
)

