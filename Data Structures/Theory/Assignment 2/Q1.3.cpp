#include <iostream>
#include <cstring>
#include <cmath>
#include "stack_int.h"
using namespace std;
int postf(string inp){
    int i=0;
    int a=0;
    int b=0;
    stackin s1;
    while (inp[i]!='\0')
    {
        if(inp[i] == '+' || inp[i] == '-' || inp[i] == '*' || inp[i] == '/' || inp[i] == '^')
        {
            b = s1.Pop();
            a = s1.Pop();
            switch (inp[i])
            {
            case '+':
                s1.Push(a + b);
                break;
            case '-':
                s1.Push(a - b);
                break;
            case '*':
                s1.Push(a * b);
                break;
            case '/':
                s1.Push(a / b);
                break;
            case '^':
                s1.Push(pow(a,b));
                break;
            default:
                break;
            }
        }else{
            s1.Push(inp[i]-'0');
        }
        i++;
    }
    return s1.Pop();
    
}

int main(){
    string inp;
    cout<<"Enter the postfix Expression: ";
    cin>>inp;

    cout<<postf(inp)<<endl;


    return 0;
}