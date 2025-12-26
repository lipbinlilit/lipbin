project(test)

add_executable(test_sort
    test_bubble.cpp
)

target_link_libraries(test_sort ${LIBRARY_NAME} gtest)

add_test(test_sort test_sort)