/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#ifndef STRING_H_
#define STRING_H_

#include <iostream>
#include <cmath>
using namespace std;

class String{           //class
    char *arr;
public:             //functions
    String();
    String(char *str);
    String(const String &);
    String(int x);
    char getAt(int i);
    void setAt(int i, char c);
    String substr(int pos, int len);
    String substr(int pos);
    void append(char a);
    void append(String &str);
    void append(char *str);
    int length();
    char * tocstring();
    void display();
    bool isEmpty();
    void copy(const String&);
    void copy(const char *);
    int find(char);
    bool equal(String&);
    int stoi();
    ~String();





};


#endif /* STRING_H_ */
int cc(char l){             //this is for converting char to int :3
	switch(l){
		case '1':
			return 1;
		break;
		case '2':
			return 2;
		break;
		case '3':
			return 3;
		break;
		case '4':
			return 4;
		break;
		case '5':
			return 5;
		break;
		case '6':
			return 6;
		break;
		case '7':
			return 7;
		break;
		case '8':
			return 8;
		break;
		case '9':
			return 9;
		break;
		case '0':
			return 0;
		break;
		default:
			return -1;
			break;
	}
}
