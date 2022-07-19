cmake_minimum_required (VERSION 3.23)

project (mystring)

set (MYSTRING_RESOURCES
    main.cc
)


add_executable (mystring ${MYSTRING_RESOURCES})

find_package(GTest)
include(GoogleTest)
enable_testing()

target_include_directories(mystring PRIVATE ${GTEST_INCLUDE_DIRECTORIES})
target_link_libraries(mystring ${GTEST_BOTH_LIBRARIES})
gtest_discover_tests(mystring)
