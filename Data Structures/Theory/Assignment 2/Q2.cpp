#include <iostream>
#include <cstring>
#include <cmath>
#include "stack_char.h"
#include "stack_int.h"
#include "queue.h"
using namespace std;
int postfixconv(string inp){
    int i=0;
    Queue q1;
    stack s1;
    string p1;
    bool x = false;
    while (inp[i]!='\0')
    {
        if(inp[i] == '+' || inp[i] == '-' || inp[i] == '*' || inp[i] == '/' || inp[i] == '^'){
            s1.Push(inp[i]);
        }else if(inp[i] == ')'){
            q1.Enqueue(string(1,s1.Pop()));
        }else if(inp[i]=='('){
            i++;
            continue;
        }else{
            while (inp[i]!='\0')
            {   x = inp[i+1] == '+' || inp[i+1] == '-' || inp[i+1] == '*' || inp[i+1] == '/' || inp[i+1] == '^' || inp[i+1] == '(' || inp[i+1] == ')' || inp[i+1] == '\0';
                if(x){
                    p1.append(string(1,inp[i]));
                    q1.Enqueue(p1);
                    p1.clear();
                    break;
                }
                else{
                    p1.append(string(1,inp[i]));
                    //cout<<p1<<endl;
                }
                i++;
            }
        }
        i++;
    }
    while (!s1.isEmpty())
    {
        q1.Enqueue(string(1,s1.Pop()));
    }
    
    //cout<<"xd";
    q1.Display();
    cout<<endl;
    stackin s2;
    int a = 0;
    int b = 0;
    while (!q1.isempty())
    {
        if(q1.FRONT()->stud == "+" || q1.FRONT()->stud == "-" || q1.FRONT()->stud == "*" || q1.FRONT()->stud == "/" || q1.FRONT()->stud == "^")
        {
            b = s2.Pop();
            a = s2.Pop();
            if(q1.FRONT()->stud == "+"){
                s2.Push(a+b);
            }else if(q1.FRONT()->stud == "-"){
                s2.Push(a-b);
            }else if(q1.FRONT()->stud == "*"){
                s2.Push(a*b);
            }else if(q1.FRONT()->stud == "/"){
                s2.Push(a/b);
            }else if(q1.FRONT()->stud == "^"){
                s2.Push(pow(a,b));
            }
        }else{
            s2.Push(stoi(q1.FRONT()->stud));
        }
        q1.Dequeue();
    }
    return s2.Pop();
    
}
int main(){
    cout<<"Enter the Expression: ";
    string inp;
    cin>>inp;
    cout<<"answerjee : "<<postfixconv(inp)<<endl;

    return 0;
}