#include <iostream>
using namespace std;

class node{
    public:
    int data;
    string password;
    string hash;
    node * left;
    node * right;
    
    node(int dat,string pass,string has){
        left = NULL;
        right = NULL;
        password = pass;
        hash = has;
        data = dat;
    }

};

class Tree{
    public:
    node * root;

    Tree(){
        root = NULL;
    }

    void insert(node * root ,int dat,string pass,string has )
    {
        if(root == NULL){
            root = new node(data,pass,has);
            return;
        }
        if(root->data > dat){
            insert(root->left,dat,pass,has);
        }else{
            insert(root->right,dat,pass,has);
        }
    }
};

// void print(node * root){
//     if(root == NULL){
//         return;
//     }
//     print(root->left);
//     cout<<root->data;
//     print(root->right);
// }

int main(){


    

    return 0; 
}