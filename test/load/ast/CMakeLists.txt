# Unit tests for the AST.
gxy_add_test(load.ast.component
  SOURCES
    test_component.cpp
    ${CMAKE_SOURCE_DIR}/src/load/ast/component.cpp
    ${CMAKE_SOURCE_DIR}/src/components/transform.cpp
  LIBRARIES
    ${YAMLCPP_LIBRARY}
    gtest_main
)

