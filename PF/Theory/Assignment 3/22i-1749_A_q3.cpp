/*
Mirza Humayun Masood
I22-1749
BS-CY(A)
*/
#include<iostream>

using namespace std;

int main(){

    int counter=11;
    int a=0;
    int b=0;
    int c=0;
    int counter2=0;

    for(int i=0;i<6;i++,counter2++,counter=counter-2){      //outer for loop
        while(b<counter2){          //loop for back slashes
            cout<<"\\\\";
            b++;
        }
        while(a<counter){           //loop for exclamation marks
            cout<<"!!";
            a++;
        }
        while(c<counter2){          //loop for forward slashes
            cout<<"//";
            c++;
        }
        cout<<endl;
        a=0;b=0;c=0;

    }

return 0;
}
