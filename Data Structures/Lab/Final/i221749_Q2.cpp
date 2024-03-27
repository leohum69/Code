#include <iostream>
using namespace std;

class pairstri{
    public:

    int intense;
    string c;
    pairstri(){
        c = "idk";
        intense = 0;
    }
    pairstri(int in,string c1){
        intense = in;
        c = c1;
    }
};

class memory{
    public:
    string event;
    pairstri emotion[5];
    float time;

    memory(){
        event = "data paper";
        time = 15.04;
        emotion[0].c = "Joy";
        emotion[1].c = "Sadness";
        emotion[2].c = "Anger";
        emotion[3].c = "Fear";
        emotion[4].c = "Disgust";
    }
    memory(string eve,int a, int b, int c, int d , int e , float ti){
        event = eve;
        time = ti;
        emotion[0].c = "Joy";
        emotion[1].c = "Sadness";
        emotion[2].c = "Anger";
        emotion[3].c = "Fear";
        emotion[4].c = "Disgust";

        emotion[0].intense = a;
        emotion[1].intense = b;
        emotion[2].intense = c;
        emotion[3].intense = d;
        emotion[4].intense = e;
    }
    memory(const memory& m1){
        event = m1.event;
        time = m1.time;
        emotion[0].c = "Joy";
        emotion[1].c = "Sadness";
        emotion[2].c = "Anger";
        emotion[3].c = "Fear";
        emotion[4].c = "Disgust";

        for (int i = 0; i < 5; i++)
        {
            emotion[i].intense = m1.emotion[i].intense;
        }
        
    }

    void print(){
        cout<<"Event : "<<event<<endl;
        cout<<"Time : "<<time<<endl;
        cout<<"Emotions"<<endl<<endl;

        for (int i = 0; i < 5; i++)
        {
            cout<<emotion[i].c<<" : "<<emotion[i].intense<<endl;
        }
    }

};

class pairs{
    public:
    memory first;
    pairstri second;

    pairs(){
    }
    pairs(memory m2,pairstri p2){
        first = m2;
        second = p2;
    }
};

class node{
    public:
    pairs data;
    node * next;
    node(pairs m1){
        data = m1;
        next = NULL;
    }
};
class linklist{
    public:
    node * head;
    node * tail;

    linklist(){
        head = NULL;
        tail = NULL;
    }
    void insert(pairs dat){
        if(head == NULL){
            head = new node(dat);
            tail = head;
            return;
        }
        tail->next = new node(dat);
        tail = tail->next;
    }
    void remove(string eve){
        if(head == NULL){
            return;
        }
        node * temp = head;
        if(head->data.first.event == eve){
            head = head->next;
            delete temp;
            return;
        }
        node * prev = NULL;
        bool chk = false;
        while (temp->next)
        {
            prev = temp;
            temp = temp->next;
            if(temp->data.first.event == eve){
                chk = true;
                break;
            }
        }
        cout<<boolalpha<<chk;
        if(!chk){
            cout<<"No memory found"<<endl;
            return;
        }
        temp = temp->next;
        delete prev->next;
        prev->next = temp;
    }
    void print(){
        node * temp = head;
        while (temp)
        {
            temp->data.first.print();
            temp = temp->next;
        }
        cout<<"end"<<endl;
        
    }
};

class Graph{
    public:
    linklist * arr;
    int vert;
    int crrvr;

    Graph(){
        vert = 100;
        crrvr = 0;
        arr = new linklist[vert];
    }

    void insertmem(memory m1){
        pairs p1;
        p1.first = m1;
        arr[crrvr++].insert(p1);
    }
    void insertedge(string event1,string event2,string emotion){
        int f,s;
        for (int i = 0; i < crrvr; i++)
        {
            if(arr[i].head->data.first.event == event1){
                f = i;
            }
            if(arr[i].head->data.first.event == event2){
                s=i;
            }
        }
        int ff,ss;
        for(int i=0;i<5;i++){
            if(arr[f].head->data.first.emotion[i].c == emotion){
                ff = arr[f].head->data.first.emotion[i].intense;
            }
            if(arr[s].head->data.first.emotion[i].c == emotion){
                ss = arr[s].head->data.first.emotion[i].intense;
            }
        }
        int result = (ff+ss)/2;

        arr[f].insert(pairs(arr[s].head->data.first , pairstri(result,emotion)));
        arr[s].insert(pairs(arr[f].head->data.first , pairstri(result,emotion)));
    }


};



int main(){


}