/*
Name: Mirza Humayun Masood
Roll No : i22-1749
Class : BS-CY(S)
*/
#include <iostream>
using namespace std;

bool exchange(int); //prototype

int main(){

    int cash=0;
    cout<<"Enter Money in PKR : ";      //gettin input
    cin>>cash;
    if(cash>0){
    bool b = exchange(cash);        //assigning value to bool
        if(b==true){
            cout<<"It is Possible."<<endl;
        }else{
            cout<<"It is not Possible."<<endl;      //possible or not possible xD
        }
    }else{
        cout<<"Invalid Input"<<endl;
        cout<<"Money cant be negative not zero"<<endl;      //-ve and 0 check
    }


return 0;
}
bool exchange(int x){       //function
    int six=0,nine=0,twen=0;

    twen =x/20;         //20 got seprated
    x = x - (twen*20);
    nine = x/9;         //9 got seprated
    x = x - (nine*9);
    six = x/6;          //6 got seprated
    x = x- (six*6);     //now if there are some remaining then possible, otherwise nope
    if(x==0){
        return true;
    }else{
        return false;
    }
}
