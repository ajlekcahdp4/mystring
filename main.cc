#include <algorithm>
#include <cstring>
#include <gtest/gtest.h>
#include <iostream>

#include "mystring.hpp"

TEST (TestMyString, TestInit)
{
    int res           = 0;
    const char *cstr1 = "Hello, world!";
    const char *cstr2 = "";
    size_t cstr_len_1 = std::strlen (cstr1);
    size_t cstr_len_2 = std::strlen (cstr2);

    mystring::mystring str1 (cstr1);
    res = cstr_len_1 - str1.size ();
    ASSERT_EQ (res, 0);

    res = std::strncmp (cstr1, str1.c_str (), cstr_len_1);
    ASSERT_EQ (res, 0);

    mystring::mystring str2 (cstr2);
    res = cstr_len_2 - str2.size ();
    ASSERT_EQ (res, 0);

    res = std::strncmp (cstr2, str2.c_str (), cstr_len_2);
    ASSERT_EQ (res, 0);
}

int main (int argc, char *argv[])
{
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS ();
}