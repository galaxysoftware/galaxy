# Unit tests for the game's core component.
gxy_add_test(game.component
  SOURCES
    test_component.cpp
    $<TARGET_OBJECTS:component>
    $<TARGET_OBJECTS:game>
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

gxy_add_test(game.entity
  SOURCES
    test_entity.cpp
    $<TARGET_OBJECTS:component>
    $<TARGET_OBJECTS:component.utils>
    $<TARGET_OBJECTS:config>
    $<TARGET_OBJECTS:config.ast>
    $<TARGET_OBJECTS:game>
  LIBRARIES
    gtest_main
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${YAMLCPP_LIBRARY}
)

gxy_add_test(game.scene
  SOURCES
    test_scene.cpp
    $<TARGET_OBJECTS:component>
    $<TARGET_OBJECTS:component.utils>
    $<TARGET_OBJECTS:config.ast>
    $<TARGET_OBJECTS:game>
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

gxy_add_test(game.load
  SOURCES
    test_load.cpp
    $<TARGET_OBJECTS:component>
    $<TARGET_OBJECTS:component.utils>
    $<TARGET_OBJECTS:config>
    $<TARGET_OBJECTS:config.ast>
    $<TARGET_OBJECTS:game>
    $<TARGET_OBJECTS:utils>
  LIBRARIES
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${YAMLCPP_LIBRARY}
    gtest_main
)

