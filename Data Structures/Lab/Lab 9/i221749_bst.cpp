#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
class Tree
{
public:
    node *root;

public:
    Tree()
    {
        root = NULL;
    }
    ~Tree()
    {
    }
    void insert(node *&p, int d)
    {
        if (p == NULL)
        {
            p = new node(d);
            return;
        }
        else if (d > p->data)
        {
            insert(p->right, d);
        }
        else
        {
            insert(p->left, d);
        }
    }
    void printinorder(node *p)
    {
        if (p == NULL)
        {
            return;
        }
        printinorder(p->left);
        cout << p->data << " ";
        printinorder(p->right);
    }
    bool search(node *p, int d)
    {
        if (p == NULL)
        {
            return false;
        }
        else if (p->data == d)
        {
            return true;
        }
        if (d > p->data)
        {
            search(p->right, d);
        }
        else
        {
            search(p->left, d);
        }
    }
    bool isEmpty()
    {
        return (root == NULL);
    }
    int findMax(node *r)
    {
        node *temp = r;
        if (temp->right == NULL)
        {
            return temp->data;
        }
        else
        {
            while (temp->right)
            {
                temp = temp->right;
            }
            return temp->data;
        }
    }
    int findMin(node *r)
    {
        node *temp = r;
        if (temp->left == NULL)
        {
            return temp->data;
        }
        else
        {
            while (temp->left)
            {
                temp = temp->left;
            }
            return temp->data;
        }
    }
    void lvlorder()
    {
        if (root == NULL)
            return;
        queue<node *> q1;
        q1.push(root);
        q1.push(NULL);

        while (!q1.empty())
        {
            node *temp = q1.front();
            q1.pop();
            if (temp == NULL)
            {
                cout << endl;
                if (!q1.empty())
                    q1.push(NULL);
            }
            else
            {
                cout << temp->data << " ";
                if (temp->left)
                {
                    q1.push(temp->left);
                }
                if (temp->right)
                {
                    q1.push(temp->right);
                }
            }
        }
    }
    node *Deletenode(node *&p, int dat)
    {
        if (p == NULL)
        {
            return NULL;
        }
        else if (p->data == dat)
        {
            if (p->left == NULL && p->right == NULL)
            {
                delete p;
                return NULL;
            }
            else if (p->left != NULL && p->right == NULL)
            {
                node *temp = p->left;
                delete p;
                return temp;
            }
            else if (p->left == NULL && p->right != NULL)
            {
                node *temp = p->right;
                delete p;
                return temp;
            }
            else if (p->left != NULL && p->right != NULL)
            {
                int x = findMax(p->left);
                p->data = x;
                p->left = Deletenode(p->left, x);
            }
        }
        else if (p->data > dat)
        {
            p->left = Deletenode(p->left, dat);
        }
        else if (p->data < dat)
        {
            p->right = Deletenode(p->right, dat);
        }
        return p;
    }
    int numnodes(node * &p){
        if(p == NULL){
            return 0;
        }
        int left = numnodes(p->left);
        int right = numnodes(p->right);
        return left + right + 1;
    }


    int height(node *&p){
        if(p == NULL){
            return 0;
        }
        
        int right = height(p->right);
        int left = height(p->left);
        if(left>right){
            return left + 1;
        }else{
            return right + 1;
        }
    }

    bool fullbin(node * p){
        if(p == NULL){
            return true;
        }else if(p->left == NULL && p->right == NULL){
            return true;
        }else if(p->left != NULL && p->right != NULL){
            return fullbin(p->left) && fullbin(p->right);
        }else{
            return false;
        }
    }
    bool pefbin(node * p){
        bool x = false;
        x = fullbin(p);
        if(numnodes(p->left) == numnodes(p->right)){
            x = x && true;
        }else{
            x = false;
        }
        return x;
    }


    bool degen(node * p){
        if(p == NULL){
            return true;
        }else if(p->left == NULL && p->right == NULL){
            return true;
        }else if(p->left == NULL && p->right != NULL){
            return true && degen(p->right);
        }else if(p->left != NULL && p->right == NULL){
            return true && degen(p->left);
        }else{
            return false;
        }
    }
    /*bool balanced(node * p){
        if(p == NULL){
            return true;
        }

        int right = height(p->right);
        int left = height(p->left);
        if((left - right) <= 1 &&)
    }*/
};

int main()
{
    Tree t1;
    t1.insert(t1.root, 8);
    t1.insert(t1.root, 3);
    t1.insert(t1.root, 10);
    t1.insert(t1.root, 1);
    t1.insert(t1.root, 6);
    t1.insert(t1.root, 14);
    t1.insert(t1.root, 13);
    t1.insert(t1.root, 4);
    t1.insert(t1.root, 7);

    t1.lvlorder();cout<<endl;
    Tree t2;
    t2.insert(t2.root,40);
    t2.insert(t2.root,30);
    t2.insert(t2.root,50);
    t2.insert(t2.root,25);
    t2.insert(t2.root,35);
    t2.insert(t2.root,45);
    t2.insert(t2.root,60);
    t2.lvlorder();

    Tree t3;
    t3.insert(t3.root,1);
    t3.insert(t3.root,2);
    t3.insert(t3.root,3);
    t3.insert(t3.root,4);
    t3.insert(t3.root,5);
    t3.insert(t3.root,6);


    // cout<<endl;
    // cout<<t1.numnodes(t1.root)<<endl;
    // node *temp = t1.Deletenode(t1.root, 7);

    // cout<<endl;
    // t1.lvlorder();
    // cout<<endl;
    //cout<<t1.height(t1.root)<<endl;
    // cout<<t1.numnodes(t1.root)<<endl;
    cout<<t2.fullbin(t2.root)<<endl;
    cout<<t3.degen(t3.root)<<endl;
    cout<<t3.pefbin(t2.root)<<endl;
    return 0;
}