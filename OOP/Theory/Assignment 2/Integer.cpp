/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include "Integer.h"
using namespace std;

Integer::Integer(){         //defualt cnstrct
    this->x = 0;
}
Integer::Integer(int a){        //cnstrcter
    this->x = a;
}
Integer::Integer(string s){     //cnstrcter with string
    int i=0;
    int p = -1;
    bool chk = true;
    while(s[i] != '\0'){
        if(!(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'))
            chk = chk && false;
        i++;
    }
    if(chk == true){
        p=0;
        int j=0;
        int power = i-1;
        while(s[j] != '\0'){
            p = p + (cc(s[j])*pow(10,power));
            power--;
            j++;
        }
    }
    this->x = p;

}
void Integer::set(int i){           //setter
    this->x = i;
}
int Integer::get() const{           //getter
    return this->x;
}
int Integer::bitCount(){            //bit count
    int temp = this->x;
    int y = 0;
    int counter = 0;
    while(temp!=0){
        y = temp%2;
        if(y==1)
            counter++;
        temp=temp/2;
    }

    return counter;
}
int Integer::compareTo(Integer &a){         //integer compare
    if(this->x == a.x){
        return 1;
    }else{
        return 0;
    }
}
double Integer::doubleValue(){          //double converter
    double var = 0;
    var = static_cast<double>(this->x);
    return var;
}
float Integer::floatValue(){            //float converter
    float var = 0;
    var = static_cast<float>(this->x);
    return var;
}
Integer Integer::plus(const Integer &a){            //plus
    Integer temp;
    temp.x = this->x + a.x;
    return temp;
}
Integer Integer::minus(const Integer &a){       //minus
    Integer temp;
    temp.x = this->x - a.x;
    return temp;
}
Integer Integer::multiple(const Integer &a){            //multiply
    Integer temp;
    temp.x = this->x * a.x;
    return temp;
}
Integer Integer::divide(const Integer &a){          //divide
    Integer temp(-1);
    if(a.x != 0)
        temp.x = this->x / a.x;
    return temp;
}

