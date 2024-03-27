/*
Name : Mirza Humayun Masood.
Roll No : I22-1749
Class : BSCY(A)
*/
#include <iostream>

using namespace std;

int main(){

    float hard,car,ten;

    cout<<"Enter Value of Hardness: ";
    cin>>hard;
    cout<<"Enter Value of Carbon content: ";
    cin>>car;
    cout<<"Enter Value of Tensile strength: ";
    cin>>ten;

    bool a = (hard>50);
    bool b = (car<0.7);
    bool c = (ten>5600);
    if(a && b &&c){
        cout<<"Grade is 10"<<endl;
    }else if(a && b){
        cout<<"Grade is 9"<<endl;
    }else if(b && c){
        cout<<"Grade is 8"<<endl;
    }else if(a && c){
        cout<<"Grade is 7"<<endl;
    }else if(a || b || c){
        cout<<"Grade is 6"<<endl;
    }else {
        cout<<"Grade is 5"<<endl;
    }




return 0;
}
