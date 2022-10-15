#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* root;

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
void inOrder(Node* root){
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);  
}
void preOrder(Node *root) {
        if(root==NULL)
            return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
void postOrder(Node *root) {
        if(root==NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
void breadthFirstTraversal(Node* root){
    if(root==NULL)
        return;
    queue<Node* >q;
    q.push(root);

    while(!q.empty()){
        Node* t=q.front();
        cout<<t->data<<" ";
        q.pop();
            
        if(t->left!=NULL)
            q.push(t->left);
        if(t->right!=NULL)
            q.push(t->right);
    }
}

int main(){
    int c,data;
    cout<<"1 --> Insert in a tree"<<endl;
    cout<<"2 --> Inorder Traversal"<<endl;
    cout<<"3 --> Postorder Traversal"<<endl;
    cout<<"4 --> Preorder Traversal"<<endl;
    cout<<"5 --> Exit"<<endl;

    cout<<"*********************************"<<endl;

    do{
        cout<<"Enter choice: ";
        cin>>c;

        switch(c){
            case 1:{
                cout<<"Enter the data: ";
                cin>>data;
                insert(data);
                break;
            }
            case 2:{
                cout<<"**Inorder Traversal: ";
                inOrder(root);
                cout<<endl;
                break;
            }
            case 3:{
                cout<<"**Postrder Traversal: ";
                postOrder(root);
                cout<<endl;
                break;
            }
            case 4:{
                cout<<"**Prerder Traversal: ";
                preOrder(root);
                cout<<endl;
                break;
            }
            case 5:{
                cout<<"Thank you!!"<<endl;
                cout<<"E X I T"<<endl;
                break;
            }
            default :{
                cout<<"Please enter valid choice."<<endl;
            }     
        }
        cout<<"*********************************"<<endl;
    }while(c!=5);
    return 0;
}