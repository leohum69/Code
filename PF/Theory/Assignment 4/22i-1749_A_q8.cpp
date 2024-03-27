/*
Name: Mirza Humayun Masood
Roll No : i22-1749
Class : BS-CY(S)
*/
#include <iostream>
using namespace std;

bool isAlpha(char);     //prototypes
bool isDigit(char);
bool isAlnum(char);
bool isXdigit(char);
bool isLower(char);
bool isUpper(char);
bool isSpace(char);



int main(){     //main
    char a;
    cout<<"Enter Character: ";      //getting character
    cin.get(a);
    cout<<endl;
    cout<<boolalpha<<"isAlpha \t"<<isAlpha(a)<<endl<<endl;  //testing every function
    cout<<boolalpha<<"isDigit \t"<<isDigit(a)<<endl<<endl;
    cout<<boolalpha<<"isAlnum \t"<<isAlnum(a)<<endl<<endl;
    cout<<boolalpha<<"isXdigit \t"<<isXdigit(a)<<endl<<endl;
    cout<<boolalpha<<"isLower \t"<<isLower(a)<<endl<<endl;
    cout<<boolalpha<<"isUpper \t"<<isUpper(a)<<endl<<endl;
    cout<<boolalpha<<"isSpace \t"<<isSpace(a)<<endl<<endl;


return 0;
}

bool isAlpha(char a){       //Checking Alphabets
    if(static_cast<int>(a)>=65 && static_cast<int>(a)<=90){
        return true;
    }else if(static_cast<int>(a)>=97 && static_cast<int>(a)<=122){
        return true;
    }else{
        return false;
    }
}
bool isDigit(char a){   //Checking Numbers
    if(static_cast<int>(a)>=48 && static_cast<int>(a)<=57){
        return true;
    }else {
        return false;
    }
}
bool isAlnum(char a){      //Checking numbers and alpahabets
    if(static_cast<int>(a)>= 65 && static_cast<int>(a)<=90){
        return true;
    }else if(static_cast<int>(a)>=97 && static_cast<int>(a)<=122){
        return true;
    }else if(static_cast<int>(a)>=48 && static_cast<int>(a)<=57){
        return true;
    }else{
        return false;
    }
}
bool isXdigit(char a){      //Checking Xdigits
    if(static_cast<int>(a)>=48 && static_cast<int>(a)<=57){
        return true;
    }else if(static_cast<int>(a)>=65 && static_cast<int>(a)<=70){
        return true;
    }else if(static_cast<int>(a)>=97 && static_cast<int>(a)<=102){
        return true;
    }else{
        return false;
    }
}
bool isLower(char a){       //Checking lowercase alphabets
    if(static_cast<int>(a)>=97 && static_cast<int>(a)<=122){
        return true;
    }else {
        return false;
    }
}
bool isUpper(char a){       //Checking uppercase alphabets
    if(static_cast<int>(a)>=65 && static_cast<int>(a)<=90){
        return true;
    }else{
        return false;
    }
}
bool isSpace(char a){   //Checking space
    if(static_cast<int>(a) == 32 || static_cast<int>(a)==9){
        return true;
    }else{
        return false;
    }
}
