/*
Mirza Humayun Masood
I22-1749
BS-CY(A)
*/
#include<iostream>

using namespace std;

int main(){

    for(int i=1;i<=40;i++){         //for loop for first line
        cout<<"-";
    }
    cout<<endl;
    for(int i=1;i<=11;i++){         //for loop for 2nd line
        if(i==1){
            cout<<"_-^";
        }else if(i==11){
            cout<<"-";
        }else{
            cout<<"-_-^";
        }
    }
    cout<<endl;
    for(int i=1,j=1;j<=20;i++,j++){         //for loop for numbers
        cout<<i<<i;
        if(i==9){
            i=-1;
        }
    }
    cout<<endl;
    for(int i=1;i<=40;i++){                 //for loop for last line
        cout<<"-";
    }
    cout<<endl;







return 0;
}
