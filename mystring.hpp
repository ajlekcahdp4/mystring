#pragma once

#include <cstring>

#include "pow_two.hpp"
namespace mystring
{

class mystring {
  private:
    char *data_;
    size_t size_;
    size_t capacity_;

    size_t capacity () const { return capacity_; }

  public:
    mystring (const char *data)
    {
        size_     = std::strlen (data);
        capacity_ = power_two::nearest_from_above_power_of_two (size_);
        data_     = new char[capacity_];
        std::strncpy (data_, data, size_);
    }

    mystring (const mystring &deststr) : size_ (deststr.size ())
    {
        capacity_ = power_two::nearest_from_above_power_of_two (size_);
        data_     = new char[capacity_];
        std::strncpy (data_, deststr.c_str (), size_);
    }

    virtual ~mystring () { delete[] data_; }

    size_t size () const { return size_; }

    char *c_str () const { return data_; }

    mystring operator= (const mystring &other)
    {
        if ( other.size () + 1 >= capacity_ )
        {
            delete[] data_;
            capacity_ = other.capacity ();
            data_     = new char[capacity_];
        }
        else
        {
            for ( int i = 0; i < size_; i++ )
                data_[i] = '\0';
        }

        size_ = other.size ();
        std::strncpy (data_, other.c_str (), size_);
        return *this;
    }
};

long operator== (const mystring &str1, const mystring &str2)
{
    int diff = str1.size () - str2.size ();
    return diff == 0 ? std::strncmp (str1.c_str (), str2.c_str (), str1.size ()) : diff;
}

}   // namespace mystring