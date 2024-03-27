#include <iostream>
#include <cstring>
using namespace std;

class node{
    public:
    string name;
    string aurthor;
    int year;
    string lang;
    int edition;

    node * next;
    node(string n,string a, int y, string lan,int edi){
        name = n;
        aurthor = a;
        year = y;
        lang = lan;
        edition = edi;
        next = NULL;
    }
    node(const node& b1){
        name = b1.name;
        aurthor = b1.aurthor;
        year = b1.year;
        lang = b1.lang;
        edition = b1.edition;
        next = b1.next;
    }
    void print(){
        cout<<"Title : "<<name<<endl;
        cout<<"Aurthor : "<<aurthor<<endl;
        cout<<"Year : "<<year<<endl;
        cout<<"Language : "<<lang<<endl;
        cout<<"Edition : "<<edition<<endl;
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
    void insert(node book){
        if(head == NULL){
            head = new node(book);
            tail = head;
            return;
        }
        tail->next = new node(book);
        tail = tail->next;
    }
    void remove(int edi){
        if(head == NULL){
            return;
        }
        node * temp = head;
        if(head->edition == edi){
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
            if(temp->edition == edi){
                chk = true;
                break;
            }
        }
        cout<<boolalpha<<chk;
        if(!chk){
            cout<<"No edition found"<<endl;
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
            temp->print();
            temp = temp->next;
        }
        cout<<"end"<<endl;
        
    }
};

class node2{
    public:
    linklist l1;
    string name;
    node2 * next;

    node2(const linklist& l2){
        node * temp = l2.head;
        name = l2.head->name;
        while (temp)
        {
            l1.insert(*temp);
            temp = temp->next;
        }
        next = NULL;
        
    }
};

class doublel{
    public:
    node2 * head;
    node2 * tail;
    doublel(){
        head = NULL;
        tail = NULL;
    }
    void insert(node2 book){
        if(head == NULL){
            head = new node2(book);
            tail = head;
            return;
        }
        tail->next = new node2(book);
        tail = tail->next;
    }

    void print(){
        node2 * temp = head;
        while (temp->next != NULL)
        {
            // cout<<"bahir?";
            temp->l1.print();
            temp = temp->next;
            cout<<endl<<endl;
        }
    }

};


int main(){
    node n1("lol","leo",12,"eng",1);
    node n2("lol","leo",12,"eng",2);
    node n3("lol","leo",12,"eng",3);


    linklist ll;
    ll.insert(n1);
    ll.insert(n2);
    ll.insert(n3);

    // ll.print();

    // ll.remove(1);

    doublel l2;
    l2.insert(ll);
    l2.insert(ll);

    l2.print();

    

    return 0; 
}