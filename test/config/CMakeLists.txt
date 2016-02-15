# Unit tests for loading a config.
add_subdirectory(ast)
add_subdirectory(yaml)

gxy_add_test(config.load
  SOURCES
    test_load.cpp
    $<TARGET_OBJECTS:component>
    $<TARGET_OBJECTS:component.utils>
    $<TARGET_OBJECTS:config>
    $<TARGET_OBJECTS:config.ast>
    $<TARGET_OBJECTS:utils>
  LIBRARIES
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${YAMLCPP_LIBRARY}
    gtest_main
)

gxy_add_test(config.parse_error
  SOURCES
    test_parse_error.cpp
  LIBRARIES
    gtest_main
)

