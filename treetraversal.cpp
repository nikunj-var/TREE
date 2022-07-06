#include<iostream>
using namespace std;

class node{
public:    
    int data;
    node* left,*right;
    
    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    void postorder(node* root){
        if(root==NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    void preorder(node* root){
        if(root==NULL)
            return;
        cout<<root->data<<" ";    
        preorder(root->left);
        preorder(root->right);
        
    }
    void inorder(node* root){
        if(root==NULL)
            return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};

int main(){
    node* t=new node(10);
    t->left=new node(20);
    t->right=new node(30);
    t->left->left=new node(40);
    t->left->right=new node(50);
    t->right->left=new node(60);
    t->right->right=new node(70);
    t->inorder(t);
    cout<<endl;
    t->postorder(t);
    cout<<endl;
    t->preorder(t);
    cout<<endl;

}


















