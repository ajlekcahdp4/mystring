#pragma once

#include <cstring>
#include <stdexcept>

#include "pow_two.hpp"
namespace mystring
{

using size_type = size_t;

struct large_
{
    size_type capacity_;
    size_type padding_;
};
class string {
  private:
    char *data_;
    size_type size_;
    union
    {
        struct large_ large_;
        char small_[sizeof (large_)];
    } flex_;

  public:
    string (const char *data)
    {
        flex_.large_.capacity_ = 0;
        flex_.large_.padding_  = 0;

        size_ = std::strlen (data);

        if ( size_ >= sizeof (struct large_) )
        {
            flex_.large_.capacity_ = power_two::nearest_from_above_power_of_two (size_);
            data_                  = new char[flex_.large_.capacity_];
        }
        else
            data_ = flex_.small_;

        std::strncpy (data_, data, size_);
    }

    string (const string &deststr) : size_ (deststr.size_)
    {
        flex_.large_.capacity_ = 0;
        flex_.large_.padding_  = 0;

        if ( size_ >= sizeof (struct large_) )
        {
            flex_.large_.capacity_ = power_two::nearest_from_above_power_of_two (size_);
            data_                  = new char[flex_.large_.capacity_];
        }
        else
            data_ = flex_.small_;

        std::strncpy (data_, deststr.data_, size_);
    }

    virtual ~string ()
    {
        if ( size_ >= 16 )
            delete[] data_;
    }

    size_type size () const { return size_; }

    char *c_str () const { return data_; }

    string operator= (const string &other)
    {
        if ( other.size_ >= sizeof (struct large_) )
        {
            if ( size_ >= sizeof (struct large_) )
                delete[] data_;

            flex_.large_.capacity_ = other.flex_.large_.capacity_;
            data_                  = new char[flex_.large_.capacity_];
        }
        else
        {
            if ( size_ >= sizeof (struct large_) )
                delete[] data_;

            data_ = flex_.small_;
        }

        size_ = other.size_;
        std::strncpy (data_, other.data_, size_);

        return *this;
    }

    // if pos > size(), the behavior is undefined
    char &operator[] (size_type pos) { return data_[pos]; }

    char &at (size_type pos)
    {
        if ( pos >= size_ )
            throw std::out_of_range ("out of range at at ()");
        return data_[pos];
    }

    void operator+= (const string &other)
    {
        size_t old_size = size_;
        size_ += other.size_;

        char *buf = nullptr;
        if ( size_ >= sizeof (struct large_) )
            buf = new char[size_];
        else
            buf = flex_.small_;   // be carefull

        std::strncpy (buf, data_, old_size);
        std::strncpy (buf + old_size, other.data_, other.size_);

        if ( old_size >= sizeof (struct large_) )
            delete[] data_;
        data_ = buf;
    }
};

int strcmp (const string &str1, const string &str2)
{
    int size_diff    = str1.size () - str2.size ();
    int content_diff = std::strncmp (str1.c_str (), str2.c_str (), str1.size ());

    if ( !content_diff )
        return size_diff;
    return content_diff;
}

bool operator== (const string &str1, const string &str2) { return !strcmp (str1, str2); }

bool operator> (const string &str1, const string &str2)
{
    int res = strcmp (str1, str2);
    return (res > 0);
}

bool operator>= (const string &str1, const string &str2)
{
    int res = strcmp (str1, str2);
    return (res >= 0);
}

bool operator< (const string &str1, const string &str2)
{
    int res = strcmp (str1, str2);
    return (res < 0);
}

bool operator<= (const string &str1, const string &str2)
{
    int res = strcmp (str1, str2);
    return (res <= 0);
}

bool operator!= (const string &str1, const string str2) { return !(str1 == str2); }

}   // namespace mystring