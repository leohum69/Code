/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include "String.h"
using namespace std;

String::String(){               //default constructer
    arr = NULL;
}
String::String(char *str){          //constructer
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    this->arr = new char[i];
    int j=0;
    while(j < i){
        arr[j] = str[j];
        j++;
    }
    arr[j]='\0';
}
String::String(const String &s){        //copy constructer
    if(arr != NULL){
        delete []arr;
    }
    int i=0;
    while(s.arr[i] != '\0'){
        i++;
    }
    this->arr = new char[i];
    int j=0;
    while(s.arr[j] != '\0'){
        this->arr[j] = s.arr[j];
        j++;
    }
    this->arr[j]='\0';

}
String::String(int x){          //constructer with predeifnde size
    this->arr = new char[x];
}
char String::getAt(int i){          //getter of a char
    int j=0;
    while(this->arr[j] != '\0'){
        j++;
    }
    if(i > -1 && i < j-1){
        return this->arr[i];
    }else
        cout<<"error"<<endl;
}
void String::setAt(int i, char c){          //setter of a char
    int j=0;
    while(this->arr[j] != '\0'){
        j++;
    }
    if(i > -1 && i < j-1){
        this->arr[i] = c;
    }else
        cout <<"error"<<endl;
}
String String::substr(int pos, int len){            //substr of len from pos
    int i=0;
    String s1;
    while(this->arr[i] != '\0'){
        i++;
    }
    if((pos + len) <= i){
        s1.arr = new char[len + 1];
        int j = pos;
        int p = 0;
        while(j != pos+len){
            s1.arr[p] = this->arr[j];
            p++;
            j++;
        }
        s1.arr[p] = '\0';
    }else{
        cout<<"Error"<<endl;
    }
    return s1;
}
String String::substr(int pos){         //substr from pos to end
    int i=0;
    String s1;
    while(this->arr[i] != '\0'){
        i++;
    }
    if(pos < i){
        s1.arr = new char[i-pos];
        int j=pos;
        int p=0;
        while(this->arr[j] != '\0'){
            s1.arr[p] = this->arr[j];
            p++;
            j++;
        }
        s1.arr[p] = '\0';
    }else{
        cout<<"Error"<<endl;
        return s1;
    }
}
void String::append(char a){            //appending a character
    int i=0;
    while(this->arr[i] != '\0'){
        i++;
    }
    char *temp = new char[i];
    int j=0;
    while(this->arr[j] != '\0'){
        temp[j] = this->arr[j];
        j++;
    }
    temp[j]='\0';
    delete[]this->arr;
    this->arr = new char[i+1];
    j=0;
    while(temp[j] != '\0'){
        this->arr[j] = temp[j];
        j++;
    }
    this->arr[j] = a;
    this->arr[j+1] = '\0';
    delete []temp;

}
void String::append(String &str){           //appending a string
    int i=0;
    while(this->arr[i] != '\0'){
        i++;
    }
    int j=0;
    while(str.arr[j] != '\0'){
        j++;
    }
    //cout<<"xd"<<endl;
    char *temp = new char[i];
    int k=0;
    while(this->arr[k] != '\0'){
        temp[k] = this->arr[k];
        k++;
    }
    temp[k]='\0';
    delete[]this->arr;
    arr = new char[i+j-1];
    k=0;
    while(temp[k] != '\0'){
        this->arr[k] = temp[k];
        k++;
    }
    int p=0;
    while(str.arr[p] != '\0'){
        this->arr[k] = str.arr[p];
        p++;
        k++;
    }
    this->arr[k] = '\0';
}
void String::append(char *str){         //appending a cstring
    int i=0;
    while(this->arr[i] != '\0'){
        i++;
    }
    int j=0;
    while(str[j] != '\0'){
        j++;
    }
    char *temp = new char[i];
    int k=0;
    while(this->arr[k] != '\0'){
        temp[k] = this->arr[k];
        k++;
    }
    temp[k]='\0';
    delete[]this->arr;
    arr = new char[i+j-1];
    k=0;
    while(temp[k] != '\0'){
        this->arr[k] = temp[k];
        k++;
    }
    int p=0;
    while(str[p] != '\0'){
        this->arr[k] = str[p];
        p++;
        k++;
    }
    this->arr[k] = '\0';
}
int String::length(){           //length fun
    int i=0;
    while(this->arr[i] != '\0'){
        i++;
    }
    return i;
}
char * String::tocstring(){             //returnin cstring
    return this->arr;
}
void String::display(){         //display
    cout<<this->arr<<endl;
}
bool String::isEmpty(){             //is empty
    if(this->arr == NULL){
        return true;
    }else{
        return false;
    }
}
void String::copy(const String &s){         //copy stuff
    if(arr != NULL){
        delete []arr;
    }
    int i=0;
    while(s.arr[i] != '\0'){
        i++;
    }
    this->arr = new char[i];
    int j=0;
    while(s.arr[j] != '\0'){
        this->arr[j] = s.arr[j];
        j++;
    }
    this->arr[j]='\0';
}
void String::copy(const char *s){       //copy stuff
    if(arr != NULL){
        delete []arr;
    }
    int i=0;
    while(s[i] != '\0'){
        i++;
    }
    this->arr = new char[i];
    int j=0;
    while(s[j] != '\0'){
        this->arr[j] = s[j];
        j++;
    }
    this->arr[j]='\0';
}
int String::find(char c){               //find character
    int i = 0;
    int p = -1;
    while(this->arr[i] != '\0'){
        if(this->arr[i] == c){
            p = i;
        }
        i++;
    }
    return p;
}
bool String::equal(String &str){            //equal check
    bool chk = false;
    int i=0;
    while(this->arr[i] != '\0'){
        i++;
    }
    int j=0;
    while(str.arr[j] != '\0'){
        j++;
    }
    if(i==j)
        chk = true;
    if(chk == true){
        int p=0;
        while(this->arr[p] != '\0'){
            if(this->arr[p] != str.arr[p])
                chk = chk && false;
            p++;
        }
    }
    return chk;
}
int String::stoi(){             //string to int (uses the cc function in header)
    int i=0;
    int p = -1;
    bool chk = true;
    while(this->arr[i] != '\0'){
        if(!(this->arr[i] == '0' || this->arr[i] == '1' || this->arr[i] == '2' || this->arr[i] == '3' || this->arr[i] == '4' || this->arr[i] == '5' || this->arr[i] == '6' || this->arr[i] == '7' || this->arr[i] == '8' || this->arr[i] == '9'))
            chk = chk && false;
        i++;
    }
    if(chk == true){
        p=0;
        int j=0;
        int power = i-1;
        while(this->arr[j] != '\0'){
            p = p + (cc(arr[j])*pow(10,power));
            power--;
            j++;
        }
    }
    return p;
}
String::~String(){          //destructor
    delete []this->arr;
}
