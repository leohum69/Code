#include <iostream>
#include <pthread.h>

using namespace std;

int arr[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

void * Sum(void * arg){
    int sum = 0;
    for(int i = 0; i < 20; i++){
        sum += arr[i];
    }
    printf("Sum: %d\n", sum);
    return NULL;
}

void * Mul(void * arg){
    int mul = 1;
    for(int i = 0; i < 20; i++){
        mul *= arr[i];
    }
    printf("Multiplication: %d\n", mul);
    return NULL;
}
void * search(void * arg){
    int * num  = (int * )arg;
    for(int i = 0; i < 20; i++){
        if(arr[i] == *num){
            // cout << "Number found at index: " << i << endl;
            printf("Number found at index: %d\n", i);
            return NULL;
        }
    }
    printf("Number not found\n");
    return NULL;
}


int main(){
    pthread_t t1, t2, t3;
    pthread_attr_t attribute;
    pthread_attr_init(&attribute);
    pthread_attr_setdetachstate(&attribute, PTHREAD_CREATE_DETACHED);
    pthread_create(&t1, &attribute, Sum, NULL);
    pthread_create(&t2, &attribute, Mul, NULL);
    int num = 10;
    pthread_create(&t3, &attribute, search, &num);

    pthread_attr_destroy(&attribute);


    return 0;
}