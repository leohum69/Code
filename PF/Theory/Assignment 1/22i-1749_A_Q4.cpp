/*
Name: Mirza Humayun Masood
Roll No: I22-1749
Class: BS-CY(A)
*/
#include <iostream>
using namespace std;

int main() {

    char a, b, c, d, e, f, g, h;
    char a1, b1, c1, d1, e1, f1, g1, h1;    //Declaration of variables

    cout << "Enter 8 Random Letters: "; //Taking values by using cin.get();
    cin.get(a);
    cin.get(b);
    cin.get(c);
    cin.get(d);
    cin.get(e);
    cin.get(f);
    cin.get(g);
    cin.get(h);

    a1 = a - 32;                    //converting in upercase
    b1 = b - 32;
    c1 = c - 32;
    d1 = d - 32;
    e1 = e - 32;
    f1 = f - 32;
    g1 = g - 32;
    h1 = h - 32;



    cout << "Upper Cased: " << a1 << b1 << c1 << d1 << e1 << f1 << g1 << h1 << endl;    //displaying









return 0;
}
