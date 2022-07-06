#include<iostream>
using namespace std;

//creation of tree
class tree{
    public:
        int data;
        tree* left;
        tree* right;
        tree(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};


int main(){
    tree* t=new tree(10);
    t->left=new tree(20);
    t->right=new tree(30);
    t->left->left=new tree(20);
    t->left->right=new tree(30);
    t->right->left=new tree(20);
    t->right->right=new tree(30);
}