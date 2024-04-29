/*
if tie breaker happens, i display the shortest path and i just display the threads that had the same min length
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <pthread.h>
using namespace std;

class pairs
{
public:
    int first;
    int second;
    pairs()
    {
        this->first = 0;
        this->second = 0;
    }
    pairs(int first, int second)
    {
        this->first = first;
        this->second = second;
    }
    pairs(const pairs &p)
    {
        this->first = p.first;
        this->second = p.second;
    }
};
    ostream &operator<<(ostream &out, pairs &p)
    {
        cout<<p.first<<" with weight : "<<p.second;
        return out;
    }

class node
{
public:
    pairs data;
    node *next;
    node(pairs &data)
    {
        this->data = data;
        node *next = NULL;
    }
};
class adjlist
{
public:
    node *head;
    node *tail;
    adjlist()
    {
        head = NULL;
        tail = NULL;
    }
    void insert(pairs &x)
    {
        if (head == NULL)
        {
            head = new node(x);
            tail = head;
            return;
        }
        else
        {
            tail->next = new node(x);
            tail = tail->next;
        }
        return;
    }
    void print()
    {
        if (head == NULL)
        {
            cout << "List empty" << endl;
            return;
        }
        cout<<"vertex : "<<head->data.first<<" ";
        cout<<"Edges : ";
        for (node *i = head->next; i != NULL; i = i->next)
        {
            cout << i->data << " , ";
        }
        cout << endl;
    }
    pairs get(int i)
    {
        node *temp = head;
        while (temp != NULL && temp->data.first != i)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "No such vertex found" << endl;
            return pairs();
        }
        
        return temp->data;
    }
};
class graph
{
public:
    vector<adjlist> arr;
    int vert;

    graph()
    {
    }
    void insert(vector<vector<pairs>> &v1)
    {
        vert = v1.size();
        for (int i = 0; i < vert; i++)
        {
            arr.push_back(adjlist());
            for (int j = 0; j < v1[i].size(); j++)
            {
                arr[i].insert(v1[i][j]);
            }
        }
    }
    void showGraphStructure()
    {
        for (int i = 0; i < vert; i++)
        {
            arr[i].print();
            cout << endl;
        }
    }
};
vector<vector<int>> p1;
graph g;
int * global;
int turn = 0;

void * func(void *arg)
{
    int *start = (int *)arg;
    srand(time(0));
    while (turn != *start);
    
    int x = (rand()+pthread_self()) % p1.size();
    // cout<<"x: "<<x<<endl;
    int sum = 0;
    vector<int> temp = p1[x];
    p1.erase(p1.begin() + x);
    turn++;
    pairs temp22;
    temp22 = g.arr[temp[0]-1].get(temp[0]);
    // cout<<temp22.first<<" "<<temp22.second<<endl;
    sum+= temp22.second;
    for (int i = 0; i < temp.size()-1; i++)
    {
        temp22 = g.arr[temp22.first-1].get(temp[i+1]);
        // cout<<temp22.first<<" "<<temp22.second<<endl;
        sum+=temp22.second;
    }

    int * su = new int(sum);

    pthread_exit((void*)su);
}

int main()
{
    srand(time(0));
    ifstream file;
    file.open("input.txt");
    vector<vector<pairs>> v1;
    vector<int> l1;
    int n;
    int l;
    int arr[2];
    string x;
    file>>n;
    for (int i = 0; i < n; i++)
    {
        v1.push_back(vector<pairs>());
        v1[i].push_back(pairs(i+1, 0));
        l1.push_back(i+1);
    }
    while (!file.eof())
    {
        file>>l;
        // cout<<l<<endl;
        getline(file, x, '-');
        file>>arr[0];
        // cout<<arr[0]<<endl;
        file>>arr[1];
        // cout<<arr[1]<<endl;
        v1[l-1].push_back(pairs(arr[0], arr[1]));
        v1[arr[0]-1].push_back(pairs(l, arr[1]));
    }
    cout<<"l1 size"<<l1.size()<<endl;
    g.insert(v1);
    g.showGraphStructure();
    cout<<"Where do you wanna start from : ";
    int start;
    cin>>start;
    while (start < 1 || start>l1.size())
    {
        cout<<"Error! Enter Value in range : ";
        cin>>start;
    }
    

    l1.erase(l1.begin()+ (start - 1));

    // for (int i = 0; i < l1.size(); i++)
    // {
    //     cout<<l1[i]<<" ";
    // }
    vector<int> temp;
    do
    {   
        temp.push_back(start);
        for (int i = 0; i < l1.size(); i++)
        {
            temp.push_back(l1[i]);
        }
        temp.push_back(start);
        p1.push_back(temp);
        temp.clear();
        
    } while (next_permutation(l1.begin(), l1.end()));
    
    for (int i = 0; i < p1.size(); i++)
    {
        for (int j = 0; j < p1[i].size(); j++)
        {
            cout<<p1[i][j]<<" ";
        }
        cout<<endl;
        
    }
    

    cout<<"How many Threads : ";
    int threads;
    cin>>threads;
    while (threads<1 || threads>p1.size())
    {
        cout<<"Error! Enter Value in range : ";
        cin>>threads;
    }
    
    pthread_t *thr = new pthread_t[threads];
    global = new int[threads];
    int * res;
    int * tids[threads];
    for (int i = 0; i < threads; i++)
    {
        tids[i] = new int(i);
        pthread_create(&thr[i], NULL, func, (void *)tids[i]);
    }

    for(int i = 0; i < threads; i++)
    {
        pthread_join(thr[i], (void **)&res);
        global[i] = *res;
    }
    int min = 1000000;
    for (int i = 0; i < threads; i++)
    {
        if(global[i] < min)
        {
            min = global[i];
        }
    }
    int ssame = 0;
    vector<int> lol;
    for (int i = 0; i < threads; i++)
    {
        if(global[i] == min)
        {
            ssame++;
            lol.push_back(i);
        }
    }
    if(ssame > 1)
    {
        cout<<"There are multiple shortest paths with the same length, And there was a tie Breaker between "<<ssame<<" threads."<<endl;
        cout<<"The threads that had the same length are : ";
        for (int i = 0; i < lol.size(); i++)
        {
            cout<<lol[i] + 1<<" ";
        }
        cout<<"\nThe shortest path is of length : "<<min<<endl;
    }
    else
    {
        cout<<"The shortest path is of length : "<<min<<endl;
    }
    
    
//gotta set graph to work :/
    

    return 0;
}
