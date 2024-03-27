#include <iostream>
#include <string>
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
    Student(string name,string id,int cgp,int ag){
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
        return gpa;
    }
};
class Node{
public:
    Student st;
    Node * next;
    Node * prev;

    Node(){
        next = NULL;
        prev = NULL;
    }
};
class Linked_List{
private:
    Node * head;
public:
    Linked_List(int ignored=0){
        head = NULL;
    }
    ~Linked_List(){
        if(head!=NULL)
            delete head;
    }
    void insert(const Student &stud){
        Node * tempemp = new Node;
        tempemp->st = stud;
        if(head!=NULL){
            Node * temp;
            temp = head;
            while((*temp).next!=NULL){
                temp = (*temp).next;
            }
            (*temp).next = tempemp;
            tempemp->prev = temp;
        }else{
            tempemp->next = head;
            head = tempemp;
            tempemp->prev = NULL;

        }
    }
    void remove (int age){
        if (head == NULL){
            cout<<"No data is in the list..."<<endl;
            return;
        }
        bool pew = false;
        Node * temp;
        while (temp){
            if(temp->st.getage() == age){
                cout<<"xd";
                pew = true;
                break;
            }
            temp = temp->next;
        }

        if(pew == true){
            if(temp == head){
                head = head->next;
                delete head->prev;
                return;
            }
            if(temp->next == NULL){
                temp->prev->next = NULL;
                delete temp;
                return;
            }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
        }else{
            cout<<"No person of that age found..."<<endl;
        }


    }

    void Display(){
        Node * temp;
        temp = head;
        if(head==NULL){
            cout<<"No data"<<endl;
            return;
        }
        int i=1;
        while(temp!=NULL){
            cout<<i++<<"th Student"<<endl;
            (*temp).st.Display();
            cout<<endl;
            temp = (*temp).next;
        }
    }
    void UpdateGPA (double cgpa, int age){
        if (head == NULL){
            cout<<"No data is in the list..."<<endl;
            return;
        }
        bool pew = false;
        Node * temp;
        while (temp){
            if(temp->st.getage() == age){
                cout<<"xd";
                pew = true;
                break;
            }
            temp = temp->next;
        }
        if(pew)
            temp->st.setgpa(cgpa);
    }
    void clear(){
        Node * temp;
        Node * temp2;
        temp = head;
        temp2 = head;
        while(temp2){
            temp = temp2;
            temp2=temp2->next;
            delete temp;
        }
    }
    bool isEmpty (){
        return (head==NULL);
    }

    /*void sort (){
        if(head == NULL)
            return;
        LL temp;
        Node * curr = head;
        while(curr->next){
            curr = curr -> next;
        }

    }*/

};

int main(){
    Student s1;
    Student s2("Lalaleo", "65",14,3);
    Student s3("Meow", "64",15,4);
    Student s4("Pew", "63",16,5);
    Linked_List L1;
    L1.insert(s1);
    L1.insert(s2);
    L1.insert(s3);
    L1.insert(s4);
    L1.Display();


    //L1.remove(4);
    cout<<endl<<endl;
    L1.Display();

return 0;
}
