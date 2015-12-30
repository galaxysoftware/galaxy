# Unit tests for the game's core components.
gxy_add_test(game.component
  SOURCES
    test_component.cpp
    ${CMAKE_SOURCE_DIR}/src/game/component.cpp
    ${CMAKE_SOURCE_DIR}/src/components/transform.cpp
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

