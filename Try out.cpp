#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

class Fraction {
public:
    void print() const;
    Fraction();
    Fraction(int inNumerator, int inDenominator);
    Fraction addedTo(const Fraction& secondFraction) const;
    Fraction subtract(const Fraction& secondFraction) const;
    Fraction multipliedBy(const Fraction& secondFraction) const;
    Fraction dividedBy(const Fraction& secondFraction) const;
    bool isEqualTo(const Fraction& secondFraction) const;
private:
    int numerator;
    int denominator;
    void simplify();
};

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int inNumerator, int inDenominator)
{  
    assert(inDenominator != 0);
    numerator = inNumerator;
    denominator = inDenominator;
    simplify();
   
}
void Fraction::print() const
{
    cout << numerator << "/" << denominator;
}

Fraction Fraction::addedTo(const Fraction& secondFraction) const
{
    Fraction result;
    result.numerator = numerator * secondFraction.denominator + secondFraction.numerator * denominator;
    result.denominator = denominator * secondFraction.denominator;
    result.simplify();
    return result;
}

Fraction Fraction::subtract(const Fraction& secondFraction) const
{
    Fraction result;
    result.numerator = numerator * secondFraction.denominator - secondFraction.numerator * denominator;
    result.denominator = denominator * secondFraction.denominator;
    result.simplify();
    return result;
}

Fraction Fraction::multipliedBy(const Fraction& secondFraction) const
{
    Fraction result;
    result.numerator = numerator * secondFraction.numerator;
    result.denominator = denominator * secondFraction.denominator;
    result.simplify();
    return result;
}

Fraction Fraction::dividedBy(const Fraction& secondFraction) const
{
    Fraction result;
    result.numerator = numerator * secondFraction.denominator;
    result.denominator = denominator * secondFraction.numerator;
    result.simplify();
    return result;
}

bool Fraction::isEqualTo(const Fraction& secondFraction) const
{
    return numerator * secondFraction.denominator == secondFraction.numerator * denominator;
}

void Fraction:: simplify()
{

    int small;
    if (denominator < numerator) {
        small = denominator;
    }
    else {
        small = numerator;
    }

    while ((denominator % small) != 0 || (numerator % small) != 0) {
        small--;
    }
    denominator = denominator / small;
    numerator = numerator / small;
   /* for (int i = abs(numerator * denominator); i > 1; i--)
    {
        if ((numerator % i) == 0 && (denominator % i) == 0)
        {
            numerator = numerator / i;
            denominator = denominator / i;
        }
    }


    if (numerator == 0)
        denominator = 1;*/
  
}

int main()
{
    Fraction f1(9, 8);
    Fraction f2(2, 3);
    Fraction result;

    cout << "The result starts off at ";
    result.print();
    cout << endl;

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)) {
        cout << "The two Fractions are equal." << endl;
    }
    else {
        cout << "The two Fractions are not equal." << endl;
    }

    const Fraction f3(12, 8);
    const Fraction f4(202, 303);
    result = f3.multipliedBy(f4);
    cout << "The product of ";
    f3.print();
    cout << " and ";
    f4.print();
    cout << " is ";
    result.print();
    cout << endl;
}