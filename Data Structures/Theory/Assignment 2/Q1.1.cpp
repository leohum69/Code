#include<iostream>
#include<cmath>
#include"stack_int.h"
using namespace std;

int fun1(long long int x , stackin &s1){
    while (x != 0)
    {   
        if(x%10 == 1 || x%10 == 0){
            s1.Push(x%10);
            x=x/10;
        }else{
            return -1;
        }
    }
    int ret = 0;
    int i = s1.size()-1;
    while (!s1.isEmpty())
    {
        ret = ret + ( s1.Pop() * pow(2 ,i) );
        i--;     
    }
    
    return ret;
}

int main(){
    stackin s1;
    cout<<"Enter The Binary Number: ";
    long long int x;
    cin>>x;
    while(x<0){
        cout<<"Value cant be -ve.. Enter Again : ";
        cin>>x;
    }
    if(fun1(x,s1) == -1){
        cout<<"Value was not valid"<<endl;
    }else{
        cout<<"Your Interger is "<< fun1(x,s1) <<endl;
    }

    return 0;
}