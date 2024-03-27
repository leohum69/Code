/*
Name: Mirza Humayun Masood
Roll No: I22-1749
Class: BS-CY(A)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    float a,b,c,d,e;
    float totalp,totals,total;      //Declaration of variables


    cout<<"Price of item 1: ";
    cin>>a;
    cout<<"Price of item 2: ";
    cin>>b;
    cout<<"Price of item 3: ";
    cin>>c;
    cout<<"Price of item 4: ";
    cin>>d;
    cout<<"Price of item 5: ";      //Taking inputs
    cin>>e;

    totalp=a+b+c+d+e;
    totals= ((a*17.0)/100.0) + ((b*17.0)/100.0) + ((c*17.0)/100.0) + ((d*17.0)/100.0) + ((e*17.0)/100.0);
    total= (a+((a*17.0)/100.0)) + (b+((b*17.0)/100.0)) + (c+((c*17.0)/100.0)) + (d+((d*17.0)/100.0)) + (e+((e*17.0)/100.0)); // Calculating totals

    cout<<setfill('*')<<setw(70)<<' '<<endl;        //bar

    cout<<setfill(' ')<<"ITEM\t\t"<<"PRICE\t\t"<<"SALES TAX(@17%)\t\t"<<"Total Price"<<endl;

    cout<<fixed<<"1"<<setw(20)<<setprecision(2)<<a<<setw(26)<<setprecision(3)<<((a*17.0)/100.0)<<setw(20)<<setprecision(2)<<a+((a*17.0)/100.0)<<endl;
    cout<<fixed<<"2"<<setw(20)<<setprecision(2)<<b<<setw(26)<<setprecision(3)<<((b*17.0)/100.0)<<setw(20)<<setprecision(2)<<b+((b*17.0)/100.0)<<endl;
    cout<<fixed<<"3"<<setw(20)<<setprecision(2)<<c<<setw(26)<<setprecision(3)<<((c*17.0)/100.0)<<setw(20)<<setprecision(2)<<c+((c*17.0)/100.0)<<endl;
    cout<<fixed<<"4"<<setw(20)<<setprecision(2)<<d<<setw(26)<<setprecision(3)<<((d*17.0)/100.0)<<setw(20)<<setprecision(2)<<d+((d*17.0)/100.0)<<endl;
    cout<<fixed<<"5"<<setw(20)<<setprecision(2)<<e<<setw(26)<<setprecision(3)<<((e*17.0)/100.0)<<setw(20)<<setprecision(2)<<e+((e*17.0)/100.0)<<endl<<endl;
    cout<<fixed<<"Total"<<setw(16)<<setprecision(2)<<totalp<<setw(26)<<setprecision(3)<<totals<<setw(20)<<setprecision(2)<<total<<endl;





return 0;
}
