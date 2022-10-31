/*
Name: Isabelle Hong; Class: C S 2B; Date: 10 / 28 / 2020
Assignment 6 : Recursion
Instrutor : Professor David Lee Harden
Name of the File : a6_a3.cpp

This program is print the values before sorting them in ascending order. 
Later, the function sortArray will be called and the arrays of integers
into ascending order which mean the smallest element in the first position,
then sort the rest of the array by a recursive call. Values will be arranged 
from smallest to largest. After that, the values will be printed out on
console window with ascending order. 

Functions ------
void sortArray(int values[], int firstIndex, int lastIndex)
values[] are going to store the values of characters that declared in client.
firstIndex represent the first position in the array and index going to be
set to 0. values[firstIndex] through values[lastIndex] are sorted in increasing order.
In this function,  we will call the function smallestIndex to help arrange the position
of the value based on ascending order. 

int smallestIndex(int values[], int firstIndex, int lastIndex)
values[] are going to store the values of characters that declared in client.
firstIndex represent the first position in the array and lastIndex represent
the last position in the array. This function is to find the smallest index(first position) 
and return it to the function that call it. 
 We are assigning the first array element to the valuePos variable and then we are comparing
all the array elements with the valuePos inside loop and if the element is smaller than valuePos
then the valuePos value is replaced by that. This way we always have the smallest value in temp.
Finally we are returning valuePos.


*/

#include <iostream>
using namespace std;

void sortArray(int values[], int firstIndex, int index = 0);
int smallestIndex(int values[], int firstIndex, int lastIndex);
void swap(int* x, int* y);

int main() {

    int values[] = { 69,19,39,12,5,17,89,0 };
    int size= sizeof(values) / sizeof(values[0]);

    cout << "Before sorting:   ";
    for (int i = 0; i < 8; i++)
         cout <<"   "<< values[i];
    cout << endl;

    sortArray(values, size);

    cout << "After  sorting:   ";
    for (int i = 0; i < 8; i++)
        cout << "   " << values[i];
    cout << endl;

    return 0;

}






int smallestIndex(int values[], int firstIndex, int lastIndex) {

    int valuePos;
    if (firstIndex == lastIndex)
        return firstIndex;
  
    valuePos = smallestIndex(values, firstIndex + 1, lastIndex);

    for (int i = firstIndex; i <= lastIndex; i++) {

        if (values[i] < values[valuePos])
            valuePos = i;
    }
    return valuePos;
}






void sortArray(int values[], int firstIndex, int index) {

    int valuePos;

    if (index == firstIndex)
        return;

    valuePos = smallestIndex(values, index, firstIndex - 1);

    if (valuePos != index)
        swap(&values[valuePos], &values[index]);

    sortArray(values, firstIndex, index + 1);

}






void swap(int* recValue, int* indexValue) {

    int temp = *recValue;
    *recValue = *indexValue;
    *indexValue = temp;
}

/*-------------------------Paste of run a6_a3---------------------------
Before sorting:      69   19   39   12   5   17   89   0
After  sorting:      0   5   12   17   19   39   69   89
(process 10504) exited with code 0.
Press any key to close this window . . .
-----------------------------------------------------------------------*/