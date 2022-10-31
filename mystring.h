#ifndef mystring_h
#define mystring_h
#include <iostream>

namespace cs_mystring
{
    class MyString
    {
    public:

        MyString(const char* inStr);
        MyString();
        MyString operator= (const MyString& right);
        MyString(const MyString& right);
        ~MyString();
        int length() const;
        char operator[] (int index)const;
        char& operator[] (int index);
        friend std::ostream& operator<< (std::ostream& out, const MyString& right);
        friend bool operator< (const MyString& left, const MyString& right);
        friend bool operator<= (const MyString& left, const MyString& right);
        friend bool operator> (const MyString& left, const MyString& right);
        friend bool operator>= (const MyString& left, const MyString& right);
        friend bool operator== (const MyString& left, const MyString& right);
        friend bool operator!= (const MyString& left, const MyString& right);

    private:
        char* str;
    };
}
#endif