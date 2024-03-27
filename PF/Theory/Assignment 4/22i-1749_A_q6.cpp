/*
Name: Mirza Humayun Masood
Roll No : i22-1749
Class : BS-CY(S)
*/
#include <iostream>
using namespace std;

void pew(int,int);

int main(){
    int x,y;
    cout<<"Lines = ";
    cin>>x;
    cout<<"Cheers = ";
    cin>>y;

    if(x<=0 || y<=0){
        cout<<"Invalid Input"<<endl;
    }else{
        pew(x,y);
    }



return 0;
}
void pew(int x,int y){
    int p=0;
    for(int i=1;i<=x;i++,p=p+3){
        for(int j=1;j<=p;j++){
            cout<<" ";
        }
        if(y==1){
            cout<<"go";
        }
        else{
            for(int k=1;k<=y;k++){
                cout<<"go ";
                if(k!=y){
                    cout<<"buddy ";
                }
            }
        }

        cout<<endl;
    }
}
