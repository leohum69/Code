/*
Name: Mirza Humayun Masood
Roll No : i22-1749
Class : BS-CY(S)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>
using namespace std;

double pi(char);        //prototype :3


int main(){
    char xd;
    int e=0;
    cout<<"Term#\t"<<"Value of pi"<<endl;
    pi('C');            //fuction call for the first time

    do{
        xd=getch();             //gettin value
        e=pi(xd);
        if(e!=0){
            cout<<e<<"is the Term where we get the 3.14 value."<<endl;          //gettin the term
            break;
        }else if(e== -1){
            cout<<"we did not find the number of terms to get 3.14 value."<<endl;       //if stopped earlier
            break;
        }
    }while(xd=='C');



return 0;
}

double pi(char p){              //function
    static int i=1;
    static int l=0;
    static float cc=4;
    static int dd=3;
    if(p=='S'){
        return -1;
    }else if(p== 'C'){
        l=l+5;
        for(;i<=l;i++,dd=dd+2){                     //for loop for gettin value
            cout<<i<<"\t"<<cc<<endl;
            if(i%2==0){
                cc = cc + static_cast<float>(4)/dd;
                cc = round(100 * cc) / 100.0;
            }else if(i%2!=0){
                cc = cc - static_cast<float>(4)/dd;
                cc = round(100 * cc) / 100.0;
            }
            if(cc == 3.14){
                return i;
                break;
            }
        }
    }
    return 0;



}



