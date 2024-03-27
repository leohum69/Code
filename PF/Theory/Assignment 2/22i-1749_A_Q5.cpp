/*
Name : Mirza Humayun Masood.
Roll No : I22-1749
Class : BSCY(A)
*/
#include <iostream>

using namespace std;


int main(){

    int a,b,c,d,large,choice;
    cout<<"Enter Your Choice: "<<endl;
    cout<<"For 3 Numbers - 1 :"<<endl;
    cout<<"For 4 Numbers - 2 :"<<endl;
    cout<<"Choice : ";
    cin>>choice;
    switch (choice){
        case 1:
            cout<<"Enter First Number: ";
            cin>>a;
            cout<<"Enter Second Number: ";
            cin>>b;
            cout<<"Enter Third Number: ";
            cin>>c;
            large = (a>b && a>c) ? a : (b>a && b>c) ? b : c ;
            cout<< "Large: "<<large<<endl;
            break;
        case 2:
            cout<<"Enter First Number: ";
            cin>>a;
            cout<<"Enter Second Number: ";
            cin>>b;
            cout<<"Enter Third Number: ";
            cin>>c;
            cout<<"Enter Fourth Number: ";
            cin>>d;
            large = (a>b && a>c && a>d)? a : (b>a && b>c && b>d)? b : (c>a && c>b && c>d) ? c : d ;
            cout<< "Large: "<<large<<endl;





    }

return 0;
}
