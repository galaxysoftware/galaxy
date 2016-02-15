# Unit tests for the AST.
gxy_add_test(config.ast.component
  SOURCES
    test_component.cpp
    $<TARGET_OBJECTS:component>
    $<TARGET_OBJECTS:component.utils>
    $<TARGET_OBJECTS:config.ast>
  LIBRARIES
    ${YAMLCPP_LIBRARY}
    gtest_main
)

gxy_add_test(config.ast.entity
  SOURCES
    test_entity.cpp
    $<TARGET_OBJECTS:component>
    $<TARGET_OBJECTS:component.utils>
    $<TARGET_OBJECTS:config.ast>
  LIBRARIES
    ${YAMLCPP_LIBRARY}
    gtest_main
)

gxy_add_test(config.ast.scene
  SOURCES
    test_scene.cpp
    $<TARGET_OBJECTS:component>
    $<TARGET_OBJECTS:component.utils>
    $<TARGET_OBJECTS:config.ast>
  LIBRARIES
    ${YAMLCPP_LIBRARY}
    gtest_main
)

