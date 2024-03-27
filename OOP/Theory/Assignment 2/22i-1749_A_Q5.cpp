/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include<iostream>
using namespace std;
class adress{               //class
private:
    int HouseNumber;
    int Street;
    int ApartmentNumber;
    char *city;
    char *state;
    int PostalCode;
public:             //member funs
    adress(int,int,int,char *,char *, int);
    adress(int,int,char *,char *, int);
    void print();
    bool compareTo(adress,adress);
};
adress::adress(int hn,int s,int an,char * city,char * state, int pc){           //constructer with  appartment number
    this->HouseNumber = hn;
    this->Street = s;
    this->ApartmentNumber = an;
    this->city = city;
    this->state = state;
    this->PostalCode = pc;
}
adress::adress(int hn,int s,char * city,char * state, int pc){          //with out an
    this->HouseNumber = hn;
    this->Street = s;
    this->city = city;
    this->state = state;
    this->PostalCode = pc;
}
void adress::print(){               //print ?
    if(ApartmentNumber==0){
        cout<<"HouseNo. "<<HouseNumber<<", Street "<<HouseNumber<<endl;
    }else{
        cout<<"HouseNo. "<<HouseNumber<<", Street "<<HouseNumber<<",ApartmentNo. "<<ApartmentNumber<<endl;
    }
    cout<<city<<", "<<state<<", "<<PostalCode<<endl;
}
bool adress::compareTo(adress a1,adress a2){            //adress chk :3
    if(a1.PostalCode > a2.PostalCode){
        return true;
    }else{
        return false;
    }
}


int main(){
    adress A1(5,10,"Dil","Ka",150);
    adress A2(10,20,30,"Beh","Hi",149);
    A1.print();
    A2.print();
    cout<<boolalpha<<A1.compareTo(A1,A2);

return 0;
}
