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
    int size;
    Node *top;
    int currel;

public:
    stack(int size)
    {
        this->size = size;
        top = NULL;
        currel = 0;
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
            currel == 0;
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
        if (currel == size)
        {
            cout << "Stack Already Full" << endl;
            return;
        }

        Node *temp = new Node;
        temp->pew = c;
        temp->next = top;
        top = temp;
        currel++;
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
        currel--;
        return pp;
    }
    bool isEmpty()
    {
        return (top == NULL);
    }
    bool isFULL()
    {
        return (currel == size);
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
            currel == 0;
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
};
void pref(string pew);
int main()
{
    stack s1(10);
    s1.Push('c');
    s1.Push('p');
    s1.Push('s');
    s1.Print();
    s1.Peak();
    pref("1 + 2 * (3 / 4)");
    pref("1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10) - 11 + (12*8)] + 14");
    pref("1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10)} - 11 + (12*8) / {13 +13}] + 14");
}
void pref(string pew)
{
    int i = 0;
    stack s1(10);
    while (pew[i] != '\0')
    {
        if(pew[i] == '(' || pew[i] == '{' || pew[i] == '['){
            s1.Push(pew[i]);
        }
        if(pew[i] == ')' || pew[i] == '}' || pew[i] == ']'){
            s1.Pop();
        }
        i++;
    }
    if(s1.isEmpty()){
        cout<<"The Expression is Correct"<<endl;
    }else{
        cout<<"The Expression is Incorrect"<<endl;
    }
}