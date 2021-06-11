cmake_policy(SET CMP0076 NEW)

set(TEST_PROJECT1 test_pract1)
add_executable(${TEST_PROJECT1})
target_sources(${TEST_PROJECT1} PUBLIC tests.c)
target_link_libraries(${TEST_PROJECT1} PUBLIC game cunit)

enable_testing()

add_test(NAME GameTest COMMAND ${TEST_PROJECT1})
