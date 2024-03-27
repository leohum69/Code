/*
Mirza Humayun Masood
I22-1749
BS-CY(A)
*/
#include<iostream>

using namespace std;

int main(){

    int a=0,b=0;
    int counter1=1,counter2=0;
    int six=0;


    while(six<6){               //outer while
        while(a<counter1){         //while for left #
            cout<<"#";
            a++;
        }
        a=0;
        while(b<counter2){          //while for spaces
            cout<<" ";
            b++;
        }
        while(a<counter1){          //while for right #
            cout<<"#";
            a++;
        }
        cout<<endl;
        a=0,b=0;
        counter2++;
        six++;

    }

return 0;
}
