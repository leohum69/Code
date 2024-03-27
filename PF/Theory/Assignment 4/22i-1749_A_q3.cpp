/*
Name: Mirza Humayun Masood
Roll No : i22-1749
Class : BS-CY(S)
*/
#include <iostream>
using namespace std;

int gcd(int,int);       //prototype

int main(){
    int a,b;
    cout<<"Enter First Integer: ";      //getting values
    cin>>a;
    cout<<"Enter Second Integer: ";
    cin>>b;
    if(a<=0 || b<=0){                   //invalid input check
        cout<<"Invalid Input"<<endl;
    }else{
        if(b>a)             // conditions if a is greater or b
            cout<<"Greatest common divisor : "<<gcd(a,b);
        else
            cout<<"Greatest common divisor : "<<gcd(b,a);
    }

return 0;
}
int gcd(int x,int y){           //function
    int pew=0;
    while((x%y) > 0){
        pew = x%y;
        x=y;
        y=pew;
    }
    return pew;
}
