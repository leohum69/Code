/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include "Array.h"
using namespace std;

Array::Array(){             //defualt cnstrcter
    this->size = 0;
    this->arr = NULL;
}
Array::Array(int size){             //cnstrcter with size
    this->size = size;
    this->arr = new int[this->size];
}
Array::Array(int *arr, int size){           //cnstrctr with a pointer
    this->size = size;
    this->arr = new int[this->size];
    for(int i=0;i<this->size;i++){
        this->arr[i] = arr[i];
    }
}
Array::Array(const Array &a){           //copy cnstrctr
    this->size = a.size;
    if(this->arr != NULL)
        delete []this->arr;
    this->arr = new int[this->size];
    for(int i=0;i<this->size;i++){
        this->arr[i] = a.arr[i];
    }
}
int Array::getAt(int i){            //getter at index
    if(i > -1 && i < this->size){
        return this->arr[i];
    }else{
        cout<<"Error"<<endl;
        return -1;
    }
}
void Array::setAt(int i, int val){          //setter at index
    if(i > -1 && i < this->size){
        this->arr[i] = val;
    }else{
        cout<<"Error"<<endl;
    }
}
Array Array::subArr(int pos, int siz){          //substr of len from pos
    Array temp;
    if(pos >=0 && pos < this->size){
        if((pos+siz) <= this->size){
            temp.arr = new int[siz];
            int j=pos;
            for(int i=0;i<siz;i++){
                temp.arr[i] = this->arr[j];
                j++;
            }
            temp.size = siz;
        }else{
            cout<<"Error"<<endl;
        }
    }else{
        cout<<"Error"<<endl;
    }
    return temp;
}
Array Array::subArr(int pos){       //substr from pos to end
    Array temp;
    if(pos >=0 && pos < this->size){
        temp.arr = new int[this->size - pos];
        temp.size = this->size - pos;
        for(int i=0;i< temp.size ; i++){
            temp.arr[i] = this->arr[pos];
            pos++;
        }
    }else{
        cout<<"Error"<<endl;
    }
    return temp;
}
int * Array::subArrPointer(int pos, int siz){       //substrpointer of len from pos
    int *p=0;
    if(pos >=0 && pos < this->size){
        if((pos+siz) <= this->size){
            p = new int[siz];
            int j=pos;
            for(int i=0;i<siz;i++){
                p[i] = this->arr[j];
                j++;
            }
        }else{
            cout<<"Error"<<endl;
        }
    }else{
        cout<<"Error"<<endl;
    }
    return p;
}
int * Array::subArrPointer(int pos){            //substrpointer from pos to end
    int *p=0;
    if(pos >=0 && pos < this->size){
        p = new int[this->size - pos];
        for(int i=0;i< this->size - pos ; i++){
            p[i] = this->arr[pos];
            pos++;
        }
    }else{
        cout<<"Error"<<endl;
    }
    return p;
}
void Array::push_back (int a){          //push val at the last index
    int *p;
    p = new int[this->size];
    for(int i=0;i < this->size ; i++){
        p[i] = this->arr[i];
    }
    delete []this->arr;
    this->arr = new int[this->size + 1];
    for(int i=0;i < this->size ; i++){
        this->arr[i] = p[i];
    }
    this->arr[size] = a;
    this->size++;
    delete []p;
}
int Array::pop_back(){              //removes the last val
    int last = this->arr[this->size - 1];
    int *temp;
    temp = new int[this->size-1];
    for(int i=0;i < this->size -1 ; i++){
        temp[i] = this->arr[i];
    }
    delete []this->arr;
    this->arr = new int[this->size - 1];
    for(int i=0;i < this->size -1 ; i++){
        this->arr[i] = temp[i];
    }
    this->size--;
    delete []temp;
    return last;
}
int Array::insert(int idx, int val){            //insert the val at idx
    int *temp;
    if(idx > -1 && idx < this->size){
        temp = new int[this->size];
        for(int i=0;i < this->size ; i++){
            temp[i] = this->arr[i];
        }
        delete []this->arr;
        this->arr = new int[this->size+1];
        int i=0;
        for(i=0;i < idx ; i++){
            this->arr[i] = temp[i];
        }
        this->arr[i] = val;
        i++;
        for(;i< this->size+1 ;i++){
            this->arr[i] = temp[i-1];
        }
        this->size++;
        delete []temp;
        return 1;
    }else{
        return -1;
    }

}
int Array::erase(int idx){          //erase the val at idx (delete its memory)
    int *temp;
    if(idx > -1 && idx < this->size){
        temp = new int[this->size];
        for(int i=0;i < this->size ; i++){
            temp[i] = this->arr[i];
        }
        delete []this->arr;
        this->arr = new int[this->size-1];
        int i=0;
        for(i=0;i < idx ;i++){
            this->arr[i] = temp[i];
        }
        for(;i < this->size-1 ; i++){
            this->arr[i] = temp[i+1];
        }
        this->size--;
        delete []temp;
        return 1;
    }else{
        return -1;
    }
}
/*void Array::size(){

}*/
int Array::length(){            //give length
    return this->size;
}
void Array::clear(){            //clears the whole arr
    delete []this->arr;
    this->arr = new int [this->size];
}
int Array::value(int idx){          //same as setter at idx
    if(idx >-1 && idx < this->size){
        return this->arr[idx];
    }else{
        cout<<"Error"<<endl;
        return -1;
    }
}
void Array::assign(int idx, int val){           //same as above ???
    if(idx > -1 && idx < this->size){
        this->arr[idx] = val;
    }else{
        cout<<"Error"<<endl;
    }
}
void Array::copy(const Array& Arr){         //copy
    this->size = Arr.size;
    if(this->arr != NULL)
        delete []this->arr;
    this->arr = new int[this->size];
    for(int i=0;i<this->size;i++){
        this->arr[i] = Arr.arr[i];
    }
}
void Array::copy(const int * arr, int siz){     //copy
    this->size = siz;
    this->arr = new int[this->size];
    for(int i=0;i<this->size;i++){
        this->arr[i] = arr[i];
    }
}
void Array::display (){         //display
    if(this->arr!=NULL){
        for(int i=0;i < this->size;i++){
            cout<< this->arr[i] <<" ";
        }
        cout<<endl;
    }else{
        cout<<"First set values in arr"<<endl;
    }
}
bool Array::isEmpty(){          //isempty
    if(this->arr=NULL){
        return true;
    }else{
        return false;
    }
}
Array Array::find(int a){           //find the idxes and return arr of idxs
    Array ret;
    int p=0;
    for(int i=0; i < this->size ; i++){
        if(this->arr[i] == a)
            p++;
    }
    ret.size = p;
    ret.arr = new int[p];
    int c=0;
    for(int i=0; i < this->size ; i++){
        if(this->arr[i] == a){
            ret.arr[c] = i;
            c++;
        }
    }
    return ret;
}
bool Array::equal(const Array &a){              //check if arrays are equal
    bool chk=false;
    if(this->size = a.size){
        chk = true;
    }
    if(chk == true){
        for(int i=0;i < this->size ; i++){
            if(this->arr[i] != a.arr[i]){
                chk = false;
            }
        }
    }
    return chk;
}
int Array::sort(){              //sort
    bool chk = true;
    if(this->size == 0 || this->size == 1)
        chk = true;
    for(int i=1;i < this->size ; i++){
        if(this->arr[i] < arr[i-1]){
            chk = false;
        }
    }
    int temp=0;
    if(chk == false){
        for(int i=0;i < this->size ;i++){
            for(int j=0; j < this->size - i ; j++){
                if(this->arr[j] > this->arr[j+1]){
                    temp = this->arr[j];
                    this->arr[j] = this->arr[j+1];
                    this->arr[j+1] = temp;
                }
            }
        }
    }
    return chk;
}
void Array::reverse(){                  //reverse the arr
    int *temp = new int[this->size];
    for(int i=0;i<this->size;i++){
        temp[i] = this->arr[i];
    }
    delete []this->arr;
    this->arr = new int[this->size];
    int j=0;
    for(int i = this->size-1; i>=0;i--){
        this->arr[j] = temp[i];
        j++;
    }
    delete []temp;
}
Array::~Array(){                        //destructor
    delete []this->arr;
}
