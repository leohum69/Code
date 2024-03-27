/*
Name : Mirza Humayun Masood.
Roll No : I22-1749
Class : BSCY(A)
*/
#include<iostream>

using namespace std;

int main(){
    cout<<"Enter 1 for Rock"<<endl;
    cout<<"Enter 2 for Paper"<<endl;
    cout<<"Enter 3 for Scissors"<<endl;
    int a,b;
    cout<<"First Player: ";
    cin>>a;
    cout<<"Second Player: ";
    cin>>b;

    if(a!=b){
        if(a==1 && b==2){
            cout<<"Second Player wins"<<endl;
        }else if(a==1 && b==3){
            cout<<"First Player wins"<<endl;
        }else if(a==2 && b==1){
            cout<<"First Player wins"<<endl;
        }else if(a==2 && b==3){
            cout<<"Second Player wins"<<endl;
        }else if(a==3 && b==1){
            cout<<"Second Player wins"<<endl;
        }else if(a==3 && b==2){
            cout<<"First Player wins"<<endl;
        }
    }else {
        cout<<"Draw"<<endl;
    }




return 0;
}
