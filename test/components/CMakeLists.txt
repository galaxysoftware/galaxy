# Unit tests for components.
gxy_add_test(components.empty_data
  SOURCES test_empty_data.cpp
  LIBRARIES gtest_main
)

gxy_add_test(components.for_each
  SOURCES test_for_each.cpp
  LIBRARIES gtest_main
)

gxy_add_test(components.name
  SOURCES test_name.cpp
  LIBRARIES gtest_main
)

gxy_add_test(components.parse
  SOURCES
    test_parse.cpp
    ${CMAKE_SOURCE_DIR}/src/components/transform.cpp
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

gxy_add_test(components.transform
  SOURCES
    test_transform.cpp
    ${CMAKE_SOURCE_DIR}/src/components/transform.cpp
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

