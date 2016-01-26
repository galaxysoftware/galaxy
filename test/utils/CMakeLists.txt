# Unit tests for utilities.
gxy_add_test(utils.box
  SOURCES test_box.cpp
)

gxy_add_test(utils.is_valid
  SOURCES test_is_valid.cpp
)

gxy_add_test(utils.scoped_directory
  SOURCES
    test_scoped_directory.cpp
    ${CMAKE_SOURCE_DIR}/src/utils/scoped_directory.cpp
  LIBRARIES
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    gtest_main
)

