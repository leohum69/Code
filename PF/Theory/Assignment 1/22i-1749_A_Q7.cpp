/*
Name: Mirza Humayun Masood
Roll No: I22-1749
Class: BS-CY(A)
*/
#include <iostream>

using namespace std;

int main(){

    float sum, num;     //Declaration of variables
    cout<<"Enter First number: ";       //i am taking input and adding it in sum variable, so we can use only two variables
    cin>>num;
    sum=num;
    cout<<"Enter Second number: ";
    cin>>num;
    sum=sum+num;
    cout<<"Enter Third number: ";
    cin>>num;
    sum=sum+num;
    cout<<"Enter Fourth number: ";
    cin>>num;
    sum=sum+num;
    cout<<"Enter Fifth number: ";
    cin>>num;
    sum=sum+num;

    sum= sum/5.0;       //and now for avg, i am dividing with 5

    cout<<"Average : "<<sum<<endl;


return 0;
}
