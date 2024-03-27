/*
Mirza Humayun Masood
I22-1749
BS-CY(A)
*/
#include<iostream>

using namespace std;

int main(){

    int counter=6;
    int counter1=1;
    int counter2=6;
    int counter3=0;

for(int i=1;i<=7;i++,counter--,counter1++,counter2--,counter3++){           //outer for
    for(int j=1;j<=counter;j++){        //inner fors
        cout<<"*";
    }
    for(int k=1;k<=counter1;k++){       //inner fors
        cout<<" ";
    }
    for(int m=1;m<=counter2;m++){       //inner fors
        cout<<"//";
    }
    for(int n=1;n<=counter3;n++){       //inner fors
        cout<<"\\\\";
    }
    for(int k=1;k<=counter1;k++){       //inner fors
        cout<<" ";
    }
    for(int j=1;j<=counter;j++){        //inner fors
        cout<<"*";
    }
    cout<<endl;
}

return 0;
}
