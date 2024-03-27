/*
Mirza Humayun Masood
I22-1749
BS-CY(A)
*/
#include<iostream>
#include<cmath>

using namespace std;

int main(){
    float x=2;
    float a=1;
    float b=2;

    do{             //do while
    cout<<a<<" / "<<b<<" = "<<a/b <<","<<endl;
    a=pow(2,x)-1;
    b=b*2;
    x++;
    }while(x<10);


return 0;
}
