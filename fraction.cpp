/*
--Private Data members 
1) inNumerator
This Data member is type int which includes positve and negative . It represents 
the upper value of a fraction which we called as Numerator in Maths.
inNumerator can be accessed only by the function inside the class and only the 
member functions or friend function are allowed to access this data member.
This member will always be reduced to the simplest form using a private function
called simplify(). 

2) inDenominator
This Data member is type int which includes positve and negative . It represents
the lower value of a fraction which we called as Denominator in Maths.
inDenominator can be accessed only by the function inside the class and only the
member functions or friend function are allowed to access this data member.
This member will always be reduced to the simplest form using a private function
called simplify().



--Private Member Functions
void Fraction::simplify()
This private member function will set the fraction to its simplifed form.
Reducing the fraction to the most simplified form but still in improper form
For example: 10/8 will be reduced and become 5/4 and not 1+1/4.
This function will reduce any fractions in general which is not only fraction 
provided in the client file. 
Fraction objects will be reduced/simplified before the end of any member function. 



--Complex Functions
ostream& operator<<(ostream& out, const Fraction& right)
This function is use to print out the product when << is called with Fraction 
Since operator<<  is a friend of the Fraction class, we can access Fraction's members directly.
It will print out improper fractions as mixed number with a sign +
For example : 5/4 will be printed out as 1+1/4
We return the ostream& so that we can put multiple  << operations on a single line

istream& operator>> (std::istream& in, Fraction& readMe)
This function is use to read in the fraction when >> is used since operator>> 
is a friend of the Fraction class, we can access Fraction's members directly
This function can read in single integer, two integers separated by
a slash, or a mixed number which consists of an integer, followed by a +
and then two integers with a slash.


*/

#include <iostream>
#include "fraction.h"
#include <cmath>
#include <cctype>
using namespace std; 


namespace cs_fraction {

    Fraction::Fraction(int num, int den) {

        assert(den != 0);
        inNumerator = num;
        inDenominator = den;
        simplify();
    }





        
    ostream& operator<<(ostream& out, const Fraction& right) {

        int remainder, wholeNum;

        if (right.inDenominator == 1)
            out << right.inNumerator;

        else if (right.inNumerator == 0)
            out << right.inNumerator;

        else if (abs(right.inNumerator) > abs(right.inDenominator))
        {
            wholeNum = right.inNumerator / right.inDenominator;
            remainder = (right.inNumerator % right.inDenominator);
            out << wholeNum << "+" << abs(remainder) << "/" << right.inDenominator;
        }

        else if (right.inNumerator < right.inDenominator && right.inNumerator != 0)
            out << right.inNumerator << "/" << right.inDenominator;

        return out;
    }





 
    istream& operator>> (istream& in, Fraction& readMe) {       
           
        int temp;
        in >> temp;
        if ( in.peek() == '+') {
        
            in.ignore();
            in >> readMe.inNumerator;
            in.ignore();
            in >> readMe.inDenominator;        
            if (temp < 0)
            {
                readMe.inNumerator = (temp * readMe.inDenominator) - 
                    readMe.inNumerator;
            }
            else
            readMe.inNumerator += (temp * readMe.inDenominator);
        }

        else  if (in.peek() == '/') {

            readMe.inNumerator = temp;
            in.ignore();
            in >> readMe.inDenominator; 
        }

        else{

            readMe.inNumerator = temp;
            readMe.inDenominator = 1;
        }
       
        readMe.simplify();
        return in;

    }





   
    void Fraction::simplify() {
        
        for (int i = abs(inNumerator * inDenominator); i > 1; i--)
        {
            if ((inNumerator % i) == 0 && (inDenominator % i) == 0)
            {
                inNumerator = inNumerator / i;
                inDenominator = inDenominator / i;
            }
        }

        if (inDenominator < 0)
        {
            inNumerator = inNumerator * -1;
            inDenominator = inDenominator * -1;
        }

        if (inNumerator == 0)
            inDenominator = 1;
    }








    bool operator<(const Fraction& left, const Fraction& right) {

        return (left.inNumerator * right.inDenominator) <
            (left.inDenominator* right.inNumerator);
    }






    bool operator<=(const Fraction& left, const Fraction& right) {

        return (left.inNumerator * right.inDenominator) <=
            (left.inDenominator * right.inNumerator);
    }






    bool operator==(const Fraction& left, const Fraction& right) {

        return (left.inNumerator * right.inDenominator) == 
            (left.inDenominator * right.inNumerator);
    }






    bool operator>(const Fraction& left, const Fraction& right) {

        return (left.inNumerator * right.inDenominator) >
            (left.inDenominator * right.inNumerator);
    }






    bool operator>=(const Fraction& left, const Fraction& right) {

        return (left.inNumerator * right.inDenominator) >=
            (left.inDenominator * right.inNumerator);
    }






    bool operator!=(const Fraction& left, const Fraction& right) {

        return (left.inNumerator * right.inDenominator) != 
            (left.inDenominator * right.inNumerator);
    }






    Fraction operator+ (const Fraction& left, const Fraction& right) {

        Fraction temp;
        temp.inNumerator = (left.inNumerator * right.inDenominator) +
            (right.inNumerator * left.inDenominator);
        temp.inDenominator = (left.inDenominator * right.inDenominator);
        temp.simplify();
        return temp;
    }






    Fraction operator -(const Fraction& left, const Fraction& right) {

        Fraction temp;
        temp.inNumerator = (left.inNumerator * right.inDenominator) -
            (right.inNumerator * left.inDenominator);
        temp.inDenominator = (left.inDenominator * right.inDenominator);
        temp.simplify();
        return temp;
    }






    Fraction operator* (const Fraction& left, const Fraction& right) {

        Fraction temp;
        temp.inNumerator = (left.inNumerator * right.inNumerator);
        temp.inDenominator = (left.inDenominator * right.inDenominator);
        temp.simplify();
        return temp;
    }






    Fraction operator/ (const Fraction& left, const Fraction& right) {

        Fraction temp;
        temp.inNumerator = (left.inNumerator * right.inDenominator);
        temp.inDenominator = (left.inDenominator * right.inNumerator);
        temp.simplify();
        return temp;
    }






    Fraction Fraction::operator+= (const Fraction& right) {

        inNumerator = (inNumerator * right.inDenominator) +
            (right.inNumerator * inDenominator);
        inDenominator = (inDenominator * right.inDenominator);
        simplify();
        return *this;

    }






    Fraction Fraction::operator-= (const Fraction& right) {

        inNumerator = (inNumerator * right.inDenominator) -
            (right.inNumerator * inDenominator);
        inDenominator = (inDenominator * right.inDenominator);
        simplify();
        return *this;
    }






    Fraction Fraction::operator*= (const Fraction& right) {

        inNumerator *= right.inNumerator;
        inDenominator *= right.inDenominator;
        simplify();
        return *this;
    }







    Fraction Fraction::operator/= (const Fraction& right) {

        inNumerator *= right.inDenominator;
        inDenominator *= right.inNumerator;
        simplify();
        return *this;
    }






    Fraction Fraction::operator++(int) {

        Fraction temp(inNumerator, inDenominator);
        inNumerator += inDenominator;
        return temp;
    }






    Fraction Fraction::operator++() {

        inNumerator += inDenominator;
        return *this;
    }






    Fraction Fraction::operator--(int) {

        Fraction temp(inNumerator, inDenominator);
        inNumerator -= inDenominator;
        return temp;
    }






    Fraction Fraction:: operator--() {

        inNumerator -= inDenominator;
        return *this;
    }

}

/*--------------------------Paste of Run of a2-------------------------------

----- Testing basic Fraction creation & printing
(Fractions should be in reduced form, and as mixed numbers.)
Fraction [0] = 1/2
Fraction [1] = -5/7
Fraction [2] = 10
Fraction [3] = -4
Fraction [4] = 0
Fraction [5] = 4+2/3
Fraction [6] = 0

----- Now reading Fractions from file
Read Fraction = 1/3
Read Fraction = 1/2
Read Fraction = 3/4
Read Fraction = -4/5
Read Fraction = 6
Read Fraction = 5
Read Fraction = -8
Read Fraction = 1+2/5
Read Fraction = -16+2/3
Read Fraction = 1+1/4
Read Fraction = 2
Read Fraction = -4+1/4
Read Fraction = -10+5/6

----- Testing relational operators between Fractions
Comparing 1/2 to -1/2
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing -1/2 to 1/2
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing 1/2 to 1/10
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing 1/10 to 0
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing 0 to 0
        Is left < right? false
        Is left <= right? true
        Is left > right? false
        Is left >= right? true
        Does left == right? true
        Does left != right ? false

----- Testing relations between Fractions and integers
Comparing -1/2 to 2
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing -3 to 1/4
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true

----- Testing binary arithmetic between Fractions
1/6 + 1/3 = 1/2
1/6 - 1/3 = -1/6
1/6 * 1/3 = 1/18
1/6 / 1/3 = 1/2
1/3 + -2/3 = -1/3
1/3 - -2/3 = 1
1/3 * -2/3 = -2/9
1/3 / -2/3 = -1/2
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/4

----- Testing arithmetic between Fractions and integers
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

----- Testing shorthand arithmetic assignment on Fractions
1/6 += 4 = 4+1/6
4+1/6 -= 4 = 1/6
1/6 *= 4 = 2/3
2/3 /= 4 = 1/6
4 += -1/2 = 3+1/2
3+1/2 -= -1/2 = 4
4 *= -1/2 = -2
-2 /= -1/2 = 4
-1/2 += 5 = 4+1/2
4+1/2 -= 5 = -1/2
-1/2 *= 5 = -2+1/2
-2+1/2 /= 5 = -1/2

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 2+2/3
2+2/3 -= 3 = -1/3
-1/3 *= 3 = -1
-1 /= 3 = -1/3

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3

(process 13532) exited with code 0.
Press any key to close this window . . .

------------------------------------------------------------------------------*/





































  
   

  