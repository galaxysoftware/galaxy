# Unit tests for component.
gxy_add_test(component.background
  SOURCES
    test_background.cpp
    ${CMAKE_SOURCE_DIR}/src/component/background.cpp
    ${CMAKE_SOURCE_DIR}/src/component/utils/empty_data.cpp
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

gxy_add_test(component.transform
  SOURCES
    test_transform.cpp
    ${CMAKE_SOURCE_DIR}/src/component/transform.cpp
    ${CMAKE_SOURCE_DIR}/src/component/utils/empty_data.cpp
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

