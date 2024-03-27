/*
Mirza Humayun Masood
I22-1749
BS-CY(A)
*/
#include<iostream>
#include<windows.h>
#include<ctime>

using namespace std;

int main(){
    srand(time(0));     //for rand value for colors
    int a=0;
    for(int i=1;i<=5;i++){
        cout<<"Enter "<<i<<"st Number : ";
        cin>>a;
        while(a<1 || a>30){             //input check
            cout<<"Invalid Input"<<endl;
            cout<<"Enter "<<i<<"st Number again: ";
            cin>>a;
        }
        SetConsoleTextAttribute(GetStdHandle ( STD_OUTPUT_HANDLE ),(rand()%14)+1);      //colors random

        for(int i=1;i<=a;i++){
            cout<<"*";
        }
        SetConsoleTextAttribute(GetStdHandle ( STD_OUTPUT_HANDLE ),7);      //color back to normal
        cout<<endl;
    }




return 0;
}
