//i221749_Mirza Humayun Masood
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;
class process{
    public:
    int start;
    int thresh;
    process(int s, int t){
        start = s;
        thresh = t;
    }
    void print(){
        cout<<"Start : "<<start<<" Thresh : "<<thresh<<endl;
    }
};

int arr[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
// int arr[20] = };

void * multiply(void * arg){
    process *p = (process *)arg;
    int mul = 1;
    for(int i = p->start;i < p->start + p->thresh; i++){
        if(i >= 20)
            break;
        mul = mul * arr[i];
    }
    int * m = new int(mul);
    pthread_exit((void*)m);
}

int main(){

    cout<<"Enter The Number of Threads You want to create : ";
    int n;
    cin>>n;

    while (n>20)
    {
        cout<<"Number of Threads should be less than 20\n";
        cin>>n;
    }
    

    int thresh = 20/n;
    if(20%n != 0)
        thresh = thresh + 1;

    pthread_t * thread = new pthread_t[n];

    for (int i = 0; i < n; i++)
    {
        process *p = new process(i*thresh, thresh);
        // p->print();
        pthread_create(&thread[i], NULL, multiply, (void *)p);
    }
    long long int res = 1;
    for (int i = 0; i < n; i++)
    {
        int * mul;
        pthread_join(thread[i], (void **)&mul);
        res = res * *mul;
    }

    delete[] thread;
    
    cout<<"Result is : "<<res<<endl;

    return 0;
}