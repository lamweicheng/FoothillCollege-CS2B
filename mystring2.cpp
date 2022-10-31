/*
Private Data Member
1) str
A c - string data member which implemented as a character dynamic array.It will expands as
more and more element being added.It is the only data member in the class and will
be called from every functions from the class.Every function from the class could
access this data member and modify the value of it.str always represents a valid
null - terminated c - string


Complex functions
myString::myString(const char* inStr)
This constructor will takes in a pointer argument called inStr pointing to
the object.It will first create a space to copy object to str(a private member data).
and then copy to it to the destination.The memory created is equal to length of the object + 1


MyString MyString::operator= (const MyString & right)
1st of Part of Big - 3. This operator= is being overloaded and it takes one argument reference
to object and is kept const.If the value of the calling object is same as right, the memory
of it will not be destroyed.If they are different, the operator will first deletes the memory
location that the data member of the calling object is pointing to, then assign memory of
appropriate length according to size of object reference.Then copy object of specified
length to private data memberand return pointer to object.


istream & operator>> (istream & in, MyString & readMe)
This overloaded extraction operator will skip any leading spaces and then read characters
into the string up to the first whitespace character.This operator will read
the input into a non - dynamic array, then strcpy() is used to copy it into str data member.
The correct amount of memory will also be allocated.


void MyString::read(istream & readMe, char delimit)
The read() function will allow the client programmer to specify the delimiting character
(the character at which reading will stop).It should work just like the getline() function
works for c - strings; that is, it should place everything up to but not including the delimiting
character into the calling object, and it should also consume(and discard) the delimiting character.
This is a void function that will take two arguments, a streamand the delimiting character.It
should not skip leading spaces.The limit of 127 characters imposed on the >> function
above also applies to this function.in >> temp function is called to read the input into a non - dynamic array, then strcpy() is used
to copy it into MyString class data member.


const MyString operator+ (const MyString & left, const MyString & right)
This function takes two parameter which is reference to myString left& rightand they are both declared const.
This operator does myString concatenationand is able to handle either myString objects
or C - strings on either side of the operator. The memory is allocated to hold the
new myString.strcpy() gets the left operand into the result myString, and then strcat() to
append the right operand.Both strcpy() and strcat() is used as if they are void even
though they do have return values.


MyString MyString::operator+= (const MyString & right)
Overloaded the shorthand += to combine concatenation and assignment.The argument to
overloaded += operator is reference to right myString object.Dynamic allocate memory
to hold size of the new myString and strcat() to append the right operand.

*/


#pragma warning(disable:4996)
#include <iostream>
#include <cassert>
#include "mystring2.h"
using namespace std;

namespace cs_mystring
{
    MyString::MyString(const char* inString)
    {
        str = new char[strlen(inString) + 1];
        strcpy(str, inString);
    }








    MyString::MyString()
    {
        str = new char[1];
        strcpy(str, "");
    }







    MyString::MyString(const MyString& copyMe)
    {
        str = new char[strlen(copyMe.str) + 1];
        strcpy(str, copyMe.str);
    }






    MyString::~MyString()
    {
        delete[] str;
    }







    ostream& operator<<(ostream& out, const MyString& printMe)
    {
        out << printMe.str;
        return out;
    }







    istream& operator>>(istream& in, MyString& readMe)
    {
        delete[] readMe.str;
        char tempStr[MyString::MAX_INPUT_SIZE + 1];
        in >> tempStr;
        readMe.str = new char[strlen(tempStr) + 1];
        strcpy(readMe.str, tempStr);
        return in;
    }







    void MyString::read(istream& in, char delimiter)
    {
        char tempStr[MyString::MAX_INPUT_SIZE + 1];

        in.getline(tempStr, MyString::MAX_INPUT_SIZE + 1, delimiter);
        delete[] str;
        str = new char[strlen(tempStr) + 1];
        strcpy(str, tempStr);
    }







    char MyString::operator[](int index) const
    {
        assert(index >= 0 && index < strlen(str));
        return str[index];
    }







    char& MyString::operator[](int index)
    {
        assert(index >= 0 && index < strlen(str));
        return str[index];
    }







    bool operator<(const MyString& left, const MyString& right)
    {
        return strcmp(left.str, right.str) < 0;
    }





    bool operator>(const MyString& left, const MyString& right)
    {
        return strcmp(left.str, right.str) > 0;
    }





    bool operator<=(const MyString& left, const MyString& right)
    {
        return strcmp(left.str, right.str) <= 0;
    }





    bool operator>=(const MyString& left, const MyString& right)
    {
        return strcmp(left.str, right.str) >= 0;
    }





    bool operator==(const MyString& left, const MyString& right)
    {
        return strcmp(left.str, right.str) == 0;
    }





    bool operator!=(const MyString& left, const MyString& right)
    {
        return strcmp(left.str, right.str) != 0;
    }







    MyString MyString::operator=(const MyString& right)
    {
        if (this != &right) {
            delete[] str;
            str = new char[strlen(right.str) + 1];
            strcpy(str, right.str);
        }

        return *this;
    }







    MyString operator+(const MyString& left, const MyString& right)
    {
        MyString tempStr;
        delete[] tempStr.str;
        tempStr.str = new char[strlen(left.str) + strlen(right.str) + 1];
        strcpy(tempStr.str, left.str);
        strcat(tempStr.str, right.str);
        return tempStr;
    }







    MyString MyString::operator+=(const MyString& right)
    {
        *this = *this + right;
        return *this;
    }







    int MyString::length() const
    {
        return strlen(str);
    }
}


/*-----------------------------Paste of run #5 --------------------------------
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Now reading MyStrings from file

----- first, word by word
Read string = The
Read string = first
Read string = time
Read string = we
Read string = will
Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

----- now, line by line
Read string = The  first  time  we  will
Read string =     read individual words, next
Read string = we read whole lines

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

----- Testing concatentation on MyStrings
outrageous + milk = outrageousmilk
milk +  = milk
 + cow = cow
cow + bell = cowbell

----- Testing concatentation between MyString and char *
abcde + XYZ = abcdeXYZ
XYZ + abcde = XYZabcde

----- Testing shorthand concat/assign on MyStrings
who += what = whowhatandwhowhat
what += WHEN = whatWHENandwhatWHEN
WHEN += Where = WHENWhereandWHENWhere
Where += why = WherewhyandWherewhy

----- Testing shorthand concat/assign using char *
I love  += programming = I love programming

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo

(process 20820) exited with code 0.
Press any key to close this window . . .
------------------------------------------------------------------------------*/