/*
Mirza Humayun Masood
I22-1749
BS-CY(A)
*/
#include <iostream>

using namespace std;

int main(){
    int k=8;
    int p=1;
    int q=0;
    for(int i=0;i<=8;i++,k--,p++,q++){      //outer for loop for upper part
        for(int i=1;i<=k;i++){              //inner for loop for spaces
            cout<<"  ";
        }
        for(int i=1;i<=p;i++){              //inner for loop for numbers in ascending order
            cout<<i<<" ";
        }
        for(int i=q;i>=1;i--){              //inner for loop for numbers in decendibng order
            cout<<i<<" ";
        }
        cout<<endl;
    }
    p=1;
    q=8;
    for(int i=0;i<=8;i++,p++,q--){      //outer loop for lower part
        for(int i=1;i<=p;i++){          //inner for loop for spaces
            cout<<"  ";
        }
        for(int i=1;i<=q;i++){          //inner for loop for lower left part
            cout<<i<<" ";
        }
        cout<<endl;
    }



return 0;
}
