#include "Line.h"
    Line::Line(){
        this->num_char = 5;
        this->c = new char[this->num_char];
    }
    Line::Line(int nc){
        this->num_char = nc;
        this->c = new char[this->num_char];
    }
    Line::Line(Line &obj){
        this->num_char = obj.num_char;
        this->c = new char[this->num_char];       
        for(int i = 0; i< this->num_char ; i++){
            this->c[i] = obj.c[i];
        }
    }
    Line::~Line(){
        delete []c;
    }
    char* Line::getchar(){
        return c;
    }
    int Line::getnumchar(){
        return num_char;
    }
    void Line::setnumchar(int x){
        this->num_char = x;
    }
    void Line::setchar(char* xx){
        delete[]c;
        c = new char[this->num_char];
        for(int i=0; i < this->num_char ; i++){
            c[i] = xx[i];
        }
    }
    void Line::operator+=(Line& obj){
        for(int i=0 ; i< )
    }