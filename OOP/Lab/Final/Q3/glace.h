#include <iostream>
#include <string>
#include "Branch.h"
using namespace std;


class Glace{
    Branch* b;
    int num_branches;

    public:
    Glace(int n);
    ~Glace();
    void addbranch();
    void rembranch(int);
    void Display();



};