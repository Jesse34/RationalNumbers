//
// Referenced this website for a method to implement normalization:
// http://snipplr.com/view/42917/reduce-a-fraction-to-lowest-terms/
//

#include "Rational.h"
using namespace std;


Rational::Rational() {
    this->numerator = 0;
    this->denominator = 1;
}

Rational::Rational(int whole) {
    this->numerator = whole;
    this->denominator = 1;
}

Rational::Rational(int n, int d) {
    this->numerator = n;
    this->denominator = d;
}

////ADDITION OVERLOAD
Rational Rational::operator+(Rational &rightObj){
    Rational sum;

    //Result numerator = (this.n * obj.d) + (this.d * obj.n)
    int newNumerator = this->numerator * rightObj.denominator + this->denominator * rightObj.numerator;

    //Result denominator = this.d * obj.d
    int newDenominator = this->denominator * rightObj.denominator;

    sum.numerator = newNumerator;
    sum.denominator = newDenominator;
    return sum;
}

////SUBTRACTION OVERLOAD
Rational Rational::operator-(Rational &rightObj){
    Rational sum;

    ////Result numerator = (this.n * obj.d) - (this.d * obj.n)
    int newNumerator = this->numerator * rightObj.denominator - this->denominator * rightObj.numerator;

    ////Result denominator = this.d * obj.d
    int newDenominator = this->denominator * rightObj.denominator;

    sum.numerator = newNumerator;
    sum.denominator = newDenominator;
    return sum;
}

////MULTIPLICATION OVERLOAD
Rational Rational::operator*(Rational &rightObj){
    Rational sum;

    ////Result numerator = numerator * numerator
    int newNumerator = this->numerator * rightObj.numerator;

    ////Result denominator = denominator * denominator
    int newDenominator = this->denominator * rightObj.denominator;

    sum.numerator = newNumerator;
    sum.denominator = newDenominator;
    return sum;
}

////DIVISION OVERLOAD
Rational Rational::operator/(Rational &rightObj){
    Rational sum;

    ////Result numerator = this.n * obj.d
    int newNumerator = this->numerator * rightObj.denominator;

    ////Result denominator = this.d * obj.n
    int newDenominator = this->denominator * rightObj.numerator;

    sum.numerator = newNumerator;
    sum.denominator = newDenominator;

    if(this->numerator == 0 && this->denominator == 1
            && rightObj.numerator == 0 && rightObj.denominator == 1){
        sum.numerator = 0;
        sum.denominator = 1;
    }

    return sum;
}

////EQUALS OVERLOAD
bool Rational::operator==(Rational &rightObj){
    bool result = false;
    string resultText = "False";

    if (this->numerator * rightObj.denominator
            == this->denominator * rightObj.numerator){
        result = true;
        resultText = "True";
    }
    cout << "The Rationals are equal in value = " << resultText << endl;
    return result;
}

////LESS THAN OVERLOAD
bool Rational::operator<(Rational &rightObj){
    bool result = false;
    string resultText = "False";

    double firstValue = (double)this->numerator / (double)this->denominator;
    double secondValue = (double)rightObj.numerator / (double)rightObj.denominator;

    if (firstValue < secondValue){
        resultText = "True";
        result = true;
    }
    cout << "The 1st Rational is less than the 2nd = " << resultText << endl;
    return result;
}

////GREATER THAN OVERLOAD
bool Rational::operator>(Rational &rightObj){
    bool result = false;
    string resultText = "False";

    double firstValue = (double)this->numerator / (double)this->denominator;
    double secondValue = (double)rightObj.numerator / (double)rightObj.denominator;

    if (firstValue > secondValue){
        result = true;
        resultText = "True";
    }
    cout << "The 1st Rational is greater than the 2nd = " << resultText << endl;
    return result;
}

////Input Overload - Validates, Parses, and Constructs the object.
void operator>>(istream &in, Rational &rat){
    string fraction;

    regex basicFraction = regex("^-?[\\d]+/-?[\\d]+$");
    regex wholeNumber = regex("^-?[\\d]+$");

    //Ignore Parameter type mismatch. Yes it's red. No it doesn't matter.
    getline(in, fraction);

    if (regex_match(fraction, basicFraction)){

        string delimiter = "/";
        string numerator = fraction.substr(0,fraction.find(delimiter));

        size_t splitPosition = fraction.find("/");
        string denominator = fraction.substr(splitPosition+1); //Position+1 excludes the '/' from the denominator string

        //Convert parsed strings into individual int values
        int n,d;
        n = stoi(numerator);
        d = stoi(denominator);

        if (d == 0){
            cout << "Cannot have a denominator equal to 0." << endl;
            rat.invalidInput = true;
            return;
        }

        cout << "SUCCESSFUL FRACTION REGEX" << endl;
        rat = Rational(n,d);
        rat.invalidInput = false;
        return;
    }

    if (regex_match(fraction, wholeNumber)){

        string numerator = fraction;

        string denominator = "1"; //For Whole Numbers, the denominator is automatically 1   eg: #/1

        //Convert strings into individual int values
        int n,d;
        n = stoi(numerator);

        cout << "SUCCESSFUL WHOLE NUMBER REGEX" << endl;
        //Set the numerator of the Whole number Rational object
        rat = Rational(n);
        rat.invalidInput = false;
        return;
    }

    if (fraction.empty()){
        cout << "CREATED RATIONAL OBJECT WITH VALUE OF ZERO" << endl;
        rat.invalidInput = false;
        return;
    }

    //Loops the input code on main.cpp
    cout << "Invalid Input, please enter a valid fraction or whole number" << endl;
    rat.invalidInput = true;
}

////OUTPUT OVERLOAD
ostream& operator<<(ostream& out, Rational &rat){
    int n, d;
    n = rat.numerator / rat.getGCD(rat.numerator, rat.denominator);
    d = rat.denominator / rat.getGCD(rat.numerator, rat.denominator);
    if (d < 0){
        n *= -1;
        d *= -1;
    }
    out << n << "/" << d;
    return out;
}

//Get the GCD of two ints
int Rational::getGCD(int x, int y){
    int gcd, remainder;

    while (x != 0){
        remainder = y%x;
        y = x;
        x = remainder;
    }
    gcd = y;
    return gcd;
}