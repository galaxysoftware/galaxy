# Unit tests for components.
gxy_add_test(components.background
  SOURCES
    test_background.cpp
    ${CMAKE_SOURCE_DIR}/src/components/background.cpp
    ${CMAKE_SOURCE_DIR}/src/components/utils/empty_data.cpp
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

gxy_add_test(components.transform
  SOURCES
    test_transform.cpp
    ${CMAKE_SOURCE_DIR}/src/components/transform.cpp
    ${CMAKE_SOURCE_DIR}/src/components/utils/empty_data.cpp
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

