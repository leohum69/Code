/*
Name: Mirza Humayun Masood
Roll No: I22-1749
Class: BS-CY(A)
*/
#include <iostream>

using namespace std;

int main()
{
    int x;

    cout << "Enter a 5 digit number: "; //taking value
    cin >> x;

    int a, b, c, d, e;
    int a1, b1, c1, d1, e1;             //Declaration of variables

    a = x / 10000;
    b = (x-(a*10000) )/ 1000;
    c = (x - (a * 10000)-(b*1000)) / 100;
    d = (x - (a * 10000)-(b*1000)-(c*100)) / 10;
    e = (x - (a * 10000) - (b * 1000) - (c * 100) - (d * 10)); //getting every single digit

    a1 = e / 2;
    b1 = d / 2;
    c1 = c / 2;
    d1 = b / 2;
    e1 = a / 2;                                     //dividing with two

    cout << "Modified Number: " << a1 << b1 << c1 << d1 << e1<<endl;    //Displaying in reverse order















    return 0;
}
