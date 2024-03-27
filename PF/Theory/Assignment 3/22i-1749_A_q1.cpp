/*
Mirza Humayun Masood
I22-1749
BS-CY(A)
*/
#include<iostream>

using namespace std;

int main(){

    float n=0;
    float sum=0;
    float mean=0;
    float eight=0;

    for(int i=1;i<=5;i++){
        cout<<"Enter score of subject "<<i<<" : ";      //enter scores
        cin>>n;
        while(n<0 || n>100){
            cout<<"Invalid score – score can be in the range 0-100"<<endl;  //check for range
            cout<<"Enter score of subject "<<i<<" : ";
            cin>>n;
        }
        if(n>=80){
            eight++;        //80+ scores
        }
        sum=sum+n;
    }
    cout<<endl<<endl;
    cout<<"Mean of scores:"<<sum/5<<endl;
    cout<<"There are "<<eight<<" scores which are more than 80."<<endl;






return 0;
}
