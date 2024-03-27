/*
Name: Mirza Humayun Masood
Roll No : i22-1749
Class : BS-CY(S)
*/
#include <iostream>
using namespace std;

bool highlow(int);      //prototype

int main(){

    int x;      //declaration
    cout<<"Enter Number: ";
    cin>>x;
    if(x<=0){
        cout<<"Invalid Input."<<endl;           //invalid chk
    }else{
        if(highlow(x)==1){              //output
            cout<<"The number is highlow"<<endl;
        }else{
            cout<<"The number is not a highlow"<<endl;
        }
    }






return 0;
}
bool highlow(int x){                //function
    int a=x;
    int c=0;
    int counter=0;          //declaration
    int counter1=0;
    int counter2=1;
    bool chk=false;
    char xd1=' ',xd2=' ',xd3=' ',xd4=' ';
    int p=0;
    int q=0;
    int e=0;
    int l=1,k=2,j=3,h=4;

    while(a>0){                 //while for counter
        a=a/10;
        counter++;
    }
    if(counter==1){
        return true;
    }
    a=x;
    while(a>0){             //while loop for checking highlow
        c = a % 10;
        if(counter2==l){
            p=c;
            if(p>=0 && p<=4){
                xd1='L';
            }else{
                xd1='H';
            }
        }else if(counter2==k){
            q=c;
            if(q>=0&& q<=4){
                xd2='L';
            }else{
                xd2='H';
            }
        }else if(counter2==j){
            p=c;
            if(p>=0 && p<=4){
                xd3='L';
            }else{
                xd3='H';
            }
        }else if(counter2==h){
            q=c;
            if(q>=0 && q<=4){
                xd4='L';
            }else{
                xd4='H';
            }
        }

        a=a/10;
        counter1++;
        if(counter2==4){
            l=l+4;
            k=k+4;
            j=j+4;
            h=h+4;
        }
        counter2++;
        if(counter==2){
            if(xd1!=xd2){
                chk = true;
            }
        }
        if(counter==3){
            if(xd1==xd3){
                if(xd1 != xd2){
                    chk =true;
                }
            }
        }
        if(counter2>=4){
            if(xd1==xd3){
                if(xd2==xd4){
                    if(xd1 != xd2){
                        if(xd3 != xd4){
                            chk=true;
                        }
                    }
                }
            }
        }

    }
    return chk;         //returning the bool :3



}
