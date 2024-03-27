/*
Name : Mirza Humayun Masood.
Roll No : I22-1749
Class : BSCY(A)
*/
#include <iostream>
#include <ctime>

using namespace std;

int main(){

    srand(time(0));
    unsigned short inp;
    cout<<"Enter Your Input: ";
    cin>>inp;

    unsigned short oper,left,right;
    right = inp & 63;
    left = (inp >> 6) & 63;
    oper = (inp>>12) & 15;

    switch(oper){
        case 0:
            cout<<"Display Value of Right Operand"<<endl;
            cout<<"Right operand: "<<right<<endl;
            break;
        case 1:
            cout<<"Display Value of Left Operand: "<<endl;
            cout<<"Left operand: "<<left<<endl;
            break;
        case 2:
            cout<<"Take (6-bit) Random input in Right operand"<<endl;
            right = rand()%63;
            right = right & 63;
            inp = inp & right;
            break;
        case 3:
            cout<<"Take (6-bit) Random input in Left operand"<<endl;
            left = rand()%63;
            left = (left<<6) & 4032;
            inp = inp & right;
            break;
        case 4:
            cout<<"Add Left and Right operand"<<endl;
            cout<<left<<" + "<<right << " = "<<(left+right)<<endl;
            break;
        case 5:
            cout<<"Calculate Subtraction of operands (Subtract Smaller from Larger)"<<endl;
            if(left>right){
                cout<<left <<" - "<<right<< " = "<< (left - right)<<endl;
            }else{
                cout<<right <<" - "<<left<< " = "<< (right - left)<<endl;
            }
            break;
        case 6:
            cout<<"Multiply Left and Right operand"<<endl;
            cout<<left<< " x "<<right<< " = "<<(left*right)<<endl;
            break;
        case 7:
            cout<<"Calculate division of operands (Divide Larger from smaller)"<<endl;
            if(left>right){
                cout<<left <<" / "<<right<< " = "<< (left / right)<<endl;
            }else{
                cout<<right <<" / "<<left<< " = "<< (right / left)<<endl;
            }
            break;
        case 8:
            cout<<"Calculate remainder operands (Larger from smaller)"<<endl;
            if(left>right){
                cout<<left <<" % "<<right<< " = "<< (left % right)<<endl;
            }else{
                cout<<right <<" % "<<left<< " = "<< (right % left)<<endl;
            }
            break;
        case 9:
            cout<<"Bitwise OR of Left and Right operand"<<endl;
            cout<<left <<" | "<<right<< " = "<< (left | right)<<endl;
            break;
        case 10:
            cout<<"Bitwise AND of Left and Right operand"<<endl;
            cout<<left <<" & "<<right<< " = "<< (left & right)<<endl;
            break;
        case 11:
            cout<<"Bitwise XOR of Left and Right operand"<<endl;
            cout<<left <<" ^ "<<right<< " = "<< (left ^ right)<<endl;
            break;
        case 12:
            cout<<"Complement of Right"<<endl;
            cout<<"~ "<<right << " = "<<(~right)<<endl;
            break;
        case 13:
            cout<<"Complement of Left"<<endl;
            cout<<"~ "<<left << " = "<<(~left)<<endl;
            break;
        case 14:
            cout<<"Left Operand << Right Operand"<<endl;
            cout<<left <<" << "<<right<<" = "<<(left<<right)<<endl;
            break;
        case 15:
            cout<<"Left Operand >> Right Operand"<<endl;
            cout<<left <<" >> "<<right<<" = "<<(left>>right)<<endl;
            break;
    }





return 0;
}
