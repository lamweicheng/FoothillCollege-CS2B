/*
Name : Isabelle Hong ; Class : C S 2B ; Date : 10/9/2021
Assignment 3.2 : Pointers and Dynamic Memory
Instrutor : Professor David Lee Harden
Name of the File : a3_a2.cpp

This program allows the user to record the scores and names of the people 
that earned the scores in any game. The program will not continue to run if 
total numbers of scores(size) were not entered by the user and we are not expecting 
negative total size in this program. If positive integer were input by the user,
the program will continue and name for the person will be required to be input and score 
of the person as well. Two dynamic arrays are declared: an array of strings and and array of ints.
All of the data (names and scores) will be stored in the heap using the "new" operator. 
After that, the program will sort the scores from descending order (from highest scores 
to lowest scores) and all of them will be printed out on the display . Only postive 
total size will be considered and work,or else, the program will crash. Only names 
before spaces will be also considered in the display. Positive and Negative 
scores can bb included in this program and they will be sorted out as usual(from
largest to smallest).


*/

#include <iostream>
using namespace std;

void readData(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);

int main()
{
    int size;
    cout << "How many scores will you enter?: ";
    cin >> size;

    int* scores = new int[size];
    string* names = new string[size];

    readData(names, scores, size);
    sortData(names, scores, size);
    displayData(names, scores, size);

    delete[] scores;
    delete[] names;

    return 0;
}






/*
This function will require the user to input a string and store into dynamic array called names[].
After that, an integer will be needed and it will be stored into another dynamic array named scores[]
then a string will be required again if this function is called by client again.
Basically, names[] will store the arrays of strings while scores[] will stores the array of integers
The total amount of string and integer needed to input depends on the value of size that user entered
before this function is called. 
This function will also take in positive & negative values for the scores and any
other inappropriate characters will cause the program to crash.
*/
void readData(string names[], int scores[], int size){

    for (int x = 0; x < size; x++)
    {
        cout << "Enter the name for score #" << (x + 1) << ": ";
        cin >> names[x];
       
        cout << "Enter the score for score #" << (x + 1) << ": ";
        cin >> scores[x];
       
    }
}






/*
This function is going to sort the values of scores stored in array scores[] that were input 
by the user with other function and the values will be arrange from the highest scores to 
the lowest. In other words, it is used to rank the scores in descending order accordingly and 
with their names. names[] is somewhat the owner of the score[], if any object in score[]
move, the name will also move. The parameter size[] represents the amount of scores that user input and called 
in the client. 
*/
void sortData(string names[], int scores[], int size){

    int highScores, highIndex;
    string temp;
    for (int x = 0; x < size - 1; x++)
    {
        highIndex = x;
        highScores = scores[x];

        for (int y = x + 1; y < size; y++)
        {
            if (scores[y] > highScores)
            {
                highIndex = y;
                highScores = scores[y];
            }
        }

        if (highIndex > x)
        {
            scores[highIndex] = scores[x];
            scores[x] = highScores;
            temp = names[x];
            names[x] = names[highIndex];
            names[highIndex] = temp;
        }
    }
}






/*
This function will print out all the names that were stored in dynamic array names[] and
another dynamic array called scores[] entered by the user in the display console according
to how it was sorted by other function called by the client. Names and scores will be printed 
out sorted by scores in descending order.
*/
void displayData(const string names[], const int scores[], int size)
{
    cout << endl;
    cout << "Top Scorers: " << endl;
    for (int x = 0; x < size; x++)
    {
        cout << names[x] << ": " << scores[x] << endl;
    }
}

/*------------------------------Paste of Run a3_a2------------------------------
How many scores will you enter?: 4
Enter the name for score #1: Suzy
Enter the score for score #1: 600
Enter the name for score #2: Kim
Enter the score for score #2: 9900
Enter the name for score #3: Armando
Enter the score for score #3: 8000
Enter the name for score #4: Tim
Enter the score for score #4: 514

Top Scorers:
Kim: 9900
Armando: 8000
Suzy: 600
Tim: 514

(process 5976) exited with code 0.
Press any key to close this window . . .


------------------------------------------------------------------------------*/