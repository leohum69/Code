/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include "patient.h"

patient::patient(int id,char na[],char pas[],char fp[],char ehp[],int ag,char gen,int numdoc,int doci[]){
    this->ID = id;
    strcpy(this->name,na);
    strcpy(this->pass,pas);
    strcpy(this->filepass,fp);
    strcpy(this->ehpass,ehp);
    this->age = ag;
    this->gender = gen;
    IOTS temp;
    if(fp[0]!='\0'){
        temp.readiot(fp);
    }
    this->docarr = NULL;
    this->wear = temp;
    this->docnum = numdoc;
    if(doci != NULL){
        for(int i=0;i<docnum;i++){
            this->docidx[i] = doci[i];
        }
        for(int i = docnum; i<5;i++){
            this->docidx[i] = -1;
        }
    }else{
        for(int i=0;i < 5;i++){
            this->docidx[i] = -1;
        }
    }
    sorting(docidx);
    ehh = new ehr[numdoc];
    if(ehpass[0]!='\0'){
        ehh->readehr(ehh,ehpass,numdoc);
    }
    for(int  i=0 ; i < 5; i++){
        this->reqsen[i]=0;
    }
}
patient::~patient(){
    delete []docarr;
}
void patient::prints(){
    cout<<"Name "<<this->name<<endl;
    cout<<"pass "<<this->pass<<endl;
    cout<<"filepass "<<this->filepass<<endl;
    cout<<"ehr file pass "<<this->ehpass<<endl;
    cout<<"age "<<this->age<<endl;
    cout<<"gender "<<this->gender<<endl;
    cout<<"docnum "<<this->docnum<<endl;
    cout<<"iots "<<endl<<endl;
    this->wear.print();
    cout<<endl;
    for(int i = 0; i<5;i++){
        cout<<this->docidx[i] <<" ";
    }
    cout<<endl;cout<<endl;
    for(int i = 0; i<docnum;i++){
        (*docarr[i]).display();
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<this->docnum;i++){
        ehh[i].display();
    }

}
void patient::setdocs(doctor *point){
    if(docarr != NULL)
        delete []this->docarr;
    this->docarr = new doctor*[docnum];
    for(int i=0; i<this->docnum;i++){
        this->docarr[i] = &point[this->docidx[i]];
    }
}
void patient::adddoc(int idx,doctor *point){
    this->docnum++;
    this->docidx[this->docnum-1] = idx;
    sorting(this->docidx);
    (*this).setdocs(point);
}
void patient::remdoc(int idx,doctor *point){
    this->docidx[idx-1] = -1;
    this->docnum--;
    sorting(this->docidx);
    (*this).setdocs(point);
}
IOTS& patient::getiot(){
    return this->wear;
}
char* patient::getname(){
    return this->name;
}
char* patient::getpass(){
    return this->pass;
}
int patient::getid(){
    return this->ID;
}
void patient::setapt(){
    int choice;
    char app[50];
    cout<<"Your Doctors are: "<<endl;
    for(int i=1 ; i <= this->docnum ; i++){
        cout<<i<<" - "<<(*docarr[i-1]).getname()<<", Doctor of "<<(*docarr[i-1]).getspec()<<endl;
    }
    cout<<"Enter Choice: ";
    cin>>choice;
    while(choice > docnum || choice < 1){
        cout<<"Invalid Input"<<endl;
        cout<<"Enter Again : ";
        cin>>choice;
    }
    if( (*docarr[choice-1]).senreqdoc()[this->ID] == 1){
        cout<<"Appointment Request is Already Made, wait For Response..."<<endl<<endl;
    }else{
        cout<<"Enter Date for Appointment : ";
        cin.ignore();
        cin.get(app,50);
        (*docarr[choice-1]).senreqdoc()[this->ID] = 1;
        cout<<"Request Sent :D"<<endl<<endl;
    }
}
void patient::addnewdocplz(doctor *point){
    int choice;
    bool chk = false;
    int *arr;
    //int var=0;
    int p=1;
    bool loopchk = true;
    if(this->docnum == 5)
        chk = true;
    if(chk){
        cout<<"No Doctors Available...";
    }else{
        arr = new int[5 - this->docnum];
        for(int i=0;i<5;i++){
            loopchk = true;
            for(int j=0;j<this->docnum;j++){
                if(point[i].getid() == this->docidx[j]){
                    loopchk = false;
                }
            }
            if(loopchk == true){
                cout<<p<<" - "<< point[i].getname()<<", Doctor of "<<point[i].getspec()<<endl;
                arr[p-1] = point[i].getid();
                p++;
            }
        }
        cout<<"Enter Your Choice:";
        cin>>choice;
        while(choice<1 || choice > (p-1)){
            cout<<"Invalid Input"<<endl;
            cout<<"Enter Again : ";
            cin>>choice;
        }
        this->docnum++;
        this->docidx[docnum-1] = arr[choice-1];
        setdocs(point);
        cout<<"Doctor Entered Successfully :D"<<endl;
        delete []arr;
    }
}
void patient::viewehr(){
    int choice;
    int ix=-1;
    cout<<"Your Doctors are: "<<endl;
    for(int i=1 ; i <= this->docnum ; i++){
        cout<<i<<" - "<<(*docarr[i-1]).getname()<<", Doctor of "<<(*docarr[i-1]).getspec()<<endl;
    }
    cout<<"Enter Choice: ";
    cin>>choice;
    while(choice > docnum || choice < 1){
        cout<<"Invalid Input"<<endl;
        cout<<"Enter Again : ";
        cin>>choice;
    }
    for(int i=0 ; i < this->docnum ; i++){
        if(strcmp((*docarr[choice - 1]).getname(),this->ehh[i].getname())==0){
            ix = i;
        }
    }
    if(ehh[ix].getname()[0] != '\0')
        ehh[ix].display();
    else
        cout<<"You Dont Have any previous Appointment History with This Doctor, So You Dont have EHR for this one..."<<endl;
    cout<<endl;
}
void patient::chkreqs(doctor *point){ //masla
    int choice,choice2;
    cout<<"These Doctors want to Edit Your EHRs..."<<endl;
    int j=1;
    int *arr;
    for(int i=0 ; i < this->docnum ; i++){
        if(this->reqsen[i] == 1){
            cout<<j<<" - "<<point[i].getname()<<", Doctor of "<<point[i].getspec()<<endl;
            j++;
        }
    }
    if(j > 1)
        arr = new int[j-1];
    else{
        j++;
        arr = new int[j-1];
    }
    for(int i=0;i<j-1;i++){
        arr[i] = -1;
    }
    int k=0;
    for(int i=0 ; i < this->docnum ; i++){
        if(this->reqsen[i] == 1){
            arr[k] = point[i].getid();
            k++;
        }
    }
    cout<<endl;
    if(arr[0] != -1){
        cout<<"Select the doctor to Approve or Reject : ";
        cin>>choice;
        while(choice<1 || choice > (j-1)){
            cout<<"Invalid Input"<<endl;
            cout<<"Enter Again : ";
            cin>>choice;
        }
        cout<<"1 - Approve"<<endl;
        cout<<"2 - Reject"<<endl;
        cin>>choice2;
        while((choice2 < 1) || (choice2 > 2)){
            cout<<"Invalid Input"<<endl;
            cout<<"Enter Again : ";
            cin>>choice2;
        }
        if(choice2 == 1)
            this->reqsen[arr[choice-1]] = 2;
        else
            this->reqsen[arr[choice-1]] = 0;
    }else{
        cout<<"No Requests Found..."<<endl;
    }
}
int* patient::getrewaliarr(){
    return this->reqsen;
}
void patient::call(){
    int choice,choice2;
    char c;
    char note[200];
    cout<<"Your Doctors are: "<<endl;
    for(int i=1 ; i <= this->docnum ; i++){
        cout<<i<<" - "<<(*docarr[i-1]).getname()<<", Doctor of "<<(*docarr[i-1]).getspec()<<endl;
    }
    cout<<"Enter Choice: ";
    cin>>choice;
    while(choice > docnum || choice < 1){
        cout<<"Invalid Input"<<endl;
        cout<<"Enter Again : ";
        cin>>choice;
    }
    cout<<"Type of call : "<<endl;
    cout<<"1 - Video"<<endl;
    cout<<"2 - Audio"<<endl;
    cin>>choice2;
    while(choice2 > 2 || choice2 < 1){
        cout<<"Invalid Input"<<endl;
        cout<<"Enter Again : ";
        cin>>choice2;
    }
    if(choice2 == 1){
        cout<<"Making a Video Call to Doctor "<<(*docarr[choice-1]).getname()<<endl;
    }else{
        cout<<"Making a Audio Call to Doctor "<<(*docarr[choice-1]).getname()<<endl;
    }
    cout<<"Do You want to Make Notes ?"<<endl;
    cin>>c;
    if(c == 'Y' || c == 'y'){
        cout<<"Write Notes : ";
        cin.ignore();
        cin.get(note,200);
    }
    cout<<"Call Ended..."<<endl;
}
int patient::getage(){
    return this->age;
}
ehr* patient::getehr(){
    return this->ehh;
}
int patient::getnumberofdocs(){
    return this->docnum;
}
doctor** patient::getdocarr(){
    return this->docarr;
}
void patient::operator=(patient& other){
    this->ID = other.ID;
    strcpy(this->name,other.name);
    strcpy(this->pass,other.pass);
    strcpy(this->filepass,other.filepass);
    strcpy(this->ehpass,other.ehpass);
    this->age = other.age;
    this->gender = other.gender;

    IOTS temp;
    if(this->filepass[0]!='\0'){
        temp.readiot(filepass);
    }
    this->docarr = NULL;
    this->wear = temp;
    this->docnum = other.docnum;
    for(int i=0 ; i <5 ; i++){
        this->docidx[i] = other.docidx[i];
        this->reqsen[i] = other.reqsen[i];
    }
    this->ehh = new ehr[this->docnum];
    ehh->readehr(this->ehh,this->ehpass,this->docnum);
}
char* patient::getehrpath(){
    return this->ehpass;
}
void patient::encrypt(){
    for(int i=0;i<this->docnum;i++){
        ehh->enc(this->ehh[i]);
    }
}
void patient::decrypt(){
    for(int i=0;i<this->docnum;i++){
        ehh->dnc(this->ehh[i]);
    }
}
