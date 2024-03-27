#include <iostream>
using namespace std;

class Line{
    private:
        int num_char;
        char* c;

    public:
        Line();
        Line(int nc);
        Line(Line &obj);
        ~Line();
        char* getchar();
        int getnumchar();
        void setnumchar(int);
        void setchar(char*);
        void operator+=(Line& obj);

};