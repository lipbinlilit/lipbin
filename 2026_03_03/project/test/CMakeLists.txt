add_executable(test_long_number test_long_number.cpp)

target_link_libraries(test_long_number 
    LongNumberLib
)

target_include_directories(test_long_number PRIVATE ${CMAKE_SOURCE_DIR}/source)