#include <iostream>
#include <string>
using namespace std;

class Employee{
    string name;
    string role;
    public:
        Employee(string="Ali",string="Head");
        void Dowork();
        string get_na();
        string get_ro();
        ~Employee();

};