#include <iostream>
#include <cmath>
using namespace std;

void reversed(int &x){
    int counter=0;
    int counter2=0;
    int a=x;
    int c=0;
    while(a>0){
        a=a/10;
        counter++;
    }
    a=x;
    x=0;
    while(a>0){
        c = a/ pow(10,(counter-1));  
        x = x + (c * pow(10,counter2));
        a = a - (c * pow(10,counter-1));
        counter--;
        counter2++;
    }

}

int main(){
    int x;
    cout<<"Enter Integer: ";
    cin>>x;

    reversed(x);

    cout<<"Reversed Integer: "<<x<<endl;

    return 0;
}
