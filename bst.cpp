#include<iostream>
using namespace std;

//creation of tree
class tree{
    public:
        int data;
        tree* left;
        tree* right;
        tree(){
            left=NULL;
            right=NULL;
        }
        tree(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
        //function to insert node in bst
        tree* insertion(tree* &root,int data){
            if(root==NULL){
                root=new tree(data);
                return root;
            }
            tree* head=root;
            while(head){
            if(head->data > data){
                if(head->left==NULL){
                    head->left=new tree(data);
                    break;
                } 
                else
                    head=head->left;
            }
            else{
                if(head->right==NULL){
                    head->right=new tree(data);
                    break;
                }
                else{
                    head=head->right;
                    }
                }
            }
            return root;
        }
        //function to search in the bst
        tree* search(tree* root,int val){
            if(root==NULL)
                return NULL;
            if(root->data==val)
                return root;
            else if(root->data > val){
                return search(root->left,val);
            }    
            else{
                return search(root->right,val);
            }

        }

        //function to find minimum value
        tree* minvaluenode(tree* root){
            tree* current=root;
            while(current && current->left){
                current=current->left;
            }
            return current;
        }

        //function to delete a node in the bst
        tree* deletenode(tree* root,int val){
                if(root==NULL){
                    return root;
                }

                //search in leftsubtree
                if(val < root->data){
                    root->left=deletenode(root->left,val);
                }

                //search in right subtree
                else if(val > root->data){
                    root->right=deletenode(root->right,val);
                }

                else{
                    //delete node if node have no child
                    if(root->left == NULL && root->right == NULL){
                        return NULL;
                    }
                    //delete node if there is only one child
                    else if(root->left==NULL){
                        tree* temp=root->right;
                        delete(root);
                        return temp;
                    }
                    else if(root->right==NULL){
                        tree* temp=root->left;
                        delete(root);
                        return temp;
                    }
                    //if node have both child find minimum value in right subtree,replace the min node with node and delete the node 
                    else{
                        tree* temp=minvaluenode(root->right);
                        root->data=temp->data;
                        root->right=deletenode(root->right,val);
                    }
                }
            return root;
        }
        //print tree
        void print(tree*& root){
            if(root==NULL){
                return;
            }
            print(root->left);
            cout<<root->data<<" ";
            print(root->right);
        }
};


int main(){
    tree t;
    tree* root=NULL;
    root=t.insertion(root,10);
    t.insertion(root,7);
    t.insertion(root,11);
    t.insertion(root,13);
    t.insertion(root,9);
    t.insertion(root,90);
    tree* s=t.search(root,90);
    if(!s){
        cout<<"not found";
    }
    else{
        cout<<"found"<<endl;
    }
    t.print(root);
    cout<<endl;
    t.deletenode(root,13);
    t.print(root);
}