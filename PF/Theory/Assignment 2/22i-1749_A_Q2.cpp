/*
Name : Mirza Humayun Masood.
Roll No : I22-1749
Class : BSCY(A)
*/
#include<iostream>

using namespace std;

int main(){

    int choice;
    cout<<"1. Calculate the Area of a Circle"<<endl;
    cout<<"2. Calculate the Area of a Rectangle"<<endl;
    cout<<"3. Calculate the Area of a Triangle"<<endl;
    cout<<"4. Quit"<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;

    cout<<endl<<endl;

    switch(choice){
        case 1:
            float r;
            cout<<"Enter Radius: ";
            cin>>r;
            cout<<"Area is: "<< (3.14159)*(r*r)<<endl;
        break;
        case 2:
            float length,width;
            cout<<"Enter Length: ";
            cin>>length;
            cout<<"Enter Width: ";
            cin>>width;

            cout<<"Area is: "<<(length*width)<<endl;
        break;
        case 3:
            float base,height;
            cout<<"Enter Triangle's Base: ";
            cin>>base;
            cout<<"Enter Triangle's Height: ";
            cin>>height;

            cout<<"Area is: "<< base*height*0.5<<endl;
        break;
        case 4:
            break;

        default:
            cout<<"Invalid Input"<<endl;
            break;


    }







return 0;
}
