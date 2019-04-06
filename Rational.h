//
// Created by prog2100 on 12/10/17.
//

#ifndef RATIONALNUMBERS_RATIONAL_H
#define RATIONALNUMBERS_RATIONAL_H

#include <array>
#include <iostream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

class Rational {

public:

    int numerator;
    int denominator;

    bool invalidInput = false;

    //Default
    Rational();

    //Convert Whole number to n over 1
    explicit Rational(int whole);

    //Construct a Rational number with the numerator n and denominator d
    Rational(int n, int d);

    int getGCD(int x, int y);

    ////INPUT OVERLOAD
    friend void operator>>(istream &in, Rational &rat);

    ////OUTPUT OVERLOAD
    friend ostream& operator<<(ostream& in, Rational &rat);

    ////ADDITION OVERLOAD
    Rational operator+(Rational &rightObj);

    ////SUBTRACTION OVERLOAD
    Rational operator-(Rational &rightObj);

    ////MULTIPLICATION OVERLOAD
    Rational operator*(Rational &rightObj);

    ////DIVISION OVERLOAD
    Rational operator/(Rational &rightObj);

    ////EQUALS OVERLOAD
    bool operator==(Rational &rightObj);

    ////GREATER THAN OVERLOAD
    bool operator>(Rational &rightObj);

    ////LESS THAN OVERLOAD
    bool operator<(Rational &rightObj);

};

#endif //RATIONALNUMBERS_RATIONAL_H
