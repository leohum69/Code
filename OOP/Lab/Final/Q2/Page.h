#include <iostream>
#include "Line.h"
using namespace std;

class Page{
    private:
        int num_line;
        Line* l;
    public:
        Page();
        Page(int nl,int nc);
        Page(Page &obj);
        ~Page();

};