#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    char pew;
};
class stack
{
    Node *top;
public:
    stack()
    {
        top = NULL;
    }
    ~stack()
    {
        if (top != NULL)
        {
            Node *curr = top;
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
            Node *curr = top;
            while (curr)
            {
                cout << curr->pew << " ";
                curr = curr->next;
            }
            cout << endl;
        }
    }
    void Push(char c)
    {
        Node *temp = new Node;
        temp->pew = c;
        temp->next = top;
        top = temp;
    }
    char Pop()
    {
        if (top == NULL)
        {
            cout << " NO element found" << endl;
            return ' ';
        }
        Node *curr = top;
        top = curr->next;
        char pp = curr->pew;
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
            Node *curr = top;
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
        Node * curr = top;
        while (curr)
        {
            curr = curr->next;
            i++;
        }
        return i;
    }
};

