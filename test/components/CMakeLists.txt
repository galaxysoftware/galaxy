# Unit tests for components.
gxy_add_test(component.empty_data
  SOURCES test_empty_data.cpp
  LIBRARIES gtest_main
)

gxy_add_test(component.name
  SOURCES test_name.cpp
  LIBRARIES gtest_main
)

gxy_add_test(component.transform
  SOURCES
    test_transform.cpp
    ${CMAKE_SOURCE_DIR}/src/component/transform.cpp
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

