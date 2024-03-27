#include <iostream>
#include <string>
#include "Flavour.h"
#include "Employee.h"
#include "Costumer.h"

using namespace std;

class Branch{
    Flavour f[4];
    string loc;
    int num_of_empl;
    int num_of_costum;
    Employee e[10];
    Costumer c[10];
    public:
    Branch(int ne,int nc,int smallp,int medp,int larp,string flaname,string l);
    ~Branch();
    string getloc();
    Flavour* getflav();
};