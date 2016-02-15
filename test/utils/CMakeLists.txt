# Unit tests for utilities.
add_subdirectory(meta)

gxy_add_test(utils.box
  SOURCES test_box.cpp
)

gxy_add_test(utils.resource
  SOURCES test_resource.cpp
)

gxy_add_test(utils.scoped_directory
  SOURCES
    test_scoped_directory.cpp
    $<TARGET_OBJECTS:utils>
  LIBRARIES
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    gtest_main
)

gxy_add_test(utils.string_view
  SOURCES test_string_view.cpp
)

gxy_add_test(utils.throw_if
  SOURCES
    test_throw_if.cpp
  LIBRARIES
    gtest_main
)

