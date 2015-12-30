# Unit tests for YAML serialisation extensions.
gxy_add_test(config.yaml.vec3
  SOURCES test_vec3.cpp
  LIBRARIES
    gtest_main
    ${YAMLCPP_LIBRARY}
)

