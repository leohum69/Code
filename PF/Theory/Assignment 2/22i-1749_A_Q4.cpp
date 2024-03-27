/*
Name : Mirza Humayun Masood.
Roll No : I22-1749
Class : BSCY(A)
*/
#include <iostream>

using namespace std;

int main(){

    int cal,fatg,calf;
    float per;

    cout<<"Enter Number of Calories: ";
    cin>>cal;
    cout<<"Enter Number of Fat Grams: ";
    cin>>fatg;
    calf= fatg*9;

    cal=cal+calf;
    per = (static_cast<float>(calf)/cal)*100.00;

    if(per<30){

        cout<<"The food is low in Fat"<<endl;
    }



return 0;
}
