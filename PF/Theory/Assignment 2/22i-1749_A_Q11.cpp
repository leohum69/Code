/*
Name : Mirza Humayun Masood.
Roll No : I22-1749
Class : BSCY(A)
*/
#include <iostream>
#include <bitset>

using namespace std;

int main(){
    bitset<32> binary;
    int num;
    string name;
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter ID: ";
    cin>>num;



    cout<<"Belt number of "<<name<<" is : "<<(num & 127)<<endl;
    cout<<"Batch number of "<<name<<" is : "<<((num >> 7) & 1023)<<endl;
    cout<<"Log number of "<<name<<" is : "<<((num >> 17) & 31)<<endl;
    cout<<"Unit number of "<<name<<" is : "<<((num >> 22) & 1023)<<endl;




return 0;
}
