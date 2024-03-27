#include <iostream>
#include <string>
using namespace std;

class Flavour{
    string name;
    int price_s;
    int price_m;
    int price_h;
    public:
        Flavour(string="Chocolate",int s=5,int m=10,int h=15);
        void set_na(string);
        void set_s(int);
        void set_m(int);
        void set_h(int);
        string get_name();
        int get_s();
        int get_m();
        int get_h();
        ~Flavour();

};