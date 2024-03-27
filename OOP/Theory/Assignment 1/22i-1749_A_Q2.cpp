/*
Name: Mirza Humayun Masood
Roll No: 22i-1749
Assignment No 1.
*/
#include<iostream>
using namespace std;

int toupper(char* ch);              //Fuction Prototypes
int tolower(char* ch);
int isspace (const char* ch);
char* strncpy(char* dest, const char* src, size_t n);
int strcmp(const char* cstr1, const char* cstr2);
char* strncat(char* dest, const char* src, size_t n);
char* strstr(char* cstr1, char* cstr2);
char* strtok(char* cstr, const char* delim);
int main(){
    char *ch=new char[100];     //declaration of ch pointers
    char *ch1=new char[100];
    char *chdest=new char[100];
    cout<<"Enter First String(lowercase): ";
    cin.get(ch,100);
    toupper(ch);
    cout<<"toupper: "<<ch<<endl;
    delete []ch;
    ch=new char[100];
    cout<<"Enter Second String(uppercase): ";
    cin.ignore();
    cin.get(ch,100);
    tolower(ch);
    cout<<"tolower: "<<ch<<endl;
    delete []ch;
    ch=new char[100];
    cout<<"Enter Third String(with space): ";
    cin.ignore();
    cin.get(ch,100);
    cout<<isspace(ch)<<endl;
    delete []ch;
    cout<<"Enter Fourth String(You want to copy): ";
    cin.ignore();
    cin.get(ch1,100);
    cout<< strncpy(chdest,ch1,10)<<endl;
    delete []ch1;
    delete []chdest;
    ch1=new char[100];
    chdest=new char[100];
    cout<<"Enter 1st String(You want to comp): ";
    cin.ignore();
    cin.get(ch1,100);
    cout<<"Enter 2nd String(You want to comp): ";
    cin.ignore();
    cin.get(chdest,100);
    cout<<"Compare:"<<strcmp(ch1,chdest)<<endl;
    delete []ch1;
    delete []chdest;
    ch1=new char[100];
    chdest=new char[100];
    cout<<"Enter 1st String(You want to concate): ";
    cin.ignore();
    cin.get(ch1,100);
    cout<<"Enter 2nd String(You want to concate): ";
    cin.ignore();
    cin.get(chdest,100);
    cout<<strncat(ch1,chdest,5)<<endl;
    delete []ch1;
    delete []chdest;
    ch1=new char[100];
    chdest=new char[100];
    cout<<"Enter 1st String(You want to occurence): ";
    cin.ignore();
    cin.get(ch1,100);
    cout<<"Enter 2nd String(You want to a): ";
    cin.ignore();
    cin.get(chdest,100);
    cout<<strstr(ch1,chdest);
    delete []ch1;

    char *charac=new char;
    ch1=new char[100];
    cout<<"Enter the string to toeknize: ";
    cin.ignore();
    cin.get(ch1,100);
    cout<<"Enter Delimiter(character): ";
    cin.ignore();
    cin.get(*charac);

    char *a1=strtok(ch1,charac);
    cout<<a1<<endl;





return 0;
}
int toupper(char* ch){                                //Change to Capital
    int i=0;
    while(*(ch+i) != '\0'){
        if(*(ch+i) >='a' && *(ch+i) <='z')
            *(ch+i) = *(ch+i) - 32;
        i++;
    }
    return 0;
}
int tolower(char* ch){                                 //Change to Lower
    int i=0;
    while(*(ch+i) != '\0'){
        if(*(ch+i) >='A' && *(ch+i) <='Z')
            *(ch+i) = *(ch+i) + 32;
        i++;
    }
    return 0;
}
int isspace (const char* ch){                          //check if space
    int i=0;
    while(*(ch+i) != '\0'){
        if(*(ch+i) == ' ' || *(ch+i) == '\r' || *(ch+i) == '\n' || *(ch+i) == '\t'|| *(ch+i) == '\f' || *(ch+i) == '\v')
            return 1;
        i++;
    }
    return 0;
}
char* strncpy(char* dest, const char* src, size_t n){           //string copy
    int i=0;
    while(i<n){
        *(dest+i) = *(src+i);
        i++;
    }

    *(dest+i) = '\0';
    return dest;
}
int strcmp(const char* cstr1, const char* cstr2){               //string compare
    bool chk=true;
    int i=0;
    while(*(cstr1+i) != '\0'){
        if(*(cstr1+i) != *(cstr2+i)){
            chk=false;
        }
        i++;
    }
    int j=0;
    while(*(cstr2+j)!= '\0'){
        j++;
    }
    if(chk==true && i==j){
        return 0;
    }
    if(i<j){
        return -1;
    }else if(j<i){
        return 1;
    }else if(i==j && chk==false){
        return 2;
    }
}
char* strncat(char* dest, const char* src, size_t n){       //string contatinate
    int i=0;
    while(*(dest+i)!= '\0'){
        i++;
    }
    int j=0;
    while( j<n && *(src+j)!='\0'){
        *(dest+i+j)= *(src+j);
        j++;
    }
    *(dest+i+j)='\0';
    return dest;
}
char* strstr(char* cstr1, char* cstr2){             //first occerance pointer
    while(*cstr1!= '\0'){
        if(strcmp(cstr1,cstr2)== 0){
            return cstr1;
        }
        cstr1++;
    }
    return 0;

}
char* strtok(char* cstr, const char* delim){
    int i=0;
    char *ch=new char[100];
    while(*(cstr+i)!='\0'){
        if(*(cstr+i)== *delim){
            break;
        }
        *(ch+i) = *(cstr+i);
        i++;
    }
    *(ch+i)='\0';

    return ch;
}

