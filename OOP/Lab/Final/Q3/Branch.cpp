include "Branch.h"

    Branch::Branch(int ne,int nc,int smallp,int medp,int larp,string flaname,string l){
        this->num_of_empl = ne;
        this->num_of_costum = nc;
        this->f[0].set_na("Chocolate");
        this->f[1].set_na("Vanilla");
        this->f[2].set_na("Strawberry");
        for(int i=0;i<3;i++){
            this->f[i].set_s(220);
            this->f[i].set_m(320);
            this->f[i].set_h(420);
        }
        this->loc = l;
        this->f[3].set_na(flaname);
        this->f[3].set_s(smallp);
        this->f[3].set_m(medp);
        this->f[3].set_h(larp);
    }
    Branch::~Branch(){

    }
    string Branch::getloc(){
        return this->loc;
    }
    Flavour* Branch::getflav(){
        return this->f;
    }