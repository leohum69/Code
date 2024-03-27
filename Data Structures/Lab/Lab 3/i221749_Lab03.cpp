#include <iostream>
using namespace std;

class List{
    private:
        int * arr;
        int size;
    public:
        List(){
            int x;
            cout<<"Enter The size of list: ";
            cin>>x;
            while(x<=0){
                cout<<"Enter Again... : ";
                cin>>x;
            }
            this->size = x;
            this->arr = new int[size];
            for(int i=0; i < size ; i++){
                cout<<"Enter the "<<i+1<<"th element: ";
                cin>>arr[i];
            }
        }
        List(int pew){
            this->size = pew;
            this->arr = new int[size];
            for(int i=0; i < size ; i++){
                cout<<"Enter the "<<i+1<<"th element: ";
                cin>>arr[i];
            }
        }
        List(List &L2){
            this->size = L2.size;
            this->arr = new int[size];
            for(int i=0 ; i < size ; i++){
                this->arr[i] = L2.arr[i];
            }
        }

        void ins_at_end(int element){
            int* arr2 = new int[this->size+1];
            for(int i=0; i < this->size;i++){
                arr2[i] = this->arr[i];
            }
            arr2[this->size] = element;
            delete []arr;
            this->arr = new int[this->size+1];
            for(int i=0;i<this->size+1;i++){
                arr[i] = arr2[i];
            }
            delete []arr2;
            this->size++;
        }
        void ins_at_start(int element){
            int* arr2 = new int[this->size+1];
            for(int i=1; i < this->size+1;i++){
                arr2[i] = this->arr[i];
            }
            arr2[0] = element;
            delete []arr;
            this->arr = new int[this->size+1];
            for(int i=0;i<this->size+1;i++){
                arr[i] = arr2[i];
            }
            delete []arr2;
            this->size++;
        }
        void inst_at_idx(int idx,int element){
            int x = idx;
            while(x<0){
                cout<<"Enter Again...: ";
                cin>>x;
            }
            int *arr2 = new int[this->size + 1];
            for(int i = 0 ; i < x ; i++){
                arr2[i] = arr[i];
            }
            arr2[x] = element;
            for(int i= x+1; i<this->size+1; i++){
                arr2[i] = arr[i-1];
            }
            delete []arr;
            this->arr = new int[this->size+1];
            for(int i=0;i<this->size+1;i++){
                arr[i] = arr2[i];
            }
            delete []arr2;
            this->size++;
        }
        void rem_at_end(){
            int *arr2 = new int[size-1];
            for(int i=0;i<this->size-1; i++){
                arr2[i] = this->arr[i];
            }
            delete []arr;
            this->arr = new int[this->size-1];
            for(int i=0;i<this->size-1;i++){
                arr[i] = arr2[i];
            }
            delete []arr2;
            this->size--;
        }
        void rem_at_start(){
            int *arr2 = new int[size-1];
            for(int i=1;i<this->size; i++){
                arr2[i-1] = this->arr[i];
            }
            delete []arr;
            this->arr = new int[this->size-1];
            for(int i=0;i<this->size-1;i++){
                arr[i] = arr2[i];
            }
            delete []arr2;
            this->size--;
        }
        void rem_at_idx(int idx){
            int x = idx;
            while(x<0){
                cout<<"Enter Again...: ";
                cin>>x;
            }
            int *arr2 = new int[this->size-1];
            for(int i=0 ; i < x ; i++){
                arr2[i] = arr[i];
            }
            for(int i = x ; i<size;i++){
                arr2[i] = arr[i+1];
            }
            delete []arr;
            this->arr = new int[this->size-1];
            for(int i=0;i<this->size-1;i++){
                arr[i] = arr2[i];
            }
            delete []arr2;
            this->size--;

        }
        int NEXT(int idx, List& L){
            if(idx == L.size - 1)
                return -1;
            return L.arr[idx+1];
        }
        int PREVIOUS(int idx, List& L){
            if(idx == 0)
                return -1;
            return L.arr[idx-1];
        }


        void print(){
            for(int i=0 ; i < this->size ; i++){
                cout<<this->arr[i]<<" ";
            }
            cout<<endl;
        }
        bool is_empty(){
            bool x = true;
            if(this->size == 0){
                return true;
            }
            else{
                for(int i= 0 ; i<size ;i++){
                    if(arr[i]!=0)
                        x = false;
                }
            }
            return x;
        }
        void Replace(int idx , int val){
            int x = idx;
            while(x < 0 || x > size-1){
                cout<<"Enter Again...: ";
                cin>>x;
            }
            arr[x] = val;
        }
        void clearthelist(){
            delete []arr;
            size = 0;
        }
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
        void sort(){
            for(int i=0;i<this->size;i++){
                int pew = minidx(this->arr,this->size,i);
                swap(this->arr[i],this->arr[pew]);
            }
        }
        int search(int element){
            for(int i=0;i<size;i++){
                if(element == arr[i])
                    return i;
            }
            return -1;
        }
        bool duplicate(){
            bool pew = false;
            for(int i=0 ; i < size ; i++){
                for(int j=i+1;j<size;j++){
                    if(arr[i] == arr[j])
                        pew = true;
                }
            }
            return pew;
        }






};
int main(){
    List x;
    x.print();
    x.ins_at_end(5);
    x.print();
    x.inst_at_idx(2,69);
    x.print();
    x.rem_at_end();
    x.print();
    x.rem_at_start();
    x.print();
    x.rem_at_idx(3);
    x.print();
    x.sort();
    x.print();
    cout<<x.NEXT(1,x)<<endl;
    cout<<x.PREVIOUS(2,x)<<endl;
    cout<<x.duplicate()<<endl;
    x.clearthelist();
    cout<<x.is_empty();

}
