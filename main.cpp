#include <iostream>
#include <sstream>
#include <cstdio>
#include <regex>
#include "Rational.h"

using namespace std;

int main() {
    Rational rat1;
    Rational rat2;

    do {
        cout << endl << "Please enter the first rational number. (format: #/#)" << endl;
        cin >> rat1;
    } while (rat1.invalidInput);

    do {
    cout << "Please enter the second rational number. (format: #/#)" << endl;
    cin >> rat2;
    } while (rat2.invalidInput);

    cout << endl;

    ////ADDITION OVERLOAD
    Rational addSum = rat1+rat2;

    ////SUBTRACTION OVERLOAD
    Rational subtractSum = rat1-rat2;

    ////MULTIPLICATION OVERLOAD
    Rational multiplySum = rat1*rat2;

    ////DIVISION OVERLOAD
    Rational divideSum = rat1/rat2;

    cout << "ADDITION | " << rat1 << " + " << rat2 << " = " << addSum << endl;
    cout << "SUBTRACT | " << rat1 << " - " << rat2 << " = " << subtractSum << endl;
    cout << "MULTIPLY | " << rat1 << " * " << rat2 << " = " << multiplySum << endl;
    cout << "DIVISION | " << rat1 << " / " << rat2 << " = " << divideSum << endl;

    cout << endl;

    ////EQUALS OVERLOAD
    rat1 == rat2;

    ////GREATER THAN OVERLOAD
    rat1 > rat2;

    ////LESS THAN OVERLOAD
    rat1 < rat2;

    //cout << "Fraction 1: " << rat1.numerator << "/" << rat1.denominator << endl << "Fraction 2: "<< rat2.numerator << "/" << rat2.denominator << endl;
}
