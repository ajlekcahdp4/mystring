#pragma once

#include <cstring>

#include "pow_two.hpp"
namespace mystring
{

using size_type = size_t;

class mystring {
  private:
    char *data_;
    size_type size_;
    size_type capacity_;

  public:
    mystring (const char *data)
    {
        size_     = std::strlen (data);
        capacity_ = power_two::nearest_from_above_power_of_two (size_);
        data_     = new char[capacity_];
        std::strncpy (data_, data, size_);
    }

    mystring (const mystring &deststr) : size_ (deststr.size_)
    {
        capacity_ = power_two::nearest_from_above_power_of_two (size_);
        data_     = new char[capacity_];
        std::strncpy (data_, deststr.data_, size_);
    }

    virtual ~mystring () { delete[] data_; }

    size_type size () const { return size_; }

    char *c_str () const { return data_; }

    mystring operator= (const mystring &other)
    {
        if ( other.size_ + 1 >= capacity_ )
        {
            delete[] data_;
            capacity_ = other.capacity_;
            data_     = new char[capacity_];
        }
        else
        {
            for ( int i = 0; i < size_; i++ )
                data_[i] = '\0';
        }

        size_ = other.size_;
        std::strncpy (data_, other.data_, size_);
        return *this;
    }
};

int strcmp (const mystring &str1, const mystring &str2)
{
    int diff = str1.size () - str2.size ();
    return diff == 0 ? std::strncmp (str1.c_str (), str2.c_str (), str1.size ()) : diff;
}

bool operator== (const mystring &str1, const mystring &str2) { return !strcmp (str1, str2); }

}   // namespace mystring