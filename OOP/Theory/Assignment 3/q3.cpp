/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include <iostream>
#include "Fraction.cpp"
using namespace std;
int main(){     //main
    Fraction f1(5, 3);      //making two objects
    Fraction f2(6, 7);
    Fraction f3 = f1 + f2;
    Fraction f4 = f1 - f2;
    Fraction f5 = f1 * f2;
    Fraction f6 = f1 / f2;
    Fraction f7 = f1;       //and doing operatoion xd;
    f7 += f2;
    Fraction f8 = f1;
    f8 -= f2;
    Fraction f9 = f1;
    f9 *= f2;
    Fraction f10 = f1;
    f10 /= f2;

    cout << "f1: ";
    cout<<f1;
    cout << "f2: ";
    cout<<f2;
    cout << "f1 + f2: ";
    cout<<f3;
    cout << "f1 - f2: ";
    cout<<f4;
    cout << "f1 * f2: ";
    cout<<f5;
    cout << "f1 / f2: ";
    cout<<f6;
    cout << "f7 (f1 += f2): ";
    cout<<f7;
    cout << "f8 (f1 -= f2): ";
    cout<<f8;
    cout << "f9 (f1 *= f2): ";
    cout<<f9;
    cout << "f10 (f1 /= f2): ";
    cout<<f10;
    cout<<"f1>f2 :";
    cout<< (f1>f2)<<endl;
    cout<<"Subscipt notation: ";
    cout<<f1[1]<<endl;
    cout<<"round notation: ";
    cout<<f1(0)<<endl;
    cout<<(f1->*f2);

return 0;
}
