#include <iostream>
#include <pthread.h>
#include <vector>
#include <string>
using namespace std;

class pairss
{
public:
    string item;
    double price;
    double quantity;
    pairss()
    {
        this->item = "";
        this->price = 0;
        this->quantity = 0;
    }
    pairss(string item, double price, double quantity)
    {
        this->item = item;
        this->price = price;
        this->quantity = quantity;
    }
    pairss(const pairss &p)
    {
        this->item = p.item;
        this->price = p.price;
        this->quantity = p.quantity;
    }
};

vector <pairss> v1;
double total = 0;

void *thread1(void *arg)
{
    int n;
    cout << "Enter the number of items you purchased: ";
    cin >> n;
    double sum=0;
    for (int i = 0; i < n; i++)
    {
        string item;
        double price;
        double quantity;
        cout << "Enter the name of item " << i + 1 << ": ";
        cin >> item;
        cout << "Enter the quantity of item " << i + 1 << ": ";
        cin >> quantity;
        cout << "Enter the price of item " << i + 1 << ": ";
        cin >> price;
        sum+=(price*quantity);
        v1.push_back(pairss(item, price,quantity));
    }

    // cout << "Kharcha" <<endl<<endl;
    cout<<endl<<endl;

    for (int i = 0; i < n; i++)
    {
        cout<<v1[i].item<<" : "<<v1[i].quantity<<" x "<<v1[i].price << " = "<< (v1[i].quantity*v1[i].price)<<endl;
    }
    cout<<"Total: "<<sum<<endl;
    total = sum;
    
    double * p = new double(sum);
    pthread_exit((void*)p);
}
void * thread2(void * arg)
{
    double x = total / 1.8; // might change
    double y = x + total;
    printf("Taxed price : %f\n\n", y);
    pthread_exit(NULL);
}
void * thread3(void * arg)
{
    if(total > 250){
        double x = total * 0.1;
        double y = total - x;
        printf("Sale on Total price : %f\n\n", y);
    }
    pthread_exit(NULL);
}

void * thread4(void * arg)
{
    
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1.size()-1; j++)
        {
            if((v1[j].price * v1[j].quantity) < (v1[j+1].price * v1[j+1].quantity))
            {
                pairss temp = v1[j];
                v1[j] = v1[j+1];
                v1[j+1] = temp;
            }
        }
    }
    printf("Sorted Items: \n");
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i].item<<" : "<<v1[i].quantity<<" x "<<v1[i].price << " = "<< (v1[i].quantity*v1[i].price)<<endl;
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1,t2,t3,t4;
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_join(t1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);
    pthread_create(&t3, NULL, thread3, NULL);
    pthread_create(&t4, NULL, thread4, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    return 0;
}