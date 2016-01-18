# Unit tests for loading a config.
gxy_add_test(config.load
  SOURCES
    test_load.cpp
    ${CMAKE_SOURCE_DIR}/src/config/ast/component.cpp
    ${CMAKE_SOURCE_DIR}/src/config/ast/entity.cpp
    ${CMAKE_SOURCE_DIR}/src/config/ast/scene.cpp
    ${CMAKE_SOURCE_DIR}/src/config/load.cpp
    ${CMAKE_SOURCE_DIR}/src/components/background.cpp
    ${CMAKE_SOURCE_DIR}/src/components/transform.cpp
    ${CMAKE_SOURCE_DIR}/src/components/utils/empty_data.cpp
    ${CMAKE_SOURCE_DIR}/src/utils/scoped_directory.cpp
  LIBRARIES
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${YAMLCPP_LIBRARY}
    gtest_main
)

