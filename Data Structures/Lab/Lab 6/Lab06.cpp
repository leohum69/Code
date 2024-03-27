#include <iostream>
using namespace std;
class Student{
private:
    string student_Name;
    string student_ID;
    double CGPA;
    int age;
public:
    Student(){
        student_Name = "Mushtaq";
        student_ID = "0";
        CGPA = 4.00;
        age = 17;
    }
    Student(string name,string id,double cgp,int ag){
        student_Name = name;
        student_ID = id;
        CGPA = cgp;
        age = ag;
    }
    void Display(){
        cout<<"Student Name : "<<student_Name<<endl;
        cout<<"Student ID : "<<student_ID<<endl;
        cout<<"Student CGPA : "<<CGPA<<endl;
        cout<<"Student Age : "<<age<<endl;
    }
    void operator= (const Student &emp){
        this->student_Name = emp.student_Name;
        this->student_ID = emp.student_ID;
        this->CGPA = emp.CGPA;
        this->age = emp.age;
    }
    int getage(){
        return age;
    }
    void setgpa(double gpa){
        this->CGPA = gpa;
    }
    double getcgpa(){
        return CGPA;
    }
};

class Node{
public:
    Student stud;
    int prior;
    Node * next;

    Node(){
        next = NULL;
        prior = -1;
    }
};
class Queue{
private:
    Node * head;
    Node * rear;
public:
    Queue(int ignored=0){
        head = NULL;
        rear = NULL;
    }
    ~Queue(){
        if(head!=NULL){
            Node* curr = head;
            Node* curr2=NULL;
            while(curr){
                curr2 = curr->next;
                delete curr;
                curr=curr2;
            }
        }
    }
    void Enqueue(const Student &stu , int priority){
        if(head == NULL){
            Node * curr = new Node;
            curr->stud = stu;
            curr->prior = priority;
            head = curr;
            rear = curr;
        }else{
            Node * curr = new Node;
            curr->stud = stu;
            curr->prior = priority;
            rear->next = curr;
            rear = curr;
        }
    }
    void Dequeue (){
        if(head == NULL){
            return;
        }
        else{
            Node * curr = head;
            head = head->next;
            delete curr;
        }
    }
    void PriorityBasedDequeue(){
        if(head == NULL)
            return;
        
        Node * temp = head;
        Node * curr = head;
        Node * purr2 = temp;
        int i = curr->prior;
        while (curr)
        {
            if( i < curr->prior){
                i = curr->prior;
                temp = curr;
            }
            curr = curr->next;
        }
        if(temp == head){
            Node * purr = head;
            head = head->next;
            delete purr;
        }else{
            Node * purr2 = temp;
            bool chk = false;
            if(temp == rear){
                chk = true;
            }
            curr =  head;
            while (curr)
            {
                if(curr->next == purr2){
                    break;
                }
                curr = curr->next;   
            }
            if(chk){
                delete purr2;
                rear = curr;
                curr->next = NULL;
            }else{
                curr->next = purr2->next;
                delete purr2;
            }
        }
    }
    Node * FRONT(){
        return head;
    }
    Node * REAR(){
        return rear;
    }

    void Display(){
        Node * temp;
        temp = head;
        int i=1;
        if(head==NULL){
            cout<<"No data"<<endl;
            return;
        }
        while(temp!=NULL){
            cout<<i<<"th Student"<<endl;
            (*temp).stud.Display();
            cout<<"priority == "<<temp->prior<<endl;
            cout<<endl;
            temp = (*temp).next;
            i++;
        }
    }
    void clear(){
        if(head == NULL){
            return;
        }else{
            Node * curr = head;
            Node * curr2 = NULL;
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
        return !(head == NULL);
    }
};

int main(){
    Queue q1;
    Student s1;
    Student s2("lalaleo","i221749",3.6,69);
    Student s3("Mushtaq","1122",4.69,50);
    Student s4("saifi","2255",2.0,30);
    q1.Enqueue(s1,1);
    q1.Enqueue(s2,2);
    q1.Enqueue(s3,4);
    q1.Enqueue(s4,5);
    q1.Display();
    //q1.Dequeue();
    q1.PriorityBasedDequeue();
    q1.Enqueue (s1,69);
    cout<<"other"<<endl;
    q1.Display();
    //q1.FRONT()->stud.Display();
    //q1.REAR()->stud.Display();


}