# Unit tests for component/utils
gxy_add_test(component.utils.empty_data
  SOURCES
    test_empty_data.cpp
    $<TARGET_OBJECTS:component.utils>
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

gxy_add_test(component.utils.for_each
  SOURCES test_for_each.cpp
  LIBRARIES gtest_main
)

