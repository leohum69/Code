#ifndef MINHEAP_H
#define MINHEAP_H
#include "Pairs.h"
class MinHeap
{
    vector<pairstring> arr;
    int maxsize;
    int numelements;

public:
    MinHeap(int arrsize)
    {
        maxsize = arrsize;
        arr.resize(++arrsize);
        numelements = 0;
    }
    pairstring min()
    {
        return arr[1];
    }
    int size()
    {
        return numelements;
    }
    void Push(pairstring val)
    {
        if (numelements == maxsize)
        {
            cout << "Heap is full!" << endl;
            return;
        }
        int index = ++numelements;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent].second > arr[index].second)
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void Pop()
    {
        if (numelements == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        pairstring temp = arr[1];
        arr[1] = arr[numelements];
        numelements--;

        int i = 1;
        while (i < numelements)
        {
            int LC = 2 * i;
            int RC = (2 * i) + 1;
            int largest = i;

            if (LC <= numelements && arr[largest].second > arr[LC].second)
                largest = LC;

            if (RC <= numelements && arr[largest].second > arr[RC].second)
                largest = RC;

            if (largest == i)
            {
                break;
            }
            else
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < numelements; i++)
        {
            cout << arr[i + 1] << " ";
        }
        cout << endl;
    }
    bool isempty()
    {
        return (numelements == 0);
    }
    bool findd(pairstring &p1)
    {
        for (int i = 0; i <= numelements; i++)
        {
            if (p1.second == arr[i].second)
            {
                return true;
            }
        }
        return false;
    }
};
#endif