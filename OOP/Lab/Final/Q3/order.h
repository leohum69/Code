#include <iostream>
#include <string>
using namespace std;

class Order{
    bool status;
    public:
        Order(bool stat=false);
        ~Order();
        bool getstat();
        void setstat(bool x);

};