/*
Mirza Humayun Masood
I22-1749
BS-CY(A)
*/
#include<iostream>

using namespace std;
int main(){
    int a=11;
    int b=2;
    for(int qew=1;qew<=3;qew++){        //outer loop run 3 times
        for(int i=1;i<=3;i++,b=b+2,a=a-4){      //inner loop for some specific part
            for(int j=1;j<=b;j++){
                cout<<" ";
            }
            cout<<"*";
            for(int j=1;j<=a;j++){
                cout<<" ";
            }
            cout<<"*";
            cout<<endl;
        }
        for(int i=1;i<=8;i++){
            cout<<" ";
        }
        cout<<"*";
        cout<<endl;

        a=3;
        b=6;
        if(qew==3){             //for last iteration an if part :3

            for(int i=1;i<=3;i++,b=b-2,a=a+4){
                for(int j=1;j<=b;j++){
                    cout<<" ";
                }
                cout<<"*";
                for(int j=1;j<=a;j++){
                    cout<<" ";
                }
                cout<<"*";
                cout<<endl;
            }
        }else{
            for(int i=1;i<=4;i++,b=b-2,a=a+4){
                for(int j=1;j<=b;j++){
                    cout<<" ";
                }
                cout<<"*";
                for(int j=1;j<=a;j++){
                    cout<<" ";
                }
                cout<<"*";
                cout<<endl;
            }
        }
        a=11;
        b=2;
    }





return 0;
}
