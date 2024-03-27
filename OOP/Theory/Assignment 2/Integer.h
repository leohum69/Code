/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#ifndef INTEGER_H_
#define INTEGER_H_

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Integer{      //class
    int x;

public:             //mem fun
    Integer();
    Integer(int);
    Integer(string);
    void set(int);
    int get() const;
    int bitCount();
    int compareTo(Integer&);
    double doubleValue();
    float floatValue();
    Integer plus(const Integer&);
    Integer minus(const Integer&);
    Integer multiple(const Integer&);
    Integer divide(const Integer&);
    static int numberOfLeadingZeros (int i){        //it tells the number of Leading zeros
        int p = i;
        string str = "";
        int c=0;
        while(p != 0){
            c=p%2;
            str.insert(0,ccreverse(c));
            p=p/2;
        }
        c = 0;
        while(str[c] != '\0'){
            c++;
        }
        c = 32 - c;
        return c;

    }
    static int numberOfTrailingZeros (int i){   //it tells the number of trailing zeros
        int p = i;
        string str = "";
        int c=0;
        while(p != 0){
            c=p%2;
            str.insert(0,ccreverse(c));
            p=p/2;
        }
        c = 0;
        while(str[c] != '\0'){
            c++;
        }
        int x = c-1;
        int l = 0;
        while(x >= 0){
            if(str[x] == '1'){
                l = x;
                break;
            }
            x--;
        }
        l = (c-1) - l;
        return l;
    }
    static string toBinaryString(int i){            //int to binary
        int p = i;
        string str = "";
        int c=0;
        while(p != 0){
            c=p%2;
            str.insert(0,ccreverse(c));
            p=p/2;
        }
        return str;
    }
    static string toHexString (int i){          //decimal to hex
        int p = i;
        string str = "";
        int c=0;
        while(p != 0){
            c=p%16;
            str.insert(0,ccreverse(c));
            p=p/16;
        }
        return str;
    }
    static string toOctString(int i){           //decimal to oct
        int p = i;
        string str = "";
        int c=0;
        while(p != 0){
            c=p%8;
            str.insert(0,ccreverse(c));
            p=p/8;
        }
        return str;
    }
    void print(){
        cout<<x<<endl;
    }
    static string ccreverse(int l){         //it converts iny to string (cuz i used insert fun of string)
    switch(l){
		case 1:
			return "1";
		break;
		case 2:
			return "2";
		break;
		case 3:
			return "3";
		break;
		case 4:
			return "4";
		break;
		case 5:
			return "5";
		break;
		case 6:
			return "6";
		break;
		case 7:
			return "7";
		break;
		case 8:
			return "8";
		break;
		case 9:
			return "9";
		break;
		case 0:
			return "0";
		break;
		case 10:
            return "A";
        break;
        case 11:
            return "B";
        break;
        case 12:
            return "C";
        break;
        case 13:
            return "D";
        break;
        case 14:
            return "E";
            break;
        case 15:
            return "F";
            break;
		default:
			return "-";
			break;
	}
}
};

#endif /* INTEGER_H_ */
int cc(char l){             //char to int
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
