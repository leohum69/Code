/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include <iostream>
#include "String.cpp"
using namespace std;
int main(){
	char *p=new char[10]{'a','b','c','d','e','f','g','h','i','\0'};
	String s1(p);
    String s2 = s1.substr(0,2);
    cout<<"s2 ";
    s2.display();
    String S3 = s1.substr(2);
    cout<<"s3 ";
    S3.display();
    s1.append('5');
    cout<<"s1 before append ";
    s1.display();
    s1.append(S3);
    cout<<"s1 after append ";
    s1.display();
    S3.append(p);
    cout<<"s3 after append ";
    S3.display();
    //cout<<s2.tocstring();
    S3.copy(p);
    cout<<"S3 p copy ";
    S3.display();
    S3.copy(s2);
    cout<<"S3 s2 wali copy ";
    S3.display();
    delete []p;
    p = new char[11]{'1','2','3','4','4','5','6','7','8','5','\0'};
    String S4(p);
    cout<<s1.find('a')<<" "<<s1.find('p')<<endl;
    cout<<boolalpha<<s1.equal(S3)<<" "<<S3.equal(s2)<<endl;
    cout<<S4.stoi();






return 0;
}

