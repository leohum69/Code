/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class Fraction {        //class
    int numer;
    int denomer;
public:     //functions
    Fraction();         //cnstrct
    Fraction(int num);
    Fraction(int num, int denum);
    Fraction(const Fraction& obj);
    int getNumerator() const;       //getters
    int getDenominator() const;
    void display() const;           //display
    Fraction operator+(const Fraction& obj);        //arthemtic
    Fraction operator-(const Fraction& obj);
    Fraction operator*(const Fraction& obj);
    Fraction operator/(const Fraction& obj);
    Fraction& operator+=(const Fraction& obj);
    Fraction& operator-=(const Fraction& obj);
    Fraction& operator*=(const Fraction& obj);
    Fraction& operator/=(const Fraction& obj);
    friend ostream& operator<<(ostream& out, const Fraction& f);        //cout cin waley
    friend istream& operator>>(istream& in, Fraction& f);
    bool operator==(const Fraction& obj);       //relational
    bool operator!=(const Fraction& obj);
    bool operator<(const Fraction& obj);
    bool operator>(const Fraction& obj);
    bool operator<=(const Fraction& obj);
    bool operator>=(const Fraction& obj);
    Fraction operator++();      //increment decrement
    Fraction operator++(int);
    Fraction operator--();
    Fraction operator--(int);
    bool operator&&(const Fraction& obj);       //logical
    bool operator||(const Fraction& obj);

    int operator[](int i) const;        //subscript and stuff
    int operator()(int i) const;
    Fraction* operator&();
    Fraction operator->();
    Fraction operator->*(Fraction x);

    ~Fraction();
};

#endif // FRACTION_H
    int gcd(int a, int b){      //gcd
    if (b != 0)
       return gcd(b, a % b);
    else
       return a;
    }

