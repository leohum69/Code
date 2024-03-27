#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void reverse(int *arr , int size){
    for(int i=0;i<size/2;i++){
        swap(arr[i],arr[size-i-1]);
    }
}

int main(){

    int arr[9] = {9,8,7,6,5,4,3,2,1};
    reverse(arr,9);

    for(int i=0;i<9;i++){
        cout<<arr[i]<<endl;
    }


}

