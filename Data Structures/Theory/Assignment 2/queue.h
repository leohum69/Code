#include <iostream>
#include <cstring>
using namespace std;
class node{
public:
    string stud;
    node * next;

    node(){
        next = NULL;
    }
};
class Queue{
private:
    node * head;
    node * rear;
public:
    Queue(int ignored=0){
        head = NULL;
        rear = NULL;
    }
    ~Queue(){
        if(head!=NULL){
            node* curr = head;
            node* curr2=NULL;
            while(curr){
                curr2 = curr->next;
                delete curr;
                curr=curr2;
            }
        }
    }
    void Enqueue(string a){
        if(head == NULL){
            node * curr = new node;
            curr->stud = a;
            head = curr;
            rear = curr;
        }else{
            node * curr = new node;
            curr->stud = a;
            rear->next = curr;
            rear = curr;
        }
    }
    void Dequeue (){
        if(head == NULL){
            return;
        }
        else{
            node * curr = head;
            head = head->next;
            delete curr;
        }
    }
    node * FRONT(){
        return head;
    }
    node * REAR(){
        return rear;
    }

    void Display(){
        node * temp;
        temp = head;
        if(head==NULL){
            cout<<"No data"<<endl;
            return;
        }
        while(temp!=NULL){
            cout<<temp->stud<<" ";
            temp = (*temp).next;
        }
    }
    void clear(){
        if(head == NULL){
            return;
        }else{
            node * curr = head;
            node * curr2 = NULL;
            while(curr){
                curr2 = curr->next;
                delete curr;
                curr = curr2;
            }
            head = NULL;
            rear = NULL;
        }
    }
    bool isempty(){
        return (head == NULL);
    }
};