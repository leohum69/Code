/*
Mirza Humayun Masood
I22-1749
BS-CY(A)
*/
#include<iostream>

using namespace std;

int main(){
    int a=1;
    int i=1;
    int j=1;
    int counter1=4;
    while(i<6){                 //outer while
        while(a<=counter1){         //inner while for spaces
            cout<<" ";
            a++;
        }
        a=1;
        while(j<=i){        //inner while for numbers
            cout<<i;
            j++;
        }
        j=1;
        i++;
        counter1--;
        cout<<endl;

    }




return 0;
}
