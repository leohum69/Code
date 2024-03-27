/*
Name : Mirza Humayun Masood.
Roll No : I22-1749
Class : BSCY(A)
*/
#include <iostream>

using namespace std;

int main(){
    int a,b;
    cout<<"Enter First Number: ";
    cin>>a;
    cout<<"Enter Second Number: ";
    cin>>b;
    char clr1,clr2;

    switch(a){
        case 1:
        case 6:
        case 7:
        case 12:
        case 17:
        case 20:
        case 28:
        case 33:
            clr1='g';
            break;
        case 2:
        case 11:
        case 13:
        case 18:
        case 19:
        case 24:
        case 29:
        case 32:
            clr1='r';
            break;
        case 3:
        case 10:
        case 14:
        case 23:
        case 25:
        case 30:
        case 31:
        case 36:
            clr1='b';
            break;
        case 4:
        case 9:
        case 15:
        case 22:
        case 26:
        case 35:
            clr1='o';
            break;
        case 5:
        case 8:
        case 16:
        case 21:
        case 27:
        case 34:
            clr1='G';
            break;
        default:
            cout<<"Invalid Input"<<endl;
    }
        switch(b){
        case 1:
        case 6:
        case 7:
        case 12:
        case 17:
        case 20:
        case 28:
        case 33:
            clr2='g';
            break;
        case 2:
        case 11:
        case 13:
        case 18:
        case 19:
        case 24:
        case 29:
        case 32:
            clr2='r';
            break;
        case 3:
        case 10:
        case 14:
        case 23:
        case 25:
        case 30:
        case 31:
        case 36:
            clr2='b';
            break;
        case 4:
        case 9:
        case 15:
        case 22:
        case 26:
        case 35:
            clr2='o';
            break;
        case 5:
        case 8:
        case 16:
        case 21:
        case 27:
        case 34:
            clr2='G';
            break;
        default:
            cout<<"Invalid Input"<<endl;
    }
    bool chk= (clr1 == clr2);

    switch (chk){
        case 1:
            cout<<"Both Colors Matched"<<endl;
            break;
        case 0:
            cout<<"Both Colors did not Match"<<endl;
            break;
    }



return 0;
}
