#include <iostream>
using namespace std;

class node
{
public:
    int data;
    string password;
    string hash;
    node *left;
    node *right;
    node(int data, string password)
    {
        this->data = data;
        this->password = password;
        this->left = NULL;
        this->right = NULL;
    }
};

class BMTree
{
public:
    node *root;
    BMTree()
    {
        root = NULL;
    }
    ~BMTree()
    {
        clear(root);
    }
    void insert(int data, string password)
    {
        node *new_node = new node(data, password);
        if (root == NULL)
        {
            root = new_node;
            return;
        }
        node *cur = root;
        while (true)
        {
            if (data < cur->data)
            {
                if (cur->left == NULL)
                {
                    cur->left = new_node;
                    return;
                }
                cur = cur->left;
            }
            else
            {
                if (cur->right == NULL)
                {
                    cur->right = new_node;
                    return;
                }
                cur = cur->right;
            }
        }
    }
    void print(node *cur)
    {
        if (cur == NULL)
            return;
        print(cur->left);
        cout << cur->data << " " << cur->password << " " << cur->hash << endl;
        print(cur->right);
    }
    bool isEmtpy()
    {
        return root == NULL;
    }
    void clear(node *cur)
    {
        if (cur == NULL)
            return;
        clear(cur->left);
        clear(cur->right);
        delete cur;
    }
    int findMaxint(node *r)
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
    string findmaxpass (node *r)
    {
        node *temp = r;
        if (temp->right == NULL)
        {
            return temp->password;
        }
        else
        {
            while (temp->right)
            {
                temp = temp->right;
            }
            return temp->password;
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
                int x = findMaxint(p->left);
                p->data = x;
                string y = findmaxpass(p->left);
                p->password = y;
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
    void deleteNode(int data)
    {
        node *temp = root;
        Deletenode(temp, data);
    }
};

int main()
{
    BMTree tree;
    tree.insert(10, "abc");
    tree.insert(20, "def");
    tree.insert(5, "ghi");
    tree.insert(15, "jkl");

    tree.print(tree.root);

    tree.deleteNode(10);

    tree.print(tree.root);
}