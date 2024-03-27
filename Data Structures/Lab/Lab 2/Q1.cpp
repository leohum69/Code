#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n=5;
    int pew=1;
    for(int a=1;a<n;a++){
        for(int b=1;b<n;b++){
            for(int c=1 ; c<n ; c++){
                int d = cbrt((a*a*a) + (b*b*b) - (c*c*c));
                if((a*a*a) + (b*b*b) == (c*c*c) + (d*d*d)){
                    cout<<pew++<<"th time"<<endl;
                    cout<<"A : "<<a<<endl;
                    cout<<"B : "<<b<<endl;
                    cout<<"C : "<<c<<endl;
                    cout<<"D : "<<d<<endl;
                }
            }
        }
    }


}
