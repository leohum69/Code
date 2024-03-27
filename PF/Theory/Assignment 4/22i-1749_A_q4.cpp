/*
Name: Mirza Humayun Masood
Roll No : i22-1749
Class : BS-CY(S)
*/
#include <iostream>
#include <cmath>
using namespace std;

int palin(int);     //prototype

int main(){
    //int c=0;
    for(int i=10;i<=99999;i++){     //for loop for numbers
        if(palin(i)==i){
            cout<<i<<" is a Palindrome Number."<<endl;
            c++;
        }
    }


    //cout<<c;

return 0;
}
int palin(int x){           //function
    int a=x;
    int p=0;
    int c=0;
    int counter=0;
    int counter2=0;
    while(a>0){         //while loop for counting number of digits
        a=a/10;
        counter++;
    }
    a=x;
    while(a>0){         //while loop for reversing the number
        c = (a / pow(10,counter-1));
        p = p + (c * pow(10,counter2));
        a = a - (c * pow(10,counter-1));
        counter--;
        counter2++;
    }
    return p;       //returning the value
}
