#include <algorithm>
#include <cstring>
#include <gtest/gtest.h>
#include <iostream>

#include "mystring.hpp"

using namespace mystring;

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

TEST (TestMyString, TestOperatorEqEq)
{
    int res = 0;
    mystring::mystring str1 ("Hello, ");
    mystring::mystring str2 ("world!");
    mystring::mystring str3 ("world! ");
    mystring::mystring str4 ("");

    res = (str1 == str1);
    ASSERT_EQ (res, 0);

    res = (str1 == str2);
    ASSERT_NE (res, 0);

    res = (str1 == str3);
    ASSERT_NE (res, 0);

    res = (str2 == str3);
    ASSERT_EQ (res, -1);

    res = (str1 == str4);
    ASSERT_GT (res, 0);
}

int main (int argc, char *argv[])
{
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS ();
}