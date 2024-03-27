#ifndef GRAPH_H
#define GRAPH_H
#include "Minheap.h"
class node
{
public:
    pairs data;
    node *next;
    node(pairs &x)
    {
        data = x;
        next = NULL;
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
        cout << "Vertice : " << head->data << " , Neighbours: ";
        for (node *i = head->next; i != NULL; i = i->next)
        {
            cout << i->data << " ";
        }
        cout << endl;
    }
    pairs paor(string name)
    {
        pairs p1;
        for (node *i = head; i != NULL; i = i->next)
        {
            if (i->data.first.name == name)
            {
                p1 = i->data;
            }
        }
        return p1;
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
    void insert(vector<vector<pairs> > &v1)
    {
        vert = v1.size();
        pairs p1;
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
    vector<pairstring> dj_algo(string src)
    {
        vector<pairstring> distances;
        for (int i = 0; i < arr.size(); i++)
        {
            distances.push_back(pairstring(arr[i].head->data.first.name, 0));
            distances[i].second = 100;
        }
        MinHeap M1(100);
        int source;
        for (source = 0; source < distances.size(); source++)
        {
            if (distances[source].first == src)
            {
                distances[source].second = 0;
                break;
            }
        }
        M1.Push(pairstring(distances[source].first, 0));
        while (!M1.isempty())
        {
            pairstring p1 = M1.min();
            int nodedist = p1.second;
            M1.Pop();
            int is = 0;
            for (; is < arr.size(); is++)
            {
                if (p1.first == arr[is].head->data.first.name)
                {
                    break;
                }
            }
            for (node *i = arr[is].head->next; i != NULL; i = i->next)
            {
                int is = 0;
                for (; is < arr.size(); is++)
                {
                    if (i->data.first.name == arr[is].head->data.first.name)
                    {
                        break;
                    }
                }

                if ((nodedist + i->data.second) < distances[is].second)
                {
                    if (M1.findd(distances[is]))
                    {
                        M1.Pop();
                    }
                    distances[is].second = nodedist + i->data.second;
                    M1.Push(distances[is]);
                }
            }
        }
        return distances;
    }
};

#endif