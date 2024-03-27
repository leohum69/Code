/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include <iostream>
#include<iomanip>
using namespace std;
class Student{              //class
private:
    char * Rollnumber;
    char * name;
    int batch;
    int *Courses_Code;
    char **Courses_Name;
    char *Courses_Grades;
    float CGPA;
    char * Degree;
    char * DOB;
public:                         //member functions
    Student();
    Student(char *,char *,int ,int[],char *[],char[],float,char *,char *);
    void setValues();
    void setRollnumber(char *);
    void setname(char *);
    void setbatch(int);
    void setCoursecodes(int*);
    void setCourseNames(char **);
    void setCoursegrades(char *);
    void setCGPA(float);
    void setDegree(char *);
    void setDOB(char *);
    //getters
    char* getRollnumber() const;
    char* getname() const;
    int getbatch() const;
    int* getCoursecodes();
    char** getCourseNames();
    char* getCoursegrades();
    float getCGPA() const;
    char* getDegree() const;
    char* getDOB() const;
    void print() const;
    ~Student();

};

Student::Student(){             //default constructer
    Rollnumber = new char[100]{'I','2','2','-','1','7','4','9'};
    name = new char[100]{'H','u','m','a','y','u','n'};
    batch = 22;
    Courses_Code = new  int[5];
    for(int i=0;i<5;i++){
        Courses_Code[i]=i;
    }
    Courses_Name = new char*[5];
    Courses_Name[0] = new char[100]{'P','F'};
    Courses_Name[1] = new char[100]{'L','A'};
    Courses_Name[2] = new char[100]{'D','S'};
    Courses_Name[3] = new char[100]{'A','L'};
    Courses_Name[4] = new char[100]{'O','S'};
    Courses_Grades = new char[5];
    for(int i=0;i<5;i++){
        Courses_Grades[i] = 'A';
    }
    CGPA = 3.65;
    Degree = new char[100]{'B','S','(','C','Y',')'};
    DOB = new char[100]{'O','c','t','o','b','e','r',' ','0','7',',','2','0','0','3'};

}
Student::Student(char *a,char *n,int b,int *cc,char **cn,char *cg,float cgp,char *d,char *dob){     //parameterized
     this->Rollnumber = a;
     this->name = n;
     this->batch = b;
     this->Courses_Code = cc;
     this->Courses_Name = cn;
     this->Courses_Grades = cg;
     this->CGPA = cgp;
     this->Degree = d;
     this->DOB = dob;
}

void Student::setValues(){          //setvalues :3
    cout<<"Enter Roll Number: ";
    cin.get(Rollnumber,100);
    cin.ignore();
    cout<<"Enter Name: ";
    cin.get(name,100);
    cin.ignore();
    cout<<"Enter Batch: ";
    cin>>batch;
    while(batch <= 0){
        cout<<"Error, Enter Again: ";
        cin>>batch;
    }
    cout<<"Enter The course codes: "<<endl;
    for(int i=0;i<5;i++){
        cout<<"Enter the course code for "<<i+1<<"th course: ";
        cin>>Courses_Code[i];
        while(Courses_Code[i]<0){
            cout<<"Error, Enter Again: ";
            cin>>Courses_Code[i];
        }
    }
    cin.ignore();
    cout<<"Enter Course Names: "<<endl;
    for(int i=0;i<5;i++){
        cout<<"Enter the course Name for "<<i+1<<"th course: ";
        cin.get(Courses_Name[i],100);
        cin.ignore();
    }
    cout<<"Enter Course Grades: "<<endl;
    for(int i=0;i<5;i++){
        cout<<"Enter the course Grade for "<<i+1<<"th course: ";
        cin>>Courses_Grades[i];
    }
    cout<<"Enter CGPA : ";
    cin>>CGPA;
    while(CGPA < 0){
        cout<<"Error, Enter again: ";
        cin>>CGPA;
    }
    cin.ignore();
    cout<<"Enter Degree : " ;
    cin.get(Degree,100);
    cin.ignore();
    cout<<"Enter Date of Birth : ";
    cin.get(DOB,100);
    cin.ignore();

}               //setters
void Student::setRollnumber(char *a){
    this->Rollnumber = a;
}
void Student::setname(char *n){
    this->name = n;
}
void Student::setbatch(int b){
    this->batch = b;
}
void Student::setCoursecodes(int *a){
    this->Courses_Code = a;
}
void Student::setCourseNames(char **b){
    this->Courses_Name = b;
}
void Student::setCoursegrades(char *c){
    this->Courses_Grades = c;
}
void Student::setCGPA(float cc){
    this->CGPA = cc;
}
void Student::setDegree(char *d){
    this->Degree = d;
}
void Student::setDOB(char *dob){
    this->DOB = dob;
}
//getters
char* Student::getRollnumber() const{
    return Rollnumber;
}
char* Student::getname() const{
    return name;
}
int Student::getbatch() const{
    return batch;
}
int* Student::getCoursecodes(){
    return Courses_Code;
}
char** Student::getCourseNames(){
    return Courses_Name;
}
char* Student::getCoursegrades(){
    return Courses_Grades;
}
float Student::getCGPA() const{
    return CGPA;
}
char* Student::getDegree() const{
    return Degree;
}
char* Student::getDOB() const{
    return DOB;
}
void Student::print() const{        //print
    cout<<"Student Name:\t"<<name;
    cout<<"   \t\t\tRoll Number: "<<Rollnumber<<endl;
    cout<<"Date Of Birth:\t"<<DOB<<"     Uni Reg: "<<Rollnumber<<"\t\tDegree: "<<Degree<<endl;
    cout<<setw(40)<<"Fall 20"<<batch<<endl;
    cout<<endl;
    cout<<setw(20)<<"Code"<<setw(20)<<"Course Title"<<setw(20)<<"Grade"<<endl;
    for(int i=0;i<5;i++){
        cout<<"\t\t"<<Courses_Code[i]<<"\t    "<<Courses_Name[i]<<setw(26)<<Courses_Grades[i]<<endl;
    }
    cout<<setw(40)<<"CGPA : "<<CGPA<<endl;
}
Student::~Student(){            //destructer
    delete []Rollnumber;
    delete []name;
    delete []Courses_Code;
    for(int i=0;i<5;i++){
        delete []Courses_Name[i];
    }
    delete []Courses_Name;
    delete []Degree;
    delete []DOB;
}

void studentDemo(){     //class demo stuff...
    Student S1;
    //S1.setValues();
    S1.print();

    char * Rn;
    char * na;
    int bat;
    int *Cour_Code;
    char **Cour_Name;
    char *Cour_Grades;
    float CG;
    char * Deg;
    char * dob;

    Rn = new char[100];
    na = new char[100];
    Cour_Code = new int[5];
    Cour_Name = new char*[5];
    for(int i=0;i<5;i++){
        Cour_Name[i] = new char[100];
    }
    Cour_Grades = new char[5];
    Deg = new char[100];
    dob = new char[100];
    cout<<"Enter Roll Number: ";
    cin.get(Rn,100);
    cin.ignore();
    cout<<"Enter Name: ";
    cin.get(na,100);
    cin.ignore();
    cout<<"Enter Batch: ";
    cin>>bat;
    while(bat <= 0){
        cout<<"Error, Enter Again: ";
        cin>>bat;
    }
    cout<<"Enter The course codes: "<<endl;
    for(int i=0;i<5;i++){
        cout<<"Enter the course code for "<<i+1<<"th course: ";
        cin>>Cour_Code[i];
        while(Cour_Code[i]<0){
            cout<<"Error, Enter Again: ";
            cin>>Cour_Code[i];
        }
    }
    cin.ignore();
    cout<<"Enter Course Names: "<<endl;
    for(int i=0;i<5;i++){
        cout<<"Enter the course Name for "<<i+1<<"th course: ";
        cin.get(Cour_Name[i],100);
        cin.ignore();
    }
    cout<<"Enter Course Grades: "<<endl;
    for(int i=0;i<5;i++){
        cout<<"Enter the course Grade for "<<i+1<<"th course: ";
        cin>>Cour_Grades[i];
    }
    cout<<"Enter CGPA : ";
    cin>>CG;
    while(CG < 0){
        cout<<"Error, Enter again: ";
        cin>>CG;
    }
    cin.ignore();
    cout<<"Enter Degree : " ;
    cin.get(Deg,100);
    cin.ignore();
    cout<<"Enter Date of Birth : ";
    cin.get(dob,100);
    cin.ignore();
    Student S2(Rn,na,bat,Cour_Code,Cour_Name,Cour_Grades,CG,Deg,dob);
    S2.print();

}

int main(){             //main
    studentDemo();


return 0;
}
