#include<iostream>
#include <ctime>
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
class adjlist{
    public:
    node * head;
    node * tail;
    adjlist(){
        head = NULL;
        tail = NULL;
    }
    void insert(int x){
        if(head==NULL){
            head = new node(x);
            tail = head;
            return;
        }else{
            tail->next = new node(x);
            tail = tail->next;
        }
        return;
    }
    void print(){
        if(head == NULL){
            cout<<"List empty"<<endl;
            return;
        }
        cout <<"Vertice : "<<head->data<<" , Neighbours: ";
        for (node * i = head->next; i != NULL; i = i->next)
        {
            cout<<i->data<<" ";
        }
        cout<<endl;
        
    }
};
class graph{
    public:
    adjlist * arr;
    int vert;

    graph(int size){
        vert = size;
        arr = new adjlist[vert];
        for (int i = 0; i < vert; i++)
        {
            arr[i].insert(i);
        }
    }
    void showGraphStructure(){
        for (int i = 0; i < vert; i++)
        {
            arr[i].print();
            cout<<endl;
        }
    }
    void insertedge(int src, int des){
        if(src >= vert || des >= vert){
            cout<<"Out of Range Vertices."<<endl;
            return;
        }
        arr[src].insert(des);
        arr[des].insert(src);
    }

    // bool iscyclic(){
    //     bool arr[vert];
    //     arr[0] = true;
    //     for (int i = 0; i < vert; i++)
    //     {
    //         /* code */
    //     }
        
    // }

};


int main(){
    srand(time(0));
    graph g1(6);
    g1.insertedge(0,4);
    g1.insertedge(0,3);
    g1.insertedge(1,2);
    g1.insertedge(1,4);
    g1.insertedge(1,5);
    g1.insertedge(2,3);
    g1.insertedge(2,5);
    g1.insertedge(3,5);
    g1.insertedge(4,5);

    g1.showGraphStructure();
}