/*
Name :Isabelle Hong ; Class : C S 2B ; Date : 10/4/2021
Assignment 2 : Operator Overloading 2
Instrutor : Professor David Lee Harden 
Name of the File : fraction.h

The Class Fraction is basically overloading every operators such as insertion operator,
extraction operator , increment operators, decrement operators,arithmetic operators,
which take in positive/negative fractions, mixed numbers & improper fractions. 
Also , reducing/simplifying any fractions that appear in the program before printing 
out to the console screen. 
The following functions are available: 

Fraction(int num = 0, int den = 1);
Precondition: This constructor function will assume there are two values to take in 
First value is num, Second value is den 
Postcondition: If the num has no value , num  will be set to value 0 and if there's no 
2nd value , den will be set to value 1. 

friend std::ostream& operator<< (std::ostream& out, const Fraction& right);
Precondition: If out is a file output stream, then out has already been connected
to a file..
Postcondition: Overloads the << operator so it can be used to output objects of 
the classes i define which is type Fraction. Display values on the screen.

friend std::istream& operator>> (std::istream& in, Fraction right);
Precondition: If in is a file input stream, then in has already been connected 
to a file. With overloaded extraction(input) operator >> , the second argument will 
be the object that receives the input value , so the second parameter which is 
"right" is an ordinary call-by-by reference parameter.
Postcondition: Overloads the >> operator so it can be used to input objects of 
type Fraction. Get input from a file and insert them into the code. 

friend bool operator< (const Fraction& left, const Fraction& right);
Postcondition:returns true if left value is lesser than right value ; otherwise,
return false

friend bool operator<= (const Fraction& left, const Fraction& right);
Postcondition:returns true if left value is lesser than and equal to right value; 
otherwise,return false

friend bool operator> (const Fraction& left, const Fraction& right);
Postcondition: returns true if left value is bigger than right value ; otherwise,
return false

friend bool operator>= (const Fraction& left, const Fraction& right);
Postcondition: returns true if left value is bigger than and equal to right value;
otherwise,return false

friend bool operator== (const Fraction& left, const Fraction& right);
Postcondition: Returns true if left value and right value have the same value; 
otherwise,return false

friend bool operator!= (const Fraction& left, const Fraction& right);
Postcondition: Returns true if left value and right value have different values;
otherwise, return false

friend Fraction operator+ (const Fraction& left, const Fraction& right);
Postcondition: Returns the sum of the values of left and right

friend Fraction operator- (const Fraction& left, const Fraction& right);
Postcondition: Returns the subtraction of the values of right from left.

friend Fraction operator* (const Fraction& left, const Fraction& right);
Postcondition: Returns the multiplication of values of left and right. 

friend Fraction operator/ (const Fraction& left, const Fraction& right);
Postcondition :Returns the division of values of left over values of right.

Fraction operator+= (const Fraction& right);
Postcondition: Add the value of left operand to the right operand. 
Returns the value that it just assigned to the left operand. 

Fraction operator-= (const Fraction& right);
Postcondition: Subtract the value of right operand from the left operand. 
Returns the value that it just assigned to the left operand. 

Fraction operator*= (const Fraction& right);
Postcondition: Multiply the value of left operand to the right operand. 
Returns the value that it just assigned to the left operand. 

Fraction operator/= (const Fraction& right);
Postcondition: Divide the value of left operand with the right operand. 
Returns the value that it just assigned to the left operand. 

Fraction operator++ ();
Precondition: Value of operand (which is being represented by the calling object)
is given
Postcondition: Increment the operand by adding one to the data member, 
and then return this new value of the operand

Fraction operator++ (int);
Precondition:Value of operand (which is being represented by the calling object)
is given
Postcondition: Determine the value of the expression , then increment the operand 
Return the original value of the operand. 

Fraction operator-- ();
Precondition: Value of operand (which is being represented by the calling object)
is given
Postcondition: Decrement the operand by subtracting one from the data member,
and then return this new value of the operand.

Fraction operator-- (int);
Precondition: Value of operand (which is being represented by the calling object)
is given
Postcondition: Determine the value of the expression , then decrement the operand
Return the original value of the operand.

*/


#ifndef fraction_h
#define fraction_h
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

namespace cs_fraction {

    class Fraction
    {
    public:
        Fraction(int num = 0, int den = 1);
        friend std::ostream& operator<< (std:: ostream& out, const Fraction& right);
        friend std::istream& operator>> (std::istream& in, Fraction& readMe);
        friend bool operator< (const Fraction& left, const Fraction& right);
        friend bool operator<= (const Fraction& left, const Fraction& right);
        friend bool operator> (const Fraction& left, const Fraction& right);
        friend bool operator>= (const Fraction& left, const Fraction& right);
        friend bool operator== (const Fraction& left, const Fraction& right);
        friend bool operator!= (const Fraction& left, const Fraction& right);
        friend Fraction operator+ (const Fraction& left, const Fraction& right);
        friend Fraction operator- (const Fraction& left, const Fraction& right);
        friend Fraction operator* (const Fraction& left, const Fraction& right);
        friend Fraction operator/ (const Fraction& left, const Fraction& right);
        Fraction operator+= (const Fraction& right);
        Fraction operator-= (const Fraction& right);
        Fraction operator*= (const Fraction& right);
        Fraction operator/= (const Fraction& right);
        Fraction operator++ ();
        Fraction operator++ (int);
        Fraction operator-- ();
        Fraction operator-- (int);

    private:
        void simplify();
        int inNumerator;
        int inDenominator;
    };

}

#endif