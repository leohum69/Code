#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
        int data;
        node * left;
        node * right;
        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
class Tree{
    public:
        node * root;
    public:
        Tree(){
            root = NULL;
        }
        ~Tree(){

        }
        void insert(node * &p , int d){
            if(p == NULL){
                p = new node(d);
                return;
            }
            else if(d > p->data){
                insert(p->right , d);
            }else{
                insert(p->left , d);
            }
        }
        void printinorder(node * p){
            if(p == NULL){
                return;
            }
            printinorder(p->left);
            cout<<p->data << " ";
            printinorder(p->right);
        }
        bool search(node * p, int d){
            if(p == NULL){
                return false;
            }else if(p->data == d){
                return true;
            }
            if(d > p->data){
                search(p->right,d);
            }else{
                search(p->left , d);
            }
        }
        bool isEmpty(){
            return (root == NULL);
        }
        int findMax(){
            node * temp = root;
            if(root->right == NULL){
                return root->data;
            }else{
                while (temp->right)
                {
                    temp = temp->right;
                }
                return temp->data;
            }
        }
        int findMin(){
            node * temp = root;
            if(root->left == NULL){
                return root->data;
            }else{
                while (temp->left)
                {
                    temp = temp->left;
                }
                return temp->data;
            }
        }
};

int main(){
    Tree t1;
    cout<<t1.isEmpty()<<endl;
    t1.insert(t1.root,45);
    t1.insert(t1.root,9);
    t1.insert(t1.root,8);
    t1.insert(t1.root,44);
    t1.insert(t1.root,2);
    t1.insert(t1.root,1);

    t1.printinorder(t1.root);
    cout<<endl;
    cout<<t1.findMax();
    cout<<endl<<t1.search(t1.root , 2)<<endl;
    cout<<t1.isEmpty()<<endl;
    cout<<t1.findMin()<<endl;
    return 0;
}