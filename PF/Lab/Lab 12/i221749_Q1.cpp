#include <iostream>
using namespace std;

void reduce(int &x,int &y){
    int p=2;
    int ee=0;
    if(x>y){
        ee=x;
        if(x%y==0){
            x=x/y;
            y=y/y;
        }
    }else if(y>x){
        ee=y;
        if(y%x==0){
            y=y/x;
            x=x/x;
        }
    }
    while(p<ee){
        while(1){
            if(x%p==0 && y%p==0){
                x=x/p;
                y=y/p;
            }else{
                break;
            }
        }
    p++;
    }
}

int main(){
    int x,y;
    cout<<"Enter Numerator :";
    cin>>x;
    cout<<"Enter Denominator :";
    cin>>y;

    reduce(x,y);

    cout<<"Simplest Numerator = "<<x<<endl;
    cout<<"Simplest Denominator = "<<y<<endl;



    return 0;
}
