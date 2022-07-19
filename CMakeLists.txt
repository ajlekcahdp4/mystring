cmake_minimum_required (VERSION 3.23)

project (mystring)

set (MYSTRING_RESOURCES
    main.cc
)

add_executable (mystring ${MYSTRING_RESOURCES})


find_package(GTest)
enable_testing()

find_program(BASH_PROGRAM bash)
if(BASH_PROGRAM)
    add_test(NAME TestLFU.testEndToEnd COMMAND ${BASH_PROGRAM} ${CMAKE_CURRENT_SOURCE_DIR}/test.sh "$<TARGET_FILE:lfucpp>" ${CMAKE_CURRENT_SOURCE_DIR})
endif()