/*
Name : Mirza Humayun Masood.
Roll No : I22-1749
Class : BSCY(A)
*/
#include <iostream>

using namespace std;

int main(){

    int mon,day;
    cout<<"Enter Day: ";
    cin>>day;
    cout<<"Enter Month: ";
    cin>>mon;

        if((mon == 12 && day >= 16 && day <= 31) || (mon == 1 && day >=1 && day <= 31) || (mon == 2 && day >= 1 && day <= 28) || (mon == 3 && day >=1 && day <=15))
            {
                cout<<"Winter"<<endl;
            }else if((mon == 3 && day >= 16 && day <= 31) || (mon == 4 && day >=1 && day <= 30) || (mon == 5 && day >= 1 && day <= 31) || (mon == 6 && day >=1 && day <=15))
            {
                cout<<"Spring"<<endl;
            }else if((mon == 6 && day >= 16 && day <= 30) || (mon == 7 && day >=1 && day <= 31) || (mon == 8 && day >= 1 && day <= 31) || (mon == 9 && day >=1 && day <=15))
            {
                cout<<"Summer"<<endl;
            }else if((mon == 9 && day >= 16 && day <= 30) || (mon == 10 && day >=1 && day <= 31) || (mon == 11 && day >= 1 && day <= 30) || (mon == 12 && day >=1 && day <=15))
            {
                cout<<"Fall"<<endl;
            }



return 0;
}
