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

TEST (TestMyString, TestStrCmp)
{
    int res = 0;
    mystring::mystring str1 ("Hello, ");
    mystring::mystring str2 ("world!");
    mystring::mystring str3 ("world! ");
    mystring::mystring str4 ("");

    res = mystring::strcmp (str1, str1);
    ASSERT_EQ (res, 0);

    res = mystring::strcmp (str1, str2);
    ASSERT_NE (res, 0);

    res = mystring::strcmp (str1, str3);
    ASSERT_NE (res, 0);

    res = mystring::strcmp (str2, str3);
    ASSERT_EQ (res, -1);

    res = mystring::strcmp (str1, str4);
    ASSERT_GT (res, 0);

    res = mystring::strcmp (str4, str1);
    ASSERT_LT (res, 0);
}

TEST (TestMyString, TestOperatorEqEq)
{
    bool res = false;
    mystring::mystring str1 ("Hello, ");
    mystring::mystring str2 ("world!");
    mystring::mystring str3 ("world! ");
    mystring::mystring str4 ("");

    res = (str1 == str1);
    ASSERT_TRUE (res);
    res = (str1 == str2);
    ASSERT_FALSE (res);

    res = (str1 == str3);
    ASSERT_FALSE (res);

    res = (str2 == str3);
    ASSERT_FALSE (res);

    res = (str1 == str4);
    ASSERT_FALSE (res);
}

TEST (TestMyString, TestInequalities)
{
    bool res = false;
    mystring::mystring str1 ("Hello, ");
    mystring::mystring str2 ("world!");
    mystring::mystring str3 ("world! ");
    mystring::mystring str4 ("");
    mystring::mystring str5 ("bb");
    mystring::mystring str6 ("aaaa");
    // operator<
    res = (str2 < str3);
    ASSERT_TRUE (res);

    res = (str3 < str2);
    ASSERT_FALSE (res);

    res = (str1 < str3);
    ASSERT_TRUE (res);

    res = (str6 < str5);
    ASSERT_TRUE (res);

    // operator>

    res = (str2 > str3);
    ASSERT_FALSE (res);

    res = (str3 > str2);
    ASSERT_TRUE (res);

    res = (str1 > str3);
    ASSERT_FALSE (res);

    res = (str5 > str6);
    ASSERT_TRUE (res);

    // operator<=

    res = (str2 <= str3);
    ASSERT_TRUE (res);

    res = (str3 <= str2);
    ASSERT_FALSE (res);

    res = (str1 <= str3);
    ASSERT_TRUE (res);

    res = (str1 <= str1);
    ASSERT_TRUE (res);

    res = (str4 <= str4);
    ASSERT_TRUE (res);

    res = (str6 <= str5);
    ASSERT_TRUE (res);

    // operator>=

    res = (str2 >= str3);
    ASSERT_FALSE (res);

    res = (str3 >= str2);
    ASSERT_TRUE (res);

    res = (str1 >= str3);
    ASSERT_FALSE (res);

    res = (str1 >= str1);
    ASSERT_TRUE (res);

    res = (str4 >= str4);
    ASSERT_TRUE (res);

    res = (str5 >= str6);
    ASSERT_TRUE (res);

    // operator!=

    res = (str1 != str1);
    ASSERT_FALSE (res);

    res = (str1 != str2);
    ASSERT_TRUE (res);

    res = (str2 != str3);
    ASSERT_TRUE (res);

    res = (str1 != str4);
    ASSERT_TRUE (res);
}

TEST (TestMyString, TestCopyCtor)
{
    bool res = false;
    mystring::mystring str1 ("Hello, world!");
    mystring::mystring str2 (str1);

    res = (str1 == str2);
    ASSERT_TRUE (res);

    mystring::mystring str3 ("");
    mystring::mystring str4 (str3);

    res = (str3 == str4);
    ASSERT_TRUE (res);
}

TEST (TestMyString, TestCopyAssiggnment)
{
    bool res = false;
    mystring::mystring str1 ("Hello, world!");
    mystring::mystring str2 ("Other string");

    str2 = str1;
    res  = (str2 == str1);
    ASSERT_TRUE (res);

    mystring::mystring str3 ("");
    str2 = str3;
    res  = (str2 == str3);
    ASSERT_TRUE (res);
}

int main (int argc, char *argv[])
{
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS ();
}