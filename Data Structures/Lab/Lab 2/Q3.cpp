#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int minidx(int *arr,int size,int start){
    int temp = arr[start];
    for(int i=start; i < size ;i++){
        if(temp>arr[i]){
            temp = arr[i];
        }
    }
    int idx = -1;
    for(int i=start;i<size ;i++){
        if(temp == arr[i])
            idx = i;
    }
    return idx;
}
void selection_sort(int *arr,int size){
    for(int i=0;i<size;i++){
        int pew = minidx(arr,size,i);
        swap(arr[i],arr[pew]);
    }
}

int main(){

    int arr[5] = {5,4,3,2,5};
    selection_sort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }


}

