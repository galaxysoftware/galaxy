# Unit tests for component.
add_subdirectory(utils)

gxy_add_test(component.background
  SOURCES
    test_background.cpp
    $<TARGET_OBJECTS:component>
    $<TARGET_OBJECTS:component.utils>
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

gxy_add_test(component.transform
  SOURCES
    test_transform.cpp
    $<TARGET_OBJECTS:component>
    $<TARGET_OBJECTS:component.utils>
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

