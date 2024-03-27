#include <iostream>
#include <string>
using namespace std;
class Employee{
public:
    int EMPID;
    string Emp_Name;
    string NIC;
    int salary;
    int Bonus;

    Employee(){
        EMPID = 0;
        Emp_Name = "Mushtaq";
        NIC = "34401-1234567-8";
        salary = 150;
        Bonus = 3;
    }
    Employee(int id,string name,string nic,int sal,int bon){
        EMPID = id;
        Emp_Name = name;
        NIC = nic;
        salary = sal;
        Bonus = bon;
    }
    void Display(){
        cout<<"Emplyee ID : "<<EMPID<<endl;
        cout<<"Emplyee Name : "<<Emp_Name<<endl;
        cout<<"Emplyee NIC : "<<NIC<<endl;
        cout<<"Emplyee Salary : "<<salary<<endl;
        cout<<"Emplyee Bonus : "<<Bonus<<endl;
    }
    void operator= (const Employee &emp){
        this->EMPID = emp.EMPID;
        this->Emp_Name = emp.Emp_Name;
        this->NIC = emp.NIC;
        this->salary = emp.salary;
        this->Bonus = emp.Bonus;
    }
};
class Node{
public:
    Employee emp;
    Node * next;

    Node(){
        next = NULL;
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
    void insert(const Employee &emplo){
        Node * tempemp = new Node;
        (*tempemp).emp = emplo;
        if(head!=NULL){
            Node * temp;
            temp = head;
            while((*temp).next!=NULL){
                temp = (*temp).next;
            }
            (*temp).next = tempemp;
        }else{
            head = tempemp;
        }
    }
    void remove (int id){
        bool chk = false;
        if (head == NULL){
            cout<<"No data is in the list..."<<endl;
            return;
        }
        Node * temp = head;
        Node * cridx;
        Node * Lcridx;
        while((*temp).next!=NULL){
            if(temp->emp.EMPID == id){
                cout<<"nn"<<endl;
                cridx = temp->next;
                chk = true;
                break;
            }
            Lcridx = temp;
            temp = temp->next;
        }
        if (chk == false){
            cout<<"No ID Found ..."<<endl;
            return;
        }
        if(Lcridx == NULL){
            Lcridx = cridx->next;
            delete cridx;
        }else if(cridx->next =NULL){
            Lcridx = NULL;
            delete cridx;
        }else{
            Lcridx = cridx->next;
            delete cridx;
        }

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
            cout<<i<<"th Employee"<<endl;
            (*temp).emp.Display();
            cout<<endl;
            temp = (*temp).next;
            i++;
        }
    }

};

int main(){
    Employee e1;
    Employee e2(15,"ALi","34455",68,1);
    Linked_List L1;
    L1.insert(e1);
    L1.insert(e2);
    L1.insert(e2);
    L1.Display();


    L1.remove(0);
    cout<<endl<<endl;
    L1.Display();

return 0;
}
