#include <iostream>
#include <string>
#include "order.h"
using namespace std;

class Costumer{
    string branch;
    int bill;
    string c_name;
    Order o;
    public:
        Costumer(string="Mirza");
        ~Costumer();
        void setcname(string);
        string getcname();
        void setbill(int x);
        void setbranch(string p);
        int getbill();
        string getbranch();


};