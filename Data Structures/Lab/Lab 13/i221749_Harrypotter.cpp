#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class paired{
    public:
    string first;
    int second;
    paired(){
        first = "pew";
        second = -1;
    }
    paired(string s1,int s2){
        first = s1;
        second = s2;
    }
    paired(paired & p1){
        first = p1.first;
        second = p1.second;
    }
};
class student{
    public:
    string name;
    string House;
    int quality[5];
    student(){
        name = "Chacha Mushtaq Ali";
        quality[0] = 10;
        quality[1] = 10;
        quality[2] = 10;
        quality[3] = 10;
        quality[4] = 10;
        House = "";
    }
    student(string name,int a,int b,int c,int d,int e){
        this->name = name;
        quality[0] = a;
        quality[1] = b;
        quality[2] = c;
        quality[3] = d;
        quality[4] = e;
    }
    student(const student& s1){
        this->name = s1.name;
        for (int i = 0; i < 5; i++)
        {
            this->quality[i] = s1.quality[i];
        }
        House = s1.House;
        
    }
    void print(){
        cout<<"Name : "<<name<<endl;
        cout<<"Magical_Abilities : "<<quality[0]<<endl;
        cout<<"Bravery : "<<quality[1]<<endl;
        cout<<"Cunning : "<<quality[2]<<endl;
        cout<<"Intelligence : "<<quality[3]<<endl;
        cout<<"Loyalty : "<<quality[4]<<endl;

        cout<<endl<<"House : "<<House<<endl;
        cout<<"--------------------------------------"<<endl;
    }

};
    ostream & operator<< (ostream &out, student &c){
        c.print();
        return out;
    }
class node{
    public:
    student data;
    node * next;
    node(student& x){
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
    void insert(student& x){
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
    int size(){
        node * temp = head;
        int i=0;
        while (temp!=NULL)
        {
            temp = temp->next;
            i++;
        }
        return i;
    }
};
class graph{
    public:
    vector<adjlist> arr;
    int vert;

    graph(int size){
        vert = size;
    }
    void insert(vector<student> & v1){
        
        
        for (int i = 0; i < vert; i++)
        {
            arr.push_back(adjlist());
            arr[i].insert(v1[i]);
        }
        
    }
    void showGraphStructure(){
        for (int i = 0; i < vert; i++)
        {
            arr[i].print();
            cout<<endl;
        }
    }
    void insertedge(string src, string des){
        int size;
        int size2;
        student s1;
        student s2;
        for (int i = 0; i < vert; i++)
        {
            if(arr[i].head->data.name == src){
                size = i;
                s1 = arr[i].head->data;
                break;
            }
        }
        for (int i = 0; i < vert; i++)
        {
            if(arr[i].head->data.name == des){
                size2 = i;
                s2 = arr[i].head->data;
                break;
            }
        }
        
        arr[size].insert(s2);
        arr[size2].insert(s1);
    }
    void addver(student & s1){
        arr.push_back(adjlist());
        arr[vert++].insert(s1);
    }
};
void swappair(paired& p1,paired& p2){
    paired p3;
    p3 = p1;
    p1 = p2;
    p2 = p3;
}
void bubbleSort(paired arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].second > arr[j + 1].second) {
                swappair(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

void sort(vector<student>& v1,graph & g1){
    int x = -1;
    paired arr[5];
    paired pew[v1.size()];
    paired pew2[v1.size()];
    arr[0].first = "Magical_Abilities";
    arr[1].first = "Bravery";
    arr[2].first = "Cunning";
    arr[3].first = "Intelligence";
    arr[4].first = "Loyalty";


    for (int i = 0; i < v1.size(); i++)
    {
        for(int j=0;j<5;j++){
            arr[j].second = v1[i].quality[j];
        }
        bubbleSort(arr,5);
        pew[i] = arr[4];
        pew2[i] = arr[3];
    }

    for (int i = 0; i < v1.size(); i++)
    {
        if((pew[i].first == "Bravery" && pew2[i].first == "Loyalty" )||(pew[i].first == "Loyalty" && pew2[i].first == "Bravery" )){
            v1[i].House = "Gryffindor";
        }else if((pew[i].first == "Magical_Abilities" && pew2[i].first == "Loyalty" )||(pew[i].first == "Loyalty" && pew2[i].first == "Magical_Abilities" )){
            v1[i].House = "Hufflepuff";
        }else if((pew[i].first == "Intelligence" && pew2[i].first == "Magical_Abilities" )||(pew[i].first == "Magical_Abilities" && pew2[i].first == "Intelligence" )){
            v1[i].House = "Ravenclaw";
        }else if((pew[i].first == "Cunning" && pew2[i].first == "Bravery" )||(pew[i].first == "Bravery" && pew2[i].first == "Cunning" )){
            v1[i].House = "Slytherin";
        }else{
            v1[i].House = "FSM";
        }
    }
}
int main(){
    student v1 ("Harry", 8, 9, 7, 8, 5);
    student v2 ("Ron", 7, 8, 6, 7, 4);
    student v3 ("Hermione", 9, 10, 10, 9, 7);
    student v4 ("Draco", 6, 7, 8, 5, 9);
    vector<student>stud;
    stud.push_back(v1);
    stud.push_back(v2);
    stud.push_back(v3);
    stud.push_back(v4);
    graph g1(4);
    // g1.insert(stud);
    // g1.insertedge("Harry", "Ron");
    // g1.insertedge("Harry", "Hermione");
    // g1.insertedge("Ron", "Hermione");
    // g1.insertedge("Draco", "Harry");

    // g1.showGraphStructure();
    sort(stud,g1);
    for (int i = 0; i < stud.size(); i++)
    {
        stud[i].print();
    }
    

    return 0;
}