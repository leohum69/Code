#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
class AVL
{
public:
    Node *root;

    AVL()
    {
        root = NULL;
    }
    ~AVL()
    {
        deletepostorderTraversal(root);
    }
    int height(Node *p)
    {
        if (p == NULL)
            return 0;
        else
            return p->height;
    }
    int max(int a, int b)
    {
        if (a > b)
            return a;
        else
            return b;
    }
    int getbal(Node *p)
    {
        if (p == NULL)
            return 0;
        else
        {
            return (height(p->left) - height(p->right));
        }
    }
    Node *rr(Node *&root)
    {
        // cout<<"rr"<<" ";
        Node *temp = root->left;
        Node *Temp2 = temp->right;
        temp->right = root;
        root->left = Temp2;
        root->height = max(height(root->left), height(root->right)) + 1;
        temp->height = max(height(temp->left), height(temp->right)) + 1;
        return temp;
    }
    Node *ll(Node *&root)
    {
        // cout<<"ll"<<" ";
        Node *temp = root->right;
        Node *Temp2 = temp->left;
        temp->left = root;
        root->right = Temp2;
        root->height = max(height(root->left), height(root->right)) + 1;
        temp->height = max(height(temp->left), height(temp->right)) + 1;
        return temp;
    }

    Node *insert(Node *&root, int dat)
    {
        if (root == NULL)
        {
            root = new Node(dat);
            return root;
        }
        else if (root->data < dat)
        {
            root->right = insert(root->right, dat);
        }
        else if (root->data > dat)
        {
            root->left = insert(root->left, dat);
        }
        else
        {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));
        // cout<<"h = "<<root->height<<endl;
        int bal = getbal(root);
        // cout<<"bal "<<bal<<endl;

        if ((bal > 1) && (dat < root->left->data))
        {
            // cout<<"kk";
            return rr(root);
        }
        else if ((bal < -1) && (root->right->data < dat))
        {
            // cout<<"jj";
            return ll(root);
        }
        else if ((bal > 1) && (dat > root->left->data))
        {
            root->left = ll(root->left);
            return rr(root);
        }
        else if ((bal < -1) && (dat > root->right->data))
        {
            root->right = rr(root->right);
            return ll(root);
        }
        return root;
    }

    int findMax(Node *r)
    {
        Node * temp = r;
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

    Node *DeleteNode(Node *&p, int dat)
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
                Node *temp = p->left;
                delete p;
                return temp;
            }
            else if (p->left == NULL && p->right != NULL)
            {
                Node *temp = p->right;
                delete p;
                return temp;
            }
            else if (p->left != NULL && p->right != NULL)
            {
                int x = findMax(p->left);
                p->data = x;
                p->left = DeleteNode(p->left, x);
            }
        }
        else if (p->data > dat)
        {
            p->left = DeleteNode(p->left, dat);
        }
        else if (p->data < dat)
        {
            p->right = DeleteNode(p->right, dat);
        }

        p->height = 1 + max(height(p->left), height(p->right));
        // cout<<"h = "<<p->height<<endl;
        int bal = getbal(p);
        // cout<<"bal "<<bal<<endl;

        if ((bal > 1) && (getbal(p->left)>=0))
        {
            // cout<<"kk";
            return rr(p);
        }
         if ((bal < -1) && (getbal(p->right)<=0))
        {
            // cout<<"jj";
            return ll(p);
        }
         if ((bal > 1) && (getbal(p->left)<0))
        {
            p->left = ll(p->left);
            return rr(p);
        }
         if ((bal < -1) && (getbal(p->right)>0))
        {
            p->right = rr(p->right);
            return ll(p);
        }

        return p;
    }

    void lvlorder()
    {
        if (root == NULL)
            return;
        queue<Node *> q1;
        q1.push(root);
        q1.push(NULL);

        while (!q1.empty())
        {
            Node *temp = q1.front();
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
    bool Search(Node *&p, int d)
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
            Search(p->right, d);
        }
        else
        {
            Search(p->left, d);
        }
        return false;
    }
    void lnr(Node *root)
    {
        if (root == NULL)
            return;
        lnr(root->left);
        cout << root->data << " ";
        cout << "xd";
        lnr(root->right);
    }

    void deletepostorderTraversal(Node *&root)
    {
        if (root != NULL)
        {
            deletepostorderTraversal(root->left);
            deletepostorderTraversal(root->right);
            delete root;
            root = NULL;
        }
    }
};
int main()
{
    AVL t1;
    t1.root = t1.insert(t1.root, 1);
    t1.root = t1.insert(t1.root, 2);
    t1.root = t1.insert(t1.root, 3);
    t1.lvlorder();
    cout<<endl<<endl;
    t1.root = t1.insert(t1.root, 4);
    t1.root = t1.insert(t1.root, 5);
    t1.root = t1.insert(t1.root, 6);
    t1.root = t1.insert(t1.root, 10);
    t1.lvlorder();
    cout<<endl<<endl;

    t1.root = t1.insert(t1.root, 8);
    t1.root = t1.insert(t1.root, 7);
    t1.root = t1.insert(t1.root, 9);
    t1.lvlorder();
    cout<<endl<<endl;
    cout<<"Delete start "<<endl<<endl;

    //t1.root = t1.DeleteNode(t1.root,11);
    t1.root = t1.DeleteNode(t1.root,10);
    t1.root = t1.DeleteNode(t1.root,9);
    t1.root = t1.DeleteNode(t1.root,6);
    t1.lvlorder();
    cout<<endl<<endl;

    t1.root = t1.DeleteNode(t1.root,8);
    t1.root = t1.DeleteNode(t1.root,7);
    t1.lvlorder();
    cout<<endl<<endl;

    t1.root = t1.DeleteNode(t1.root,5);
    t1.root = t1.DeleteNode(t1.root,4);
    t1.root = t1.DeleteNode(t1.root,3);
    t1.root = t1.DeleteNode(t1.root,2);
    t1.lvlorder();
    cout<<endl<<endl;
    t1.root = t1.DeleteNode(t1.root,1);
    t1.lvlorder();
    cout<<endl<<endl;
    return 0;
}