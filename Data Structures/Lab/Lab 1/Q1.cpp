#include <iostream>

using namespace std;

template <typename T>

void Print(T* A , int size) {
    cout << "Printing values of Array: ";
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
   }
template <typename T>

T* Union(T* A, T* B, int sizeofa, int sizeofb) {
    int x=0;
    bool chk = true;
    for(int i=0;i<sizeofa;i++){
        for(int j=0;j<sizeofb;j++){
            if(A[i]==B[j])
                x++;
        }
    }
    x = sizeofa + sizeofb - x;


    T *arr = new T[x];
    int p=0;


    for (int i = 0; i < sizeofa; i++)
        arr[p++] = A[i];




    for (int i = 0; i < sizeofb; i++) {
        for (int j = 0; j < sizeofa; j++) {
            if (B[i] == A[j]) {
                chk = false;
            }
        }
        if (chk == true)
            arr[p++] = B[i];
        chk = true;
    }
    //cout<<p<<endl;
    return arr;

}
template <typename T>
T* intersection(T* A, T* B, int sizeofa, int sizeofb){
    int x=0;
    int p=0;
    for(int i=0;i<sizeofa;i++){
        for(int j=0;j<sizeofb;j++){
            if(A[i]==B[j])
                x++;
        }
    }
    T* arr = new T[x];
    for(int i=0;i<sizeofa;i++){
        for(int j=0;j<sizeofb;j++){
            if(A[i]==B[j])
                arr[p++] = A[i];
        }
    }
    return arr;

}
template <typename T>
bool Disjoint(T* A, T* B, int sizeofa, int sizeofb){
    bool chk=false;
    for(int i=0;i<sizeofa;i++){
        for(int j=0;j<sizeofb;j++){
            if(A[i]==B[j])
                chk = true;
        }
    }

    return !chk;
}

template <typename T>
bool FindElement(T element, T *A, int sizeofa){
    bool chk = false;
    for(int i=0;i<sizeofa;i++){
        if(element == A[i])
            chk=true;
    }
    return chk;
}


int main()
{
    double A[] = {10.43,4.3,5.61,6.90,11.57,12.11,3.8,2.4,9.5};
    double B[] = {11.01,12.34,16.5,3.8,8.1,2.4,9.11,12.11,6.75,10.43,20.2,2.1,4.3};
    Print<double>(A, 9);
    double *unionwali =Union<double>(A, B, 9, 13);
    Print<double>(unionwali, 17);
    double *interserctionwali = intersection<double>(A, B, 9, 13);
    Print<double>(unionwali, 5);
    cout<<boolalpha<<Disjoint<double>(A, B, 9, 13)<<endl;
    cout<<boolalpha<<FindElement<double>(11.01 , A ,9);


}
