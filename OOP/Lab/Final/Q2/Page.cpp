#include "Page.h"
    Page::Page(){
        this->num_line = 5;
        this->l = new Line[num_line];
    }
    Page::Page(int nl,int nc){
        this->num_line = nl;
        this->l = new Line[num_line];
    }
    Page::Page(Page &obj){
        this->num_line = obj.num_line;
        this->l = new Line[num_line];
        for(int i=0 ; i< this->num_line ; i++){
            l[i].setnumchar(obj.l[i].getnumchar());
            l[i].setchar(obj.l[i].getchar());
        }
    }
    Page::~Page(){
        delete []l;
    }