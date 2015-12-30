# Unit tests for the AST.
gxy_add_test(config.ast.component
  SOURCES
    test_component.cpp
    ${CMAKE_SOURCE_DIR}/src/config/ast/component.cpp
    ${CMAKE_SOURCE_DIR}/src/components/transform.cpp
  LIBRARIES
    ${YAMLCPP_LIBRARY}
    gtest_main
)

gxy_add_test(config.ast.entity
  SOURCES
    test_entity.cpp
    ${CMAKE_SOURCE_DIR}/src/config/ast/component.cpp
    ${CMAKE_SOURCE_DIR}/src/config/ast/entity.cpp
    ${CMAKE_SOURCE_DIR}/src/components/transform.cpp
  LIBRARIES
    ${YAMLCPP_LIBRARY}
    gtest_main
)

gxy_add_test(config.ast.scene
  SOURCES
    test_scene.cpp
    ${CMAKE_SOURCE_DIR}/src/config/ast/component.cpp
    ${CMAKE_SOURCE_DIR}/src/config/ast/entity.cpp
    ${CMAKE_SOURCE_DIR}/src/config/ast/scene.cpp
    ${CMAKE_SOURCE_DIR}/src/components/transform.cpp
  LIBRARIES
    ${YAMLCPP_LIBRARY}
    gtest_main
)

