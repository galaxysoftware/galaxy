# Unit tests for component/utils
gxy_add_test(component.utils.empty_data
  SOURCES
    test_empty_data.cpp
    ${CMAKE_SOURCE_DIR}/src/component/utils/empty_data.cpp
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

gxy_add_test(component.utils.for_each
  SOURCES test_for_each.cpp
  LIBRARIES gtest_main
)

