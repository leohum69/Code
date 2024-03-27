/*
Mirza Humayun Masood
I22-1749
BS-CY(A)
*/
#include<iostream>
#include<iomanip>

using namespace std;

int main(){

    cout<<"+";
    for(int i=0;i<6;i++){           //for loop for upper line
        cout<<"-";
    }
    cout<<"+"<<endl;
    for(int pew=1;pew<=2;pew++){            //outer for loop for lines
        int q=2;
        int p=0;
        for(int i=1;i<=3;i++,q--,p=p+2){        //inner for inner inner lines
            cout<<"|";
            for(int i=1;i<=q;i++){                  //more nested for loops for inner materials
                cout<<" ";
            }
            cout<<"^";
            for(int i=1;i<=p;i++){
                cout<<" ";
            }
            cout<<"^";
            for(int i=1;i<=q;i++){
                cout<<" ";
            }
            cout<<"|";
            cout<<endl;
        }
    }
    cout<<"+";
    for(int i=0;i<6;i++){
        cout<<"-";
    }
    cout<<"+"<<endl;

    for(int i=1;i<=2;i++){
        int q=4;
        int p=0;
        for(int j=1;j<=3;j++,p++,q=q-2){
            cout<<"|";
            for(int k=1;k<=p;k++){
                cout<<" ";
            }
            cout<<"v";
            for(int k=q;k>=1;k--){
                cout<<" ";
            }
            cout<<"v";
            for(int k=1;k<=p;k++){
                cout<<" ";
            }
            cout<<"|";

            cout<<endl;
        }
    }
    cout<<"+";
    for(int i=0;i<6;i++){
        cout<<"-";
    }
    cout<<"+"<<endl;





return 0;
}
