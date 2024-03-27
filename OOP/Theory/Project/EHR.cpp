/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include"EHR.h"


ehr::ehr(char docn[],char cns[],char presc[],char recom[],char diet[],char aller[],char regm[],char chro[],char **pointer){
    strcpy(this->docname,docn);
    strcpy(this->consult,cns);
    strcpy(this->prescripion,presc);
    strcpy(this->recommendation,recom);
    strcpy(this->dietry,diet);
    strcpy(this->allergy,aller);
    strcpy(this->regu_med,regm);
    strcpy(this->chron,chro);
    if(pointer == NULL){
        for(int i=0;i<4;i++){
            strcpy(this->appointment[i],"\0");
        }
    }else{
        for(int i=0;i<4;i++){
            strcpy(this->appointment[i],pointer[i]);
        }
    }

}
ehr::~ehr(){
}
void ehr::display(){
    cout<<"Doctor Name : "<<this->docname<<endl;
    cout<<"Consultations : "<<this->consult<<endl;
    cout<<"Prescription : "<<this->prescripion<<endl;
    cout<<"Recommendation : "<<this->recommendation<<endl;
    cout<<"Diet : "<<this->dietry<<endl;
    cout<<"Allergies : "<<this->allergy<<endl;
    cout<<"Regular Medication : "<<this->regu_med<<endl;
    cout<<"Chronic Disease : "<<this->chron<<endl;
    cout<<"Previous Appointments Made with Doctor :"<<endl;
    for(int i=0;i <4;i++){
        cout<<i+1<<" - "<<this->appointment[i]<<endl;
    }
}
void ehr::operator=(ehr &is){
    strcpy(this->docname,is.docname);
    strcpy(this->consult,is.consult);
    strcpy(this->prescripion,is.prescripion);
    strcpy(this->recommendation,is.recommendation);
    strcpy(this->dietry,is.dietry);
    strcpy(this->allergy,is.allergy);
    strcpy(this->regu_med,is.regu_med);
    strcpy(this->chron,is.chron);
    for(int i=0;i <4;i++){
        strcpy(this->appointment[i],is.appointment[i]);
    }
}
void ehr::readehr(ehr *e,char path[],int sizes){
    ifstream ifile;
    ehr temp;
    ifile.open(path,ios::binary);
    for(int i=0;i<sizes;i++){
        ifile.read((char *)&temp, sizeof(temp));
        e[i] = temp;
    }
    ifile.close();
}
void ehr::writeehr(ehr *e,char path[],int sizes){
    ofstream ofile;
    ofile.open(path);
    for(int i=0;i<sizes;i++){
        ofile.write((char *)&e[i], sizeof(e[i]));
    }
    ofile.close();
}
//setters

void ehr::setDocname(const char* name) {
    strcpy(docname, name);
}

void ehr::setConsult(const char* consultation) {
    strcpy(consult, consultation);
}

void ehr::setPrescription(const char* prescription) {
    strcpy(prescripion, prescription);
}

void ehr::setRecommendation(const char* recommendation) {
    strcpy(this->recommendation, recommendation);
}

void ehr::setDietry(const char* dietry) {
    strcpy(this->dietry, dietry);
}

void ehr::setAllergy(const char* allergy) {
    strcpy(this->allergy, allergy);
}

void ehr::setRegu_med(const char* regu_med) {
    strcpy(this->regu_med, regu_med);
}

void ehr::setChron(const char* chron) {
    strcpy(this->chron, chron);
}

void ehr::setAppointment(int index, const char* appointment) {
    strcpy(this->appointment[index], appointment);
}
//getters
const char* ehr::getname() const{
    return this->docname;
}
const char* ehr::getConsult() const {
    return this->consult;
}

const char* ehr::getPrescription() const {
    return this->prescripion;
}

const char* ehr::getRecommendation() const {
    return this->recommendation;
}

const char* ehr::getDietry() const {
    return this->dietry;
}

const char* ehr::getAllergy() const {
    return this->allergy;
}

const char* ehr::getRegu_med() const {
    return this->regu_med;
}

const char* ehr::getChron() const {
    return this->chron;
}

const char* ehr::getAppointment(int index) const {
    return this->appointment[index];
}
void ehr::viewapoints(){
    for(int i=0;i <4;i++){
        cout<<i+1<<" - "<<this->appointment[i]<<endl;
    }
}
//updaters

    void ehr::updateDocName(const char* str) {
        strncat(docname, str, 30-strlen(docname)-1);
    }

    void ehr::updateConsult(const char* str) {
        strncat(consult, str, 256-strlen(consult)-1);
    }

    void ehr::updatePrescription(const char* str) {
        strncat(prescripion, str, 256-strlen(prescripion)-1);
    }

    void ehr::updateRecommendation(const char* str) {
        strncat(recommendation, str, 255-strlen(recommendation)-1);
    }

    void ehr::updateDietry(const char* str) {
        strncat(dietry, str, 256-strlen(dietry)-1);
    }

    void ehr::updateAllergy(const char* str) {
        strncat(allergy, str, 256-strlen(allergy)-1);
    }

    void ehr::updateReguMed(const char* str) {
        strncat(regu_med, str, 256-strlen(regu_med)-1);
    }

    void ehr::updateChron(const char* str) {
        strncat(chron, str, 256-strlen(chron)-1);
    }
    void ehr::enc(ehr &obj){
        int i=0;
        while(this->docname[i]!='\0'){
            this->docname[i] += 2;
            i++;
        }
        i=0;
        while(this->consult[i]!='\0'){
            this->consult[i] += 2;
            i++;
        }
        i=0;
        while(this->prescripion[i]!='\0'){
            this->prescripion[i] += 2;
            i++;
        }
        i=0;
        while(this->recommendation[i]!='\0'){
            this->recommendation[i] += 2;
            i++;
        }
        i=0;
        while(this->dietry[i]!='\0'){
            this->dietry[i] += 2;
            i++;
        }
        i=0;
        while(this->allergy[i]!='\0'){
            this->allergy[i] += 2;
            i++;
        }
        i=0;
        while(this->regu_med[i]!='\0'){
            this->regu_med[i] += 2;
            i++;
        }
        i=0;
        while(this->chron[i]!='\0'){
            this->chron[i] += 2;
            i++;
        }
        i=0;

    }
    //encryption shits

    void ehr::dnc(ehr &obj){
        int i=0;
        while(this->docname[i]!='\0'){
            this->docname[i] -= 2;
            i++;
        }
        i=0;
        while(this->consult[i]!='\0'){
            this->consult[i] -= 2;
            i++;
        }
        i=0;
        while(this->prescripion[i]!='\0'){
            this->prescripion[i] -= 2;
            i++;
        }
        i=0;
        while(this->recommendation[i]!='\0'){
            this->recommendation[i] -= 2;
            i++;
        }
        i=0;
        while(this->dietry[i]!='\0'){
            this->dietry[i] -= 2;
            i++;
        }
        i=0;
        while(this->allergy[i]!='\0'){
            this->allergy[i] -= 2;
            i++;
        }
        i=0;
        while(this->regu_med[i]!='\0'){
            this->regu_med[i] -= 2;
            i++;
        }
        i=0;
        while(this->chron[i]!='\0'){
            this->chron[i] -= 2;
            i++;
        }
        i=0;
    }
