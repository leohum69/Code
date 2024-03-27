#include "glace.h"
    Glace::Glace(int n){
        this->num_branches = n;
        b = new Branch[6]{(3,3,230,330,430,"Mango","Mutan"),(3,3,210,310,410,"Coconut","Karachi"),(3,3,240,340,440,"Titti Frutti","Lahore"),
        (3,3,250,350,450,"Pistachio","Peshawar"),(3,3,200,300,400,"Cherry","Quetta"),(3,3,220,320,420,"Coffe","Skardoo")};
    }
    Glace::~Glace(){
        delete []this->b;
    }
    void Glace::Display(){
        for(int i=0;i<num_branches;i++){
            cout<<b[i].getflav()[3].get_name()<<" in "<<b[i].getloc() <<'\t'<<"S: "<<b[i].getflav()[3].get_s()<<" , M: "<<b[i].getflav()[3].get_m()<<" , L : "<<b[i].getflav()[3].get_h()<<endl;
        }
    }