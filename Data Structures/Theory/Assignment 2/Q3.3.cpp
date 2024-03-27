#include <iostream>
#include <queue>
#include <ctime>
#include <chrono>
using namespace std;

template <typename Func>
double measureTime(Func func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();  // Call the function to be measured
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the time duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

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
        deletepostorderTraversal(root);
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
        else if (d < p->data)
        {
            insert(p->left, d);
        }
        else{
                return;
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
        return false;
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

    void deletepostorderTraversal(node* &root) {
      if(root!=NULL) {
        deletepostorderTraversal(root->left);
        deletepostorderTraversal(root->right);
        delete root;
        root = NULL;
      }
    }

};


class Node{
    public:
        int data;
        int height;
        Node * left;
        Node * right;
    Node(int d){
        left = NULL;
        right = NULL;
        data = d;
        height = 1;
    }
};
class AVL{
    public:
        Node * root;

        AVL(){
            root = NULL;
        }
        ~AVL(){
            deletepostorderTraversal(root);
        }
        int height(Node * p){
            if(p == NULL)
                return 0;
            else
                return p->height;
        }
        int max(int a, int b){
            if(a>b)
                return a;
            else
                return b;
        }
        int getbal(Node * p){
            if(p == NULL)
                return 0;
            else{
                return (height(p->left) - height(p->right));
            }
        }
        Node * rr(Node * &root){
            // cout<<"rr"<<" ";
            Node *temp = root->left;  
            Node *Temp2 = temp->right;      
            temp->right = root;  
            root->left = Temp2;
            root->height = max(height(root->left),height(root->right)) + 1;  
            temp->height = max(height(temp->left),height(temp->right)) + 1;
            return temp;
        }
        Node * ll(Node * &root){
            // cout<<"ll"<<" ";
            Node *temp = root->right;  
            Node *Temp2 = temp->left;      
            temp->left = root;  
            root->right = Temp2;
            root->height = max(height(root->left),height(root->right)) + 1;  
            temp->height = max(height(temp->left),height(temp->right)) + 1;
            return temp;
        }

        Node * insert(Node * &root , int dat){
            if(root == NULL){
                root = new Node(dat);
                return root;
            }else if (root->data < dat)
            {
                root->right = insert(root->right , dat);
            }else if (root->data > dat)
            {
                root->left = insert(root->left , dat);
            }else{
                return root;
            }

            root->height = 1 + max(height(root->left), height(root->right));
            // cout<<"h = "<<root->height<<endl;
            int bal =  getbal(root); 
            // cout<<"bal "<<bal<<endl;

            if((bal > 1) && (dat < root->left->data)){
                // cout<<"kk";
                 return rr(root);
            }else if ((bal < -1) && (root->right->data < dat)){
                // cout<<"jj";
                return ll(root);
            }else if ((bal > 1) && (dat > root->left->data)){
                root->left = ll(root->left);
                return rr(root);
            }else if ((bal < -1) && (dat > root->right->data)){
                root->right = rr(root->right);
                return ll(root);
            }
            return root;
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
    void lnr(Node * root){
        if(root == NULL)
            return;
        lnr(root->left);
        cout<<root->data<<" ";
        cout<<"xd";
        lnr(root->right);
    }

    void deletepostorderTraversal(Node* &root) {
      if(root!=NULL) {
        deletepostorderTraversal(root->left);
        deletepostorderTraversal(root->right);
        delete root;
        root = NULL;
      }
    }

};


int main(){
    srand(time(0));
    double av = 0;
    double bs = 0;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    AVL t1;
    Tree t2;
    int rad = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int i = 0; i < 1000; i++)
        {   
            rad = rand();
            t1.root = t1.insert(t1.root,rad);
            t2.insert(t2.root,rad);
        }
        start = std::chrono::high_resolution_clock::now();
        bool s = t1.Search(t1.root,rand());
        end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        av = av + duration.count();

        // cout<<"AVL = "<<duration.count()<<endl;

        start = std::chrono::high_resolution_clock::now();
        s = t2.search(t2.root,rand());
        end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        bs = bs + duration.count();

        t1.deletepostorderTraversal(t1.root);
        t2.deletepostorderTraversal(t2.root);
    }
    
    
    // t1.lvlorder();
    
    // cout<<"BST = "<<duration.count()<<endl;

    cout<<"AVL : "<<av/1000<<endl;
    cout<<"BST : "<<bs/1000<<endl;
    return 0;
}