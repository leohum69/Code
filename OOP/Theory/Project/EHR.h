/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#ifndef EHR_H
#define EHR_H
#include <cstring>
#include <fstream>
class ehr{
    char docname[30];
    char consult[256];
    char prescripion[256];
    char recommendation[255];
    char dietry[256];
    char allergy[256];
    char regu_med[256];
    char chron[256];
    char appointment[4][256];
public:
    ehr(char[] = "\0",char[] = "\0",char[] = "\0",char[] = "\0",char[] = "\0",char[] = "\0",char[] = "\0",char[] = "\0",char** = NULL);
    virtual ~ehr();
    void display();
    void readehr(ehr* , char[], int);
    void writeehr(ehr* , char[], int);
    void operator=(ehr &is);
    void viewapoints();
    void enc(ehr &obj);
    void dnc(ehr &obj);

    //setters
    void setDocname(const char* name);
    void setConsult(const char* consultation);
    void setPrescription(const char* prescription);
    void setRecommendation(const char* recommendation);
    void setDietry(const char* dietry);
    void setAllergy(const char* allergy);
    void setRegu_med(const char* regu_med);
    void setChron(const char* chron);
    void setAppointment(int index, const char* appointment);
    //getters
    const char* getname() const;
    const char* getConsult() const;
    const char* getPrescription() const;
    const char* getRecommendation() const;
    const char* getDietry() const;
    const char* getAllergy() const;
    const char* getRegu_med() const;
    const char* getChron() const;
    const char* getAppointment(int index) const;
    //updaters
    void updateDocName(const char* str);
    void updateConsult(const char* str);
    void updatePrescription(const char* str);
    void updateRecommendation(const char* str);
    void updateDietry(const char* str);
    void updateAllergy(const char* str);
    void updateReguMed(const char* str);
    void updateChron(const char* str);






};
#endif // EHR_H
