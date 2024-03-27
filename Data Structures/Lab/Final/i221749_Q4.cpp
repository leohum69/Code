#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node * next;
    node(int x){
        data = x;
        next = NULL;
    }
};

class stacks{
    public:
    node * head;
    int s;

    stacks(){
        head = NULL;
        s = 0;
    }

    void insert(int x){
        if(head == NULL){
            head = new node(x);
            s++;
            return;
        }
        node * temp = head;
        head = new node (x);
        head->next = temp;
        s++;

        return;
    }

    int remove(){
        if(head == NULL){
            cout<<"no element"<<endl;
            return -1;
        }
        s--;
        node * x = head;
        int dat = head->data;
        head = head->next;
        delete x;
        return dat;
    }
    void print(){
        node * temp = head;
        while (temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    void clear(){
        // if(head == NULL){
        //     s = 0;
        //     head = NULL;
        //     return;
        // }
        // if(head->next == NULL){
        //     delete head;
        //     head = NULL;
        //     s = 0;
        //     return;
        // }
        // node * temp = head;
        // node * temp2 = NULL;
        // while (temp->next)
        // {
        //     temp2 = temp;
        //     temp = temp->next;
        //     delete temp2;
        // }
        s = 0;
        head = NULL;
        // s=0;
        
    }
};
void span(stacks s1){
    int x=1;
    int now = s1.remove();
    int size = s1.s;
    // cout<<size;
    int chke = 0;
    bool c = true;
    for (int i = 0; i < size; i++)
    {
        chke = s1.remove();
        if(chke < now){
            x++;
            // c = true;
        }else{
            break;
        }
    }
    cout<<x<<" ";
}
void calculateStockSpan(int * arr , int size){
    stacks s1;
    for (int i = 1; i < size+1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            s1.insert(arr[j]);
        }
        span(s1);
        s1.clear();
    }
    
    // s1.print();
}


int main(){

    cout<<"Enter num of days : ";
    int days;
    cin>>days;
    // int arr[7] = {100,80,60,70,60,75,85};
    int *arr = new int[days];

    for (int i = 0; i < days; i++)
    {
       cout<<"Enter The Values of stocks in day "<<i+1<<" : ";
       cin>>arr[i];
    }
   calculateStockSpan(arr,days); 



    return 0; 
}