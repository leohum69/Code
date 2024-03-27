/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include <iostream>
#include "Integer.cpp"
using namespace std;

int main(){
    Integer i1(5);
    Integer i2(155);
    i1.print();
    i2.print();
    Integer I3;
    I3 = i1.divide(i2);
    I3.print();
    cout<<i2.compareTo(i1)<<endl;
    cout<<i2.bitCount()<<endl;
    cout<<Integer::toBinaryString(155)<<endl;
    cout<<Integer::toOctString(155)<<endl;
    cout<<Integer::toHexString(155)<<endl;
    cout<<Integer::toBinaryString(8)<<endl;
    cout<<Integer::numberOfTrailingZeros(8)<<endl;
    cout<<Integer::numberOfLeadingZeros(170);




return 0;
}
