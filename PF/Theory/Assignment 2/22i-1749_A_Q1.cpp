/*
Name : Mirza Humayun Masood
Roll No : 22i-1749
Class : BS-CY(A)
*/
#include <iostream>

using namespace std;

int main(){

    int cwl,cm,cy,rd,ri;

    cout<<"Enter Current water level: ";
    cin>>cwl;
    cout<<"Current month: ";
    cin>>cm;
    cout<<"Current Year: ";
    cin>>cy;
    cout<<"Rate of decrease in level from September to February: ";
    cin>>rd;
    cout<<"Rate of increase in level from March to August: ";
    cin>>ri;

    if(cwl<1550){

        if(cm>2 && cm<9){
            cm= 9-cm;
            cwl+= (cm*ri);

        }

    }






return 0;
}
