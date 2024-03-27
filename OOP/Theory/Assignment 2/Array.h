/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>
using namespace std;

class Array{            //class
    int *arr;
    int size;
public:             //mem funs
    Array();
    Array(int size);
    Array(int *arr, int size);
    Array(const Array &);
    int getAt(int i);
    void setAt(int i, int val);
    Array subArr(int pos, int siz);
    Array subArr(int pos);
    int * subArrPointer(int pos, int siz);
    int * subArrPointer(int pos);
    void push_back (int a);
    int pop_back();
    int insert(int idx, int val);
    int erase(int idx);
    //void size();
    int length();
    void clear();
    int value(int idx);
    void assign(int idx, int val);
    void copy(const Array& Arr);
    void copy(const int * arr, int siz);
    void display ();
    bool isEmpty();
    Array find(int);
    bool equal(const Array&);
    int sort();
    void reverse();
    ~Array();

};
#endif /* ARRAY_H_ */
