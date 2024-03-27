/*
Mirza Humayun Masood
I22-1749
BS-CY(A)
*/
#include<iostream>

using namespace std;

int main(){

    int i=1;
    int j=1;
    int k=1;
    int x=1;

    while(i<=6){            //outer while
        while(j<=9){            //inner while
            cout<<" ";
            j++;
        }
        cout<<"|";
        i++;
        j=1;
    }
    cout<<endl;
    while(k<=60){           //while
        if(x==10){
            x=0;
        }
        cout<<x;
        k++;
        x++;

    }




return 0;
}
