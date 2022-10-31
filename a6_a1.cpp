/*
Name : Isabelle Hong ; Class : C S 2B ; Date : 10/27/2020
Assignment 6: Recursion
Instrutor : Professor David Lee Harden
Name of the File : a6_a1.cpp

This program is mainly reverse the selected characters when given the specifc 
index of the character. Secondly, it is also designed to reverse c string 
in a backward direction , for example : "abcd" would become "dcba" and printed
out on the console window after function is called from client. This program
would also check the inappropriate bounds which would not allow the array of 
characters being reversed. Only correct bounds of chracters would be reversed.


Functions ------
void reverseWithinBounds(char arrayOfChar[], int lowerBound, int upperBound)
This function is used declared as void and it is use to reverse the order 
of those entries in the array whose indices are between the two bounds
(including the bounds). There are three arguments in this function: 
arrayOfChar[] is to take in the array of characters set in client,
lowerBound and upperBound would take in the index that set in the client.

void reverseCString(char CStr[])
This function is a also void function and it  takes a single argument that is a
C string and modifies the argument so that it is reversed. CStr[] would store 
the string of value to be modified/reversed.

void printArray(string title, char arrays[], int arraySize)
This function will help us to print the arrays using for loop function with parameter
title,arrays[] and aaraySize. arrays[] represent the arrayOfChars used in the main
while arraySize will be determined by the number of characters in the array.

*/



#include <iostream>
using namespace std;

void reverseWithinBounds(char arrayOfChar[], int lowerBound, int upperBound);
void reverseCString(char CStr[]);
void printArray(string title, char arrays[], int arraySize);

int main(){

    char arrayOfChars[]{ 'A','B','C','D','E','\0' };
    short arraySize = sizeof(arrayOfChars) / sizeof(arrayOfChars[0]);

    printArray("1. Array of characters before reversing: ", arrayOfChars, arraySize);
    reverseWithinBounds(arrayOfChars, 1, 4);
    cout << endl;
    printArray("   Array of characters after reversing with bounds(1,4): ", arrayOfChars, arraySize);
    cout << endl;

    char cString[] = "VolunFlex Non-Profit Organization";

    cout << "2. C-String before reversing: " << endl;
    cout << "    " << cString << endl << endl;
    reverseCString(cString);
    cout << "   C-String after  reversing: " << endl;
    cout << "    " << cString << endl;

    return 0;
}






void printArray(string title, char arrays[], int arraySize)
{
    cout << title << endl;
    
    for (int i = 0; i < arraySize - 1; i++){

        cout << "    a["<< i << "] == '" << arrays[i] << "'";
    }
    cout << endl;
}






void reverseWithinBounds(char arrayOfChar[], int lowerBound, int upperBound) {
    
    if (lowerBound < upperBound) {

        char temp = arrayOfChar[lowerBound];
        arrayOfChar[lowerBound] = arrayOfChar[upperBound];
        arrayOfChar[upperBound] = temp;
        reverseWithinBounds(arrayOfChar, lowerBound + 1, upperBound - 1);

    }
}






void reverseCString(char CStr[]){

    reverseWithinBounds(CStr, 0, strlen(CStr) - 1);
}


/*-----------------------Paste of Run a6_a1 with Bounds(1,4)-------------------
1. Array of characters before reversing:
    a[0] == 'A'    a[1] == 'B'    a[2] == 'C'    a[3] == 'D'    a[4] == 'E'

   Array of characters after reversing with bounds(1,4):
    a[0] == 'A'    a[1] == 'E'    a[2] == 'D'    a[3] == 'C'    a[4] == 'B'

2. C-String before reversing:
    VolunFlex Non-Profit Organization

   C-String after  reversing:
    noitazinagrO tiforP-noN xelFnuloV

(process 18256) exited with code 0.
Press any key to close this window . . .


-----------------------------------------------------------------------------*/
