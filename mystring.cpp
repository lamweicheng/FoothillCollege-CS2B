#pragma warning(disable:4996)
#include <iostream>
#include <cassert>
#include "mystring.h"
using namespace std;

namespace cs_mystring
{

    MyString::MyString(const char* inStr) {

        str = new char[strlen(inStr) + 1];
        strcpy(str, inStr);
    }






    MyString::MyString(){

        str = new char[1];
        strcpy(str, "");
    }

   




    MyString MyString::operator= (const MyString& right){

        if (this != &right)
        {
            delete[]str;
            str = new char[strlen(right.str) + 1];
            strcpy(str, right.str);
        }
        return *this;
    }






    MyString::MyString(const MyString& right){

        str = new char[strlen(right.str) + 1];
        strcpy(str, right.str);
    }






    MyString::~MyString(){

        delete[] str;
    }
    





    char MyString::operator[] (int index)const{

        assert(index >= 0 && index < strlen (str));
        return str[index];
    }






    char& MyString::operator[] (int index){

        assert(index >= 0 && index < strlen(str));
        return str[index];
    }






    ostream& operator<< (ostream& out, const MyString& right){

        out << right.str;
        return out;
    }






    int MyString::length()const{

        return (int)strlen(str);

    }






    bool operator< (const MyString& left, const MyString& right){

        return strcmp(left.str, right.str) < 0;
    }






    bool operator<= (const MyString& left, const MyString& right){

        return left < right || left == right;
    }






    bool operator> (const MyString& left, const MyString& right){

        return !(left == right) && !(left < right);
    }






    bool operator>= (const MyString& left, const MyString& right){

        return !(left < right);
    }






    bool operator== (const MyString& left, const MyString& right){

        return strcmp(left.str, right.str) == 0;

    }






    bool operator!= (const MyString& left, const MyString& right){

        return !(left == right);
    }  

}

/*-------------------------------Paste of Run a4_a1----------------------------
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between MyStrings
Comparing app to apple
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing apple to
    Is left < right? false
    Is left <= right? false
    Is left > right? true
    Is left >= right? true
    Does left == right? false
    Does left != right ? true
Comparing  to Banana
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing Banana to Banana
    Is left < right? false
    Is left <= right? true
    Is left > right? false
    Is left >= right? true
    Does left == right? true
    Does left != right ? false

----- Testing relations between MyStrings and char *
Comparing he to hello
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing why to wackity
    Is left < right? false
    Is left <= right? false
    Is left > right? true
    Is left >= right? true
    Does left == right? false
    Does left != right ? true

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is Binky
val is winky
after assign,  val is Binky

(process 2180) exited with code 0.
Press any key to close this window . . .


---------------------------------------------------------------------------*/