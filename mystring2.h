/*
Name : Isabelle Hong ; Class : C S 2B ; Date : 10/20/2021
Assignment 5 : Classes with Dynamic Memory 2
Instructor : Professor David Lee Harden
Name of the File : mystring2.h

The class MyString will handle constructing strings, reading/printing them on display,
accessing characters, read characters from file. The MyString object will also have 
the ability to copy its own when being copied. MyString class allow direct access
to the individual characters of the string and will do a range-check and assert
if the index is out of bounds. The client can declare and use My tring freely wihtout concern
for input,output, construction, indexing and concatenations of Mystrings are provided.
This class also supports all six relational operators ,they will compare MyString object
to other Mystring as well as MyString to c-strings. 

MyString(const char* str);
Postcondition: a MyString object is created and initialized to "inString".

MyString();
Postcondition: a MyString object is created and initialized to the empty string.

MyString operator= (const MyString& right);
Precondition: Takes reference of one paramater 
Postcondition: returns the same calling object if left and right operand are the same,
returns different object if left and right operand are different

MyString(const MyString& right);
Precondition: Takes on arguement which acts as pass-by-value parameter
Postcondition: a MyString object is created and initialized to "right".
Function will change its local copy of the object 

~MyString();
Precondition: Do not have return type and don't have any arguement.
Postcondition: automatically deallocate the meemory on the heap that the object is 
pointing to. 

int length() const;
Precondition: Don't have precondition
Postcondition: Returns the length of the string without changing the calling object 

char operator[] (int index)const;
Precondition: 0 <= index < length()
Postcondition: returns the index to myString specifying the char to that location 
which is const.

char& operator[] (int index);
Precondition: 0 <= index < length()
Postcondition: returns the index to myString specifying the char to that location.

friend std::ostream& operator<< (std::ostream& out, const MyString& right);
Precondition: If out is a file output stream, then out has already been connected
to a file. The ostream object out is ready for writing
Postcondition: The contents of "right" have been inserted into "out". 
Display characters and strings on the screen.

friend std::istream& operator>> (std::istream& in, MyString& readMe);
Precondition: If in is a file input stream, then in has already been connected 
to a file. The istream object in is ready for reading. 
Postcondition: Overloads the >> operator so it can be used to input characters of 
type MyString. Get input from a file and insert them into the code. MyString in the 
istream in has been read and assigned to MyString target

friend const MyString operator+ (const MyString& left, const MyString& right);
Postcondition: Concatenate MyString objects either on the left or thr right
side of the operator

void read(std::istream& readMe, char delimit);
Precondition: Take two arguement, an istream called readMe is ready for reading
and a delimitting character 
Postcondition: The sequence of characters in "readMe", terminated by "delimit",
have been extracted and stored in the calling object.

MyString operator+= (const MyString& right);
Precondition: left operand and right operand have been given values. 
Postcondition: Combine concatenation and assignment.

friend bool operator< (const MyString& left, const MyString& right);
Postcondition: Returns true if left < right, false otherwise

friend bool operator<= (const MyString& left, const MyString& right);
Postcondition: Returns true if left <= right, false otherwise.

friend bool operator> (const MyString& left, const MyString& right);
Postcondition: Returns true if left > right, false otherwise.

friend bool operator>= (const MyString& left, const MyString& right);
Postcondition: Returns true if left >= right, false otherwise.

friend bool operator== (const MyString& left, const MyString& right);
Postcondition: Returns true if left == right, false otherwise.

friend bool operator!= (const MyString& left, const MyString& right);
Postcondition: Returns true if left != right, false otherwise.

*/


#ifndef MYSTRING2_H
#define MYSTRING2_H
#include <iostream>

namespace cs_mystring {
    class MyString {
    public:
        MyString(const char* inString);
        MyString();
        MyString(const MyString& copyMe);
        ~MyString();
        friend std::ostream& operator<<(std::ostream& out, const MyString& printMe);
        friend std::istream& operator>>(std::istream& in, MyString& readMe);
        void read(std::istream& in, char delimeter);
        static const int MAX_INPUT_SIZE = 127;
        char operator[] (int index) const;
        char& operator[](int index);
        friend bool operator<(const MyString& left, const MyString& right);
        friend bool operator>(const MyString& left, const MyString& right);
        friend bool operator<=(const MyString& left, const MyString& right);
        friend bool operator>=(const MyString& left, const MyString& right);
        friend bool operator==(const MyString& left, const MyString& right);
        friend bool operator!=(const MyString& left, const MyString& right);
        MyString operator=(const MyString& right);
        friend MyString operator+(const MyString& left, const MyString& right);
        MyString operator+=(const MyString& right);
        int length() const;
    private:
        char* str;
    };
}

#endif