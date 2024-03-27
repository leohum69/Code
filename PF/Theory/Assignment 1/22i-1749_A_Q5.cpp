/*
Name: Mirza Humayun Masood
Roll No: I22-1749
Class: BS-CY(A)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int a,b,c,d,e,scale;    //declaration of variables

    cout<<"N1: ";
    cin>>a;
    cout<<"N2: ";
    cin>>b;
    cout<<"N3: ";
    cin>>c;
    cout<<"N4: ";
    cin>>d;
    cout<<"N5: ";
    cin>>e;                 //taking inputs

    cout<<"Enter Scale: ";
    cin>>scale;

    cout<<"BAR CHART OUTPUT"<<endl;

    cout<<setfill('*')<<setw(scale*a+1)<<' '<<endl;       //i m displaying asterisks by using setw and setf, but after some testing
    cout<<setfill('*')<<setw(scale*b+1)<<' '<<endl;       //my compiler needs to take a variable or operand to display asterisks so
    cout<<setfill('*')<<setw(scale*c+1)<<' '<<endl;       //i m using spaces and adding 1 so space does not get in setw function...
    cout<<setfill('*')<<setw(scale*d+1)<<' '<<endl;
    cout<<setfill('*')<<setw(scale*e+1)<<' '<<endl;






return 0;
}
