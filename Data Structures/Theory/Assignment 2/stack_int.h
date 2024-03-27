#include <iostream>
using namespace std;

class nod
{
public:
    nod *next;
    int pew;
};
class stackin
{
    nod *top;
public:
    stackin()
    {
        top = NULL;
    }
    ~stackin()
    {
        if (top != NULL)
        {
            nod *curr = top;
            while (curr != NULL)
            {
                curr = curr->next;
                delete top;
                top = curr;
            }
        }
    }
    void Print()
    {
        if (top == NULL)
        {
            cout << "Stack Empty" << endl;
        }
        else
        {
            nod *curr = top;
            while (curr)
            {
                cout << curr->pew << " ";
                curr = curr->next;
            }
            cout << endl;
        }
    }
    void Push(int c)
    {
        nod *temp = new nod;
        temp->pew = c;
        temp->next = top;
        top = temp;
    }
    int Pop()
    {
        if (top == NULL)
        {
            cout << " NO element found" << endl;
            return -1;
        }
        nod *curr = top;
        top = curr->next;
        int pp = curr->pew;
        delete curr;
        return pp;
    }
    bool isEmpty()
    {
        return (top == NULL);
    }
    void Clear()
    {
        if (top != NULL)
        {
            nod *curr = top;
            while (curr != NULL)
            {
                curr = curr->next;
                delete top;
                top = curr;
            }
        }
    }
    void Peak()
    {
        if (top != NULL)
        {
            cout << top->pew << endl;
        }
        else
        {
            cout << "No elements..." << endl;
        }
    }
    int size(){
        if(top == NULL){
            return 0;
        }
        int i=0;
        nod * curr = top;
        while (curr)
        {
            curr = curr->next;
            i++;
        }
        return i;
    }
};