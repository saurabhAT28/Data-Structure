#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* root;

Node* Search(int data){
    Node* current=root;

    while(current!=NULL){
        if(current->data==data)
            return current;
        if(current->data>data)
            current=current->left;
        if(current->data<data)
            current=current->right;
    }
    return NULL;
}

void insert(int data){
    Node* n=new Node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    
    if(root==NULL)
        root=n;
    else{
        Node* current=root;
        Node* temp=NULL;
        while(1){
            temp=current;
            if(temp->data>data){
                current=current->left;
                if(current==NULL){
                    temp->left=n;
                    return;
                }
            }
            else{
                current=current->right;
                if(current==NULL){
                    temp->right=n;
                    return;
                }
            }
        }
    }
}
void inorder(Node* root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);  
}
void minValue(){
    Node* t=root;
    while(t->left!=NULL)
        t=t->left;
    cout<<"Minimum value in a tree: "<<t->data<<endl;
}
void maxValue(){
    Node* t=root;
    while(t->right!=NULL)
        t=t->right;
    cout<<"Maximum value in a tree: "<<t->data<<endl;
}

int inorderPredessor(Node* t){
    while(t->right!=NULL)
        t=t->right;
    int ip=t->data;
    delete(t);
    return ip;
}


void deleteNode(int val){
    Node* t=Search(val);
    if(t->left!=NULL && t->right!=NULL){
        t->data=inorderPredessor(t->left);
    }
}



int main(){
    
    insert(10);
    inorder(root);
    cout<<endl;
    insert(20);
    insert(5);
    insert(3);
    insert(24);
    cout<<Search(241)<<endl;
    cout<<Search(24)<<endl;
    // minValue();
    // insert(1);
    // inorder(root);
    // cout<<endl;
    // minValue();
    // maxValue();
    // insert(100);
    // maxValue();
    // inorder(root);
    // cout<<endl;

    // insert(11);
    // insert(6);
    // insert(19);
    // insert(4);
    // insert(8);
    // insert(17);
    // insert(43);
    // insert(5);
    // insert(10);
    // insert(31);
    // insert(49);
    // inorder(root);
    // cout<<endl;
    // deleteNode(6);
    // inorder(root);
    // cout<<endl;



    return 0;
}



