#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
class job{
    int priority;
    int cap;
    public:
    job(){
        priority = -1;
        cap = 0;
    }
    job(int pri,int ca){
        priority = pri;
        cap = ca;
    }
    job(job& j1){
        cap = j1.cap;
        priority = j1.priority;
    }
    void set(int x,int y){
        priority = x;
        cap = y;
    }
    int getpri(){
        return priority;
    }
    int getcap(){
        return cap;
    }
    bool operator>(job& j1){
        bool chk = false;
        if(this->priority > j1.priority){
            chk = true;
        }
        return chk;
    }
    bool operator<(job& j1){
        if(this->priority < j1.priority){
            return true;
        }else{
            false;
        }
    }
    void print(){
        cout<<"Time taken By the Job : "<<static_cast<double>(cap)/10<<endl;
    }
};
void swap(job& j1, job& j2){
    job j3;
    j3 = j1;
    j1 = j2;
    j2 = j3;
}
class jobheap{
private:
    job *arr;
    int capacity;
    int crrsize;

public:
    jobheap(int cap = 100)
    {
        capacity = cap;
        crrsize = 1;
        arr = new job[capacity];
    }
    void insert(job &x)
    {
        if (crrsize + 1 == capacity)
        {
            cout << "Heap is full." << endl;
        }
        arr[crrsize++] = x;
        heapify();
    }
    void heapify()
    {
        int x = crrsize - 1;
        while (x > 1)
        {
            if (arr[x] > arr[x / 2])
            {
                swap(arr[x], arr[x / 2]);
                x = x / 2;
            }
            else
            {
                return;
            }
        }
    }
    void remove()
    {
        if (crrsize == 1)
        {
            cout << "Heap already Empty" << endl;
            return;
        }
        arr[1] = arr[crrsize - 1];
        crrsize--;
        int x = 1;
        int r, l;
        // cout<<crrsize<<"  .. " ;
        // print();
        while (x < crrsize)
        {
            l = x * 2;
            r = x * 2 + 1;
            if (l < crrsize && r < crrsize)
            {
                if (arr[l] > arr[r])
                {
                    if (arr[l] > arr[x])
                    {
                        swap(arr[l], arr[x]);
                        x = l;
                    }
                    else
                    {
                        return;
                    }
                }
                else
                {
                    if (arr[r] > arr[x])
                    {
                        swap(arr[r], arr[x]);
                        x = r;
                    }
                    else
                    {
                        return;
                    }
                }
            }
            else if(l < crrsize)
            {
                if (arr[l] > arr[x])
                {
                    swap(arr[l], arr[x]);
                    x = l;
                }
                else
                {
                    return;
                }
            }else{
                return;
            }
        }
    }
    void clear()
    {
        if (arr)
        {
            delete[] arr;
            arr = new job[capacity];
        }
        crrsize = 1;
    }
    bool isempty()
    {
        return (arr == NULL);
    }
    void print()
    {
        for (int i = 1; i < crrsize; i++)
        {
            cout<<"Job "<<i<<endl;
            arr[i].print();
        }
        cout << endl;
    }
    void operator=(jobheap& j1){
        capacity = j1.capacity;
        crrsize = j1.crrsize;
        for (int i = 0; i < crrsize; i++)
        {
            arr[i] = j1.arr[i];
        }
    }

};
class vm{
    int percent_used;
    int Curr_res;
    int Max_res;
    public:
    jobheap jh;
    vm(){
        Max_res = rand()%300 + 200;
        Curr_res = Max_res;
        calper();
    }
    vm(int max,int curr){
        Max_res = max;
        Curr_res = curr;
        calper();
    }
    vm(vm& v1){
        Max_res = v1.Max_res;
        Curr_res = v1.Max_res;
        calper();
        jh = v1.jh;
    }
    void calper(){
        percent_used = 100 - ((static_cast<double>(Curr_res)/Max_res)*100);
    }
    void decrase(int x){
        Curr_res = Curr_res-x;
        calper();
    }
    int getcapa(){
        return Curr_res;
    }
    int getperc(){
        return percent_used;
    }
    bool operator>(vm& v1){
        bool chk = false;
        if(this->percent_used > v1.percent_used){
            chk = true;
        }
        return chk;
    }
    bool operator<(vm& v1){
        if(this->percent_used < v1.percent_used){
            return true;
        }else{
            false;
        }
    }
    void print(){
        cout<<"Max Capacity of VM : "<<Max_res<<endl;
        cout<<"Current Capacity of VM : "<<Curr_res<<endl;
        cout<<"Percentage Usage of VM: "<<percent_used<<endl;
        cout<<"Jobs Done by the VM: "<<endl;
        jh.print();
        cout<<endl<<endl;
    }
};
void swap(vm& v1, vm& v2){
    vm v3;
    v3 = v1;
    v1 = v2;
    v2 = v3;
}
class vmheap
{
private:
    vm *arr;
    int capacity;
    int crrsize;

public:
    vmheap(int cap = 100)
    {
        capacity = cap;
        crrsize = 1;
        arr = new vm[capacity];
    }
    void insert(vm &x)
    {
        if (crrsize + 1 == capacity)
        {
            cout << "Heap is full." << endl;
        }
        arr[crrsize++] = x;
        heapify();
    }
    void heapify()
    {
        int x = crrsize - 1;
        while (x > 1)
        {
            if (arr[x] > arr[x / 2])
            {
                swap(arr[x], arr[x / 2]);
                x = x / 2;
            }
            else
            {
                return;
            }
        }
    }
    void remove()
    {
        if (crrsize == 1)
        {
            cout << "Heap already Empty" << endl;
            return;
        }
        arr[1] = arr[crrsize - 1];
        crrsize--;
        int x = 1;
        int r, l;
        // cout<<crrsize<<"  .. " ;
        // print();
        while (x < crrsize)
        {
            l = x * 2;
            r = x * 2 + 1;
            if (l < crrsize && r < crrsize)
            {
                if (arr[l] > arr[r])
                {
                    if (arr[l] > arr[x])
                    {
                        swap(arr[l], arr[x]);
                        x = l;
                    }
                    else
                    {
                        return;
                    }
                }
                else
                {
                    if (arr[r] > arr[x])
                    {
                        swap(arr[r], arr[x]);
                        x = r;
                    }
                    else
                    {
                        return;
                    }
                }
            }
            else if(l < crrsize)
            {
                if (arr[l] > arr[x])
                {
                    swap(arr[l], arr[x]);
                    x = l;
                }
                else
                {
                    return;
                }
            }else{
                return;
            }
        }
    }
    void clear()
    {
        if (arr)
        {
            delete[] arr;
            arr = new vm[capacity];
        }
        crrsize = 1;
    }
    bool isempty()
    {
        return (arr == NULL);
    }
    void print()
    {
        for (int i = 1; i < crrsize; i++)
        {
            cout<<"*** VM "<<i<<" ***"<<endl;
            arr[i].print();
            cout<<endl;
        }
        cout << endl;
    }
    vm* getvarr(int x){
        return arr;
    }
    void faul(){
        int x = rand()%10;
        for(int i=1 ; i < crrsize ; i++){
            if(arr[i].getperc() > 80){
                if(x == 5){
                    cout<<"Vm number "<<i<<" stopped working..."<<endl;
                    cout<<"Replacing the VM"<<endl;
                }else{
                    x = rand()%10;
                }
            }
        }
    }

};

void assign(vmheap& varr,job * arr,int size){
    vm * v1 = new vm;
    for (int i = 0; i < size; i++)
    {
        if(v1->getperc() >= 80){
            varr.insert(*v1);
            v1 = new vm;
        }
        if(arr[i].getcap() <= v1->getcapa() && (v1->getcapa() > arr[i].getcap())){
            v1->jh.insert(arr[i]);
            v1->decrase(arr[i].getcap());
        }
        else
        {   
            if(v1->getperc() > 0){
                varr.insert(*v1);
            }
            v1 = new vm;
            i--;
        }
        
    }
    // cout<<v1->getperc();
    if(v1->getperc() < 80){
        varr.insert(*v1);
    }
}
void print(vmheap& varr){
    varr.print();
}

int main(){
    srand(time(0));
    char c;
    ifstream fin("inp.txt");
    int x,y,i=0;
    job arr[100];
    while (!fin.eof())
    {
        fin>>x;
        fin>>y;
        arr[i++].set(x,y);
    }
    vmheap varr;
    int cond;
    bool chk = 0;

    do
    {
        // system("clear");
        cout<<"1 - Read Jobs From Files."<<endl;
        cout<<"2 - Print Jobs"<<endl;
        cout<<"3 - See the faulty_Tolrence"<<endl;
        cout<<"4 - Exit"<<endl;
        cin>>cond;
        if(cond == 1){
            assign(varr,arr,i);
            chk = 1;
            // cin>>c;
        }else if(cond == 2){
            if(chk == 1){
                varr.print();
                // cin>>c;
            }else{
                cout<<"First Read the jobs from the file..."<<endl<<endl;
            }
        }else if(cond == 3){
            if(chk == 1){
                varr.faul();
                // cin>>c;
            }else{
                cout<<"First Read the jobs from the file..."<<endl<<endl;
            }
        }else if(cond == 4){
            break;
        }else{
            cout<<"Invalid Input. Please Enter Again : ";
            cin>>cond;
        }
    }while (cond != 4 );
    



    return 0;
}