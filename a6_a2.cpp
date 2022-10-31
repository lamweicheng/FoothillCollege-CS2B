/*
Name: Isabelle Hong; Class: C S 2B; Date: 10 / 30 / 2020
Assignment 6 : Recursion
Instrutor : Professor David Lee Harden
Name of the File : a6_a2.cpp

This program is to check whether the string that entered by user is a palindrome 
or not. A palindrome is a string that reads the same forward and backward. If 
the string entered by user can be read same forward and backward,
the program will print out _________ is a parlindrome, else , it is not. The program
will continue to run until the user enters "quit" and the program will shut down. 


bool isAPalindrome(MyString str, int lowerBounds, int upperBounds);
This is a recursive function that takes a MyString argument and two arguements
that are the bounds on MyString induices. It will check the argumenet between
the lower and upper bounds and it will return true if the string entered by
the user if it is a panlidrome, false if it is not a panlidrome. It will also
check for punctuation or space for left half & right half and ignore it
This function must consider uppercase and lowercase letters to be the same.

*/



#include "mystring2.h"
#include <iostream>
#include <cstring>
#include <cassert>
#include<cctype>
using namespace std;
using namespace cs_mystring;

bool isAPalindrome(MyString str,  int lowerBounds,  int upperBounds);

int main()
{
    MyString str;
    cout << "Enter a string: ";
    str.read(cin, '\n');
 
    while (str != "quit") {

        if (isAPalindrome(str, 0, str.length() - 1))
            cout << str << " is a parlindrome." << endl;
        else
            cout << str << " is not a parlindrome." << endl;

        cout << "Enter a string: ";
        str.read(cin, '\n');
    }

    return 0;
}






bool isAPalindrome(MyString str,  int lowerBounds,  int upperBounds)
{
   
    if (lowerBounds == upperBounds)
        return true;

    if (ispunct(str[lowerBounds]) || isspace(str[lowerBounds]))
        return isAPalindrome(str, lowerBounds + 1, upperBounds);

    if (ispunct(str[upperBounds]) || isspace(str[upperBounds]))
        return isAPalindrome(str, lowerBounds, upperBounds - 1);
  
    if ((toupper(str[lowerBounds]) != toupper(str[upperBounds])))
        return false;

    if (lowerBounds < (upperBounds + 1))
        return isAPalindrome(str, lowerBounds + 1, upperBounds - 1);

    return true;
}


/*-----------------------------Paste of Run a6_a2-------------------------------
Enter a string: Able was I, ere I saw Elba
Able was I, ere I saw Elba is a parlindrome.
Enter a string: peanut butter
peanut butter is not a parlindrome.
Enter a string: quit

(process 5276) exited with code 0.
Press any key to close this window . . .

-----------------------------------------------------------------------------*/

/*--------------------Paste of Run a6_a2 (Try other strings)----------------------
Enter a string: Burt Bees
Burt Bees is not a parlindrome.
Enter a string: July December
July December is not a parlindrome.
Enter a string: Seiko Lol
Seiko Lol is not a parlindrome.
Enter a string: Seiko LoL okies
Seiko LoL okies is a parlindrome.
Enter a string: quit

(process 12672) exited with code 0.
Press any key to close this window . . .


-----------------------------------------------------------------------------*/