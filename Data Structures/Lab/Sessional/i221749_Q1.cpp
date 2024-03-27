#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;
};
class Stack{
    Node * top;
    public:
    Stack(){
        top = NULL;
    }
    void insert(int x){
        Node * temp = new Node;
        temp -> data= x;
        temp->next = top;
        top = temp;
    }
    int pop(){
        Node * temp = NULL;
        temp = top;
        top = top->next;
        int a= temp->data;
        delete temp;
        return a;
    }
    void print(){
        if(top==NULL)
            return;
        Node * temp = top;
        while (temp)
        {
            cout << temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
bool ret(int * arr,int size){
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
    
}
bool check(int * arr,int size){
    Stack s1;
    for (int i = 0; i < size; i++)
    {
        s1.insert(arr[i]);
    }
    int arr2[size]={0};
    for (int i = 0; i < size; i++)
    {
        arr2[i]=s1.pop();
    }
    return ret(arr2,size);
    
}

int main(){
    int arr[]= {10,9,8,7,6,5,4,3,2,1};
    if(check(arr,10)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
   
    return 0;
}