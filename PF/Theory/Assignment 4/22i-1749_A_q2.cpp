/*
Name: Mirza Humayun Masood
Roll No : i22-1749
Class : BS-CY(S)
*/
#include<iostream>
#include <cmath>
using namespace std;

int val(long int);      //prototype

int main(){
    long long x;
    cout<<"Enter a binary number: ";        //getting value
    cin>>x;
    if(x<=0){
        cout<<"Invalid Input"<<endl;            //invalid input
    }else{
        int z = val(x);
        if(z==-1){
        cout<<"Entered number cannot have any digit other than 0 and 1"<<endl;          //invalid input
        }else{
            cout<<"The binary number "<<x<<" is written as "<<z<<" in the decimal system."<<endl;
        }
    }
return 0;
}

int val(long int x){        //function
    int p=0;
    int counter=0;
    long long y=x;
    while (y>0){        //digits count
        y=y/10;
        counter++;
    }
    int q=0;
    y=x;
    while(y>0){
        q=y/(pow(10,(counter-1)));
        if(q==1||q==0){
            y= y - (q*(pow(10,(counter-1))));
            counter--;
            p= p +(q * pow(2,counter));         //p is the decimal val
        }else{
            return -1;      //in case of invalid input
        }
    }
    return p;           //returning decimal val
}
