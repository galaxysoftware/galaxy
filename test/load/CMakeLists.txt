# Unit tests for loading a config.
gxy_add_test(load.load
  SOURCES
    test_load.cpp
    ${CMAKE_SOURCE_DIR}/src/load/ast/component.cpp
    ${CMAKE_SOURCE_DIR}/src/load/ast/entity.cpp
    ${CMAKE_SOURCE_DIR}/src/load/load.cpp
    ${CMAKE_SOURCE_DIR}/src/components/transform.cpp
    ${CMAKE_SOURCE_DIR}/src/utils/scoped_directory.cpp
  LIBRARIES
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${YAMLCPP_LIBRARY}
    gtest_main
)

