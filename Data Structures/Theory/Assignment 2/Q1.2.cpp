#include<iostream>
#include<cmath>
#include"stack_int.h"
using namespace std;

long long int fun1(int x , stackin &s1){
    while (x > 0)
    {
        s1.Push(x%2);
        x=x/2;
    }
    long long int ret = 0;
    int i = s1.size() - 1;
    while (!s1.isEmpty())
    {
        ret = ret + (s1.Pop() * pow (10,i));
        i--;
    }
    
    return ret;
}

int main(){
    stackin s1;
    cout<<"Enter The Integer Number: ";
    int x;
    cin>>x;
    while(x<0){
        cout<<"Value cant be -ve.. Enter Again : ";
        cin>>x;
    }
    cout<<"Your Binary Value is "<< fun1(x,s1) <<endl;

    return 0;
}