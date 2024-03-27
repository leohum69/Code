#include <iostream>
using namespace std;

class heap
{
private:
    int *arr;
    int capacity;
    int crrsize;

public:
    heap(int cap = 100)
    {
        capacity = cap;
        crrsize = 1;
        arr = new int[capacity];
    }
    void insert(int x)
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
            arr = new int[capacity];
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
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void heap_sort()
    {
        // cout << crrsize << endl;
        int *arr2 = new int[crrsize];
        int p = crrsize;
        for (int i = p; i > 1; i--)
        {   
            // cout<<arr[1]<<" ";
            arr2[i - 1] = arr[1];
            remove();
            // print();
        }
        for (int i = 1; i < p; i++)
        {
            arr[i] = arr2[i];
        }

        crrsize = p;
    }
};

int main()
{
    heap h1;
    h1.insert(5);
    h1.insert(3);
    h1.insert(17);
    h1.insert(10);
    h1.insert(84);
    h1.insert(19);
    h1.insert(6);
    h1.insert(22);
    h1.insert(9);
    // h1.heapify();

    h1.print();

    // h1.remove();
    // h1.print();
    // h1.remove();
    // h1.print();
    // h1.remove();
    // cout << endl;
    // cout << "After Deletion" << endl
    //      << endl;
    // h1.print();
    // cout << endl;
    cout<<"After sort"<<endl<<endl;
    h1.heap_sort();
    cout<<endl;
    h1.print();
    return 0;
}