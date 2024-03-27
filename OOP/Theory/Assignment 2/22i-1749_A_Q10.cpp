/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include <iostream>
#include "Array.cpp"

using namespace std;

int main(){

    int *arr= new int[5]{1,2,3,4,5};
    Array A1(arr,5);
    //Array A2;
    //arr = A1.subArrPointer(1,4);
    A1.display();
    A1.push_back(69);
    A1.display();
    cout<<A1.pop_back()<<endl;
    A1.display();
    //A2.display();
    A1.insert(2,69);
    A1.display();
    A1.erase(2);
    A1.display();
    A1.reverse();
    A1.display();
    cout<<A1.sort()<<endl;
    A1.display();
    delete []arr;
    arr = new int[10]{1,1,2,4,5,1,9,8,10,1};
    Array A2(arr,10);
    Array A3 = A2.find(1);
    A2.display();
    A3.display();





return 0;
}
