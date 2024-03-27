/*
Name : Mirza Humayun Masood ,, Saif ur Rehman
Roll No : I221749 ,, I221697
Section : CY(A)
*/
#include <iostream>
#include <cstring>
//#include "getch.h"
 #include <conio.h>  //saifi set krli isko
#include"sha1.hpp"
#include <fstream>
using namespace std;
string current_date()
{
    std::time_t currentTime = std::time(nullptr);

    // Format the time as a string
    char buffer[80]; // Sufficient size for most date formats
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", std::localtime(&currentTime));

    std::string currentDate(buffer);

    

    return currentDate;
}
string current_time()
{
    std::time_t currentTime = std::time(nullptr);

    // Format the time as a string with AM/PM
    char buffer[80]; // Sufficient size for most time formats
    std::strftime(buffer, sizeof(buffer), "%I:%M:%S %p", std::localtime(&currentTime));

    std::string currentTimeStr(buffer);

    

    return currentTimeStr;
}
string hasher(string s){
    SHA1 hashers;
    string prev_hash;
    hashers.update(s);
    return hashers.final();
}
class admin{
public:
    string username;
    string password;
    string name;
    admin(string n = "Chaudari mushtaq ali haidrabadi",string user = "user", string pass= "pass"){
        name = n;
        username = user;
        password = pass;
    }
    string getuser(){
        return username;
    }
    string getpass(){
        return password;
    }
    string getname(){
        return name;
    }
    void Display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Username : "<<username<<endl;
        cout<<"Password : "<<password<<endl;
    }


};

class student{
private:
    int Roll;
    
    int attendance;
    int phy;
    int math;
    int data;
public:
    char name[100];
    char username[100];
    char password[100];
    student(int rol = 1, char * n = "Mushtaq", int attend = 69 ,int ph = 78, int mat = 87, int dat = 95, char * user = "user", char * pass = "pass"){
        Roll = rol;
        strcpy(name,n);
        attendance = attend;
        phy = ph;
        math = mat;
        data = dat;
        strcpy(username, user);
        strcpy(password, pass);
    }
    void setter(int rol = 1, char * n = "Mushtaq", int attend = 69 ,int ph = 78, int mat = 87, int dat = 95){
        Roll = rol;
        strcpy(name,n);
        attendance = attend;
        phy = ph;
        math = mat;
        data = dat;
    }
    int getid(){
        return Roll;
    }
    char * getuser(){
        return username;
    }
    char * getpassword(){
        return password;
    }
    int getattend(){
        return attendance;
    }
    void display(){
        cout << Roll << " \t " << name  << " \t\t" << attendance << " \t\t" << phy << " \t\t" << math << " \t\t" << data << endl;
    }
};
template<class User_type>
class hash_node{
    public:
    string prev_hash;
    string date;
    string time;
    string action;
    User_type user;
    hash_node<User_type> *next;
    hash_node<User_type> *prev;
    public:
    hash_node(string prev_hash,string date,string time,string action, User_type user)
    {
        this->prev_hash=prev_hash;
        this->date=date;
        this->time=time;
        this->action=action;
        this->user=user;
        this->next=NULL;
        this->prev=NULL;
    }
    void display_hash()
    {
        cout<<"\nTimestamp="<<this->time<<endl;
        cout<<"Action Date="<<this->date<<endl;
        cout<<"Action = " <<this->action<<endl;
        cout<<"exited from here"<<endl;
    }
    string concat()
    {
        return prev_hash+date+time+action+user.username;
    }
};
template <class User>
class hash_chain{
    public:
    hash_node<User> *head;
    hash_node<User> *tail;
    public:
    hash_chain()
    {
        head =NULL;
        tail=NULL;
    }
    void insert_end(string action, User &user)
    {
        
        SHA1 hasher;
        string prev_hash;
        if(tail!=NULL)
        {
            hasher.update(tail->concat());
            prev_hash=hasher.final();
        }
        string date=current_date();
        string time=current_time();
        hash_node<User> * temp=new hash_node<User>(prev_hash,date,time,action,user);
        if(head ==NULL && tail==NULL)
        {
            head = temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }
    void insert_end2(string prev_hash , string date , string time,string action ,User &user){
                
        SHA1 hasher;
        if(tail!=NULL)
        {
            hasher.update(tail->concat());
            prev_hash=hasher.final();
        }
        hash_node<User> * temp=new hash_node<User>(prev_hash,date,time,action,user);
        if(head ==NULL && tail==NULL)
        {
            head = temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }
    string hash()
    {
        return hasher(tail->concat());
    }
    void display_chain()
    {
        hash_node<User> *curr=head;
        if(head!=NULL)
        {
            hash_node<User> *curr=head;
            //hash_node<User> *curr2=curr->next;
            // curr->display_hash();
            //cout<<"\nDisplaying curr2"<<endl;
            //curr2->display_hash();
            cout<<endl<<endl;

            int i=0;
            while(curr!=NULL)
            {
                i++;
                //curr->display_hash();
                cout<<"here"<<endl;
                curr = curr->next;
             }
            cout<<"i:"<<i<<endl;
            curr = head;
            while(curr!=NULL)
            {
                //i++;
                curr->display_hash();
                cout<<"here"<<endl;
                curr = curr->next;
             }
        }
    }
    void search_user(string user_name)
    {
        hash_node<User> *curr=head;
        bool check =0;
        while(curr!=NULL)
            {
                if(curr->user.getuser()==user_name)
                {
                    curr->display_hash();
                    check=1;
                }
                curr = curr->next;
            }
        if(check==0)
        {
            cout<<"\nRecord Doesnot exist for specific input."<<endl;
        }
    }
    void search_date(string dat)
    {
        hash_node<User> *curr=head;
        bool check =0;
        while(curr!=NULL)
            {
                if(curr->date==dat)
                {
                    curr->display_hash();
                    check=1;
                }
                curr = curr->next;
            }
        if(check==0)
        {
            cout<<"\nRecord Doesnot exist for specific input."<<endl;
        }
    }
    void search_time(string tim)
    {
        hash_node<User> *curr=head;
        bool check =0;
        while(curr!=NULL)
            {
                if(curr->time==tim)
                {
                    curr->display_hash();
                    check=1;
                }
                curr = curr->next;
            }
        if(check==0)
        {
            cout<<"\nRecord Doesnot exist for specific input."<<endl;
        }
    }
    void writeHashChainToFile(const   string& filename) {
          ofstream file(filename, ios::binary);

        if (!file) {
            cout << "Error opening the file for writing." <<   endl;
            return;
        }

        // Traverse the chain and write each node to the file
        hash_node<User>* current = head;
        while (current != nullptr) {
            // Calculate the hash of the node
              string node_hash = hasher(current->concat());

            // Write the hash and node data to the file
            file.write(node_hash.c_str(), 20);
            file.write(reinterpret_cast<const char*>(current), sizeof(hash_node<User>));

            current = current->next;
        }

        file.close();
    }
    void readHashChainFromFile(const   string& filename) {
          ifstream file(filename,   ios::binary);

        if (!file) {
              cerr << "Error opening the file for reading." <<   endl;
            return;
        }

        // Read and process each node from the file
        while (true) {
              string node_hash(20, '\0');
            file.read(&node_hash[0], 20);

            if (file.eof()) {
                break; // End of file reached
            }

            hash_node<User> node("", "", "", "", User());
            file.read(reinterpret_cast<char*>(&node), sizeof(hash_node<User>));

            // Check the hash to ensure data integrity (compare with node_hash)
              string calculated_hash = hasher(node.concat());
            if (calculated_hash != node_hash) {
                  cerr << "Data corruption detected! Skipping this node." <<   endl;
                continue;
            }

            // Insert the node into the chain
           this->insert_end2(node.prev_hash, node.date, node.time, node.action, node.user);
        }

        file.close();
    }

};

void addData()
{

    system("clear");

        cout << "\t|Enter Data|" << endl
             << endl;

    int rollNumber;char  name[100]; int attendance, physics, data, maths;
    char username[100]; char password[100];
    string moreData;

    cout << "\nEnter Student's roll Number : ";
    cin >> rollNumber;
    cout << "\nEnter Studnet's Name : ";
    cin.ignore();
    cin.getline(name,100);
    cout << "\nEnter Attendance : ";
    cin >> attendance;
    cout << "\nEnter Physic's Marks : ";
    cin>>physics;

    cout << "\nEnter Maths Marks : ";
    cin >> maths;

    cout << "\nEnter Data Structures Marks : ";
    cin >> data;

    cout<<"Enter Username: ";
    cin.ignore();
    cin.getline(username,100);
    cout<<"Enter Password: ";
    cin.getline(password,100);

    student s1(rollNumber,name,attendance,physics,maths,data,username,password);

    ofstream ofile("students.dat",ios::binary | ios::app);
    ofile.write((char *)&s1, sizeof(s1));
    ofile.close();

}
void viewData()
{
    system("clear");
    ifstream fin;
    fin.open("students.dat", ios::in | ios::binary);
    if (!fin)
    {
        cout << "File Could Not Be Open";
        fin.close();
        return;
    }

    cout << "\n\t\t\t\t\t\t|Students Record| \n\n";

    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n"
         << endl
         << endl;
    cout << "Roll \t Name \t\t Attendance \t\t Physics \t\t Maths \t\t Data St" << endl
         << endl;
         student st;
        while (fin.read(reinterpret_cast<char *>(&st), sizeof(student)))
        {
            st.display();
        }


    cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl;
    fin.close();
    getch();
}

void deleteData()
{
    system("clear");

    fstream fp;

    int n;
    int flag = 0;
    cout << "\nDELETE STUDENT" << endl;
    cout << "\nEnter the Roll num :" << endl;
    cin >> n;
    fp.open("students.dat", ios::in | ios::out | ios::binary);
    fstream fp2;
    fp2.open("temp.dat", ios::out | ios::binary);
    fp.seekg(0);
    student s1;
    while (fp.read((char *)&s1, sizeof(student)))
    {
        if (s1.getid() != n)
        {
            flag = 1; // student found
        }
    }
    fp2.close();
    fp.close();
    remove("students.dat");
    rename("temp.dat", "students.dat"); // data after deletion moved to temp
    if (flag == 1)
    {
        cout << "\nRecord Deleted." << endl;
    }
    else
    {
        cout << "\nRecord not Found." << endl;
    }
}
void updateData()
{
    fstream fp;
    int n;
    int found = 0; // seach student of given data
    system("clear");
    cout << "\nMODIFY STUDENT RECORD" << endl;
    cout << "\nEnter the Roll no. ";
    cin >> n;
    fp.open("students.dat", ios::in | ios::out | ios::binary);
    int pos;
    student st;
    while (fp.read(reinterpret_cast<char *>(&st), sizeof(student)) && found == 0)
    {

        if (st.getid() == n)
        {
            st.display();
            cout << "\nEnter the new details of student";
                int rollNumber;char  name[100]; int attendance, physics, data, maths;
    string moreData;

    cout << "\nEnter Student's roll Number : ";
    cin >> rollNumber;
    cout << "\nEnter Studnet's Name : ";
    cin.ignore();
    cin.getline(name,100);
    cout << "\nEnter Attendance : ";
    cin >> attendance;
    cout << "\nEnter Physic's Marks : ";
    cin>>physics;

    cout << "\nEnter Maths Marks : ";
    cin >> maths;

    cout << "\nEnter Data Structures Marks : ";
    cin >> data;

    st.setter(rollNumber,name,attendance,physics,maths,data);

            fp.seekp(pos); // back from current position
            fp.write(reinterpret_cast<char *>(&st), sizeof(student));
            cout << "\nRecord Updated." << endl;
            found = 1;
        }
        pos = fp.tellg();
    }
    fp.close();
    if (found == 0)
    {
        cin.ignore();
        cout << "\nRecord Not Found." << endl;
    }
}
int checkpass(admin * a){
    string user;
    string pass;
    cout << "\n\n\t\tStudent Record Management System";
    cout << "\n\n\t\t Enter Username: ";
    cin.ignore();
    getline(cin,user);
    cout << "\n\n\t\t Enter Password: ";
    getline(cin,pass);
    bool x=0;
    int p=-1;
    for(int i = 0 ; i < 3 ; i++){
        if(user == a[i].getuser() && pass == a[i].getpass()){
            x = true;
            p=i;
        }
    }
    if(x == false)
        cout<<"No Admin found...(Wrong Credenitials)"<<endl;
    return p;
}

void smth(admin *a , int p,hash_chain<admin> &H){
    int i=1;
        while (i==1) {
        system("clear");
        cout << "\n\n\t\t\tStudent Record Management System";
        cout << "\n\n\t\t\t1. Add Student Record";
        cout << "\n\t\t\t2. View Student Records";
        cout << "\n\t\t\t3. Update Student Record";
        cout << "\n\t\t\t4. Delete Student Record";
        cout << "\n\t\t\t5. Exit";
        cout << "\n\n\t\t\tEnter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                H.insert_end("Adding student records",a[p]);
                addData();
                break;
            case 2:
                H.insert_end("Viewing student records",a[p]);
                viewData();
                break;
            case 3:
                H.insert_end("Updating student records",a[p]);
                updateData();
                break;
            case 4:
                H.insert_end("Deleting student records",a[p]);
                deleteData();
                break;
            case 5:
                cout << "\n\n\t\t\tQuitting The Program";
                for (int i = 0; i < 4; i++) {
                    cout << ".";

                }
                i=0;
                return;
            default:
                cout << "\n\n\t\t\tInvalid choice! Please try again.";
                break;
        }
    }

}
void complain(){
    string xd;
    cin.ignore();
    getline(cin,xd);

}
void degree(){
    cout<<"Your degree has been "<<rand()%100<<"%"<<"Completed."<<endl;
}
bool cp(char * a, char *b){
    int i=0;
    while (a[i]!='\0')
    {
        if(a[i]!=b[i])
            return false ;
        i++;
    }
    return true;
    
}
void stud(hash_chain<student> &H){
    ifstream fin;
    fin.open("students.dat",ios::binary);
    if (!fin)
    {
        cout << "File Could Not Be Open";
        fin.close();
        return;
    } 
    char user[100];
    char pass[100];
    cout << "\n\n\t\tStudent Record Management System";
    cout << "\n\n\t\t Enter Username: ";
    cin.ignore();
    cin.getline(user,100);
    cout << "\n\n\t\t Enter Password: ";
    cin.getline(pass,100);
    bool x = false;
    student x1;
    while (fin.read(reinterpret_cast<char *>(&x1), sizeof(student)))
    {
        if(cp(x1.getuser(),user)){
            x = true;
            break;
        }

    }
    int choice = -1;
    if(x){
        do
        {
        cout << "\n\n\t\t\t1. View Record";
        cout << "\n\t\t\t2. See, How much Degree is done.";
        cout << "\n\t\t\t3. View Attendance";
        cout << "\n\t\t\t4. Enter Complains or Suggestions";
        cout << "\n\t\t\t5. Exit";
        cout << "\n\n\t\t\tEnter your choice: ";
        cin>>choice;
        switch (choice) {
            case 1:
                H.insert_end("Viewing records",x1);
                x1.display();
                break;
            case 2:
                H.insert_end("Viewing Degree Progress",x1);
                degree();
                break;
            case 3:
                H.insert_end("Attendance check",x1);
                cout<<x1.getattend()<<"%"<<endl;;
                break;
            case 4:
                H.insert_end("added a complain",x1);
                complain();
                break;
            case 5:
                cout << "\n\n\t\t\tQuitting The Program";
                for (int i = 0; i < 4; i++) {
                    cout << ".";

                }
                x=0;
                break;
            default:
                cout << "\n\n\t\t\tInvalid choice! Please try again.";
                break;
            }
        
        } while (x);
        
    }

}
void viewadmin(admin * a){
    for(int i=0;i<3;i++){
        a[i].Display();
        cout<<endl;
    }
}
void hashing_portal(hash_chain<admin> &HA,hash_chain<student> &HS)
{
    int user;
    int choice = -1;
    bool x = true;
    do{
    system("clear");
    cout<<"\n\t\t1.Admin";
    cout<<"\n\t\t2.Student";
    cout<<"\n\t\tEnter Your choice:";
    cin>>user;
    while(user<=0 || user>2)
    {
        cout<<"\nInvalid Input!Type Again:";
        cin>>user;
    }
        cout << "\n\n\t\t\t1.Search With User.";
        cout << "\n\t\t\t2. Search with date.";
        cout << "\n\t\t\t3. Search with time.";
        cout << "\n\t\t\t4. Exit.";
        cout << "\n\n\t\t\tEnter your choice: ";
        cin>>choice;
        while(choice > 4 || choice < 1){
            cout<<"Invalid Input"<<endl;
            cout<<"Enter Again : ";
            cin>>choice;
        }
        string user_name;
        switch (choice)
        {
        case 1:
            system("clear");
            cout<<"\nEnter Username:";
            cin>>user_name;
            (user==1)?HA.search_user(user_name):HS.search_user(user_name);
            break;
        case 2:
            system("clear");
            cout<<"\nEnter Date:";
            cin>>user_name;
            (user==1)?HA.search_date(user_name):HS.search_date(user_name);
            break;
        case 3:
            system("clear");
            cout<<"\nEnter Time:";
            cin>>user_name;
            (user==1)?HA.search_time(user_name):HS.search_time(user_name);
            break;
        case 4:
            x = false;
            break;
        default:
            break;
        }
    }while(x);
}
void super(admin * a,hash_chain<admin> &HA,hash_chain<student> &HS){
    cout<<"\t\tWelcome to Super User...\n";
    int choice = -1;
    bool x = true;
    do{
        cout << "\n\n\t\t\t1. View Admins";
        cout << "\n\t\t\t2. hashing washing .exe (saif krli kuch)";
        cout << "\n\t\t\t3. Exit";
        cout << "\n\n\t\t\tEnter your choice: ";
        cin>>choice;
        while(choice > 3 || choice < 1){
            cout<<"Invalid Input"<<endl;
            cout<<"Enter Again : ";
            cin>>choice;
        }
        switch (choice)
        {
        case 1:
            viewadmin(a);
            break;
        case 2:
            hashing_portal(HA,HS);
            break;
        case 3:
            x = false;
            break;
        default:
            break;
        }
    }while(x);

}


int main()
{
    // string str1="saif Ur Rehman";
    // string str2;
    // SHA1 hasher;
    // hasher.update(str1);
    // str2=hasher.final();
    // cout<<"Hasher="<<str2<<endl;
    hash_chain<student> HS;
    hash_chain<admin> HA;
    // H.readHashChainFromFile(filename);
    // H.insert(H.hash(),"\0","\0","\0",T);
    //HA.readHashChainFromFile("admin.dat");
    //HS.readHashChainFromFile("stud.dat");
    // loadingBar();


    bool run = true;
    int choice = 69;
    admin xD1("Umer farooq","farooq","password");
    admin xD2("saifi","saif","possword");
    admin xD3("Chaudari mushtaq ali haidrabadi","user","pass");
    admin ass[3];
    ass[0]=xD1;
    ass[1]=xD2;
    ass[2]=xD3;
    int p;


    do{
    cout << "\n\n\t\t\tStudent Record Management System";
    cout << "\n\n\t\t 1-Admin\n";
    cout << "\n\t\t 2-Student\n";
    cout << "\n\t\t 3-Super User\n";
    cout << "\n\t\t 4-Exit\n";
    cin>>choice;
    while(choice > 4 || choice < 1){
        cout<<"Invalid Input"<<endl;
        cout<<"Enter Again : ";
        cin>>choice;
    }
    switch(choice){
        case 1:
            p = checkpass(ass);
            if(p>=0){
                smth(ass, p,HA);
            }
        break;
        case 2:
            stud(HS);
        break;
        case 3:
            super(ass,HA,HS);
        break;
        case 4:
            run = false;
            break;
    }
    }while(run);

    HS.display_chain();
    HA.display_chain();
    HA.writeHashChainToFile("admin.dat");
    HS.writeHashChainToFile("stud.dat");
    //cout<<"fule bani ??"<<endl;
    return 0;
}