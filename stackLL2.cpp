#include<iostream>
using namespace std;

struct Node{
    int info;
    Node* next;
};    

Node* top=NULL;

int isEmpty(){
    if(top==NULL)
        return 1;
    return 0;
}
void push(int data){
    Node* n=new Node;
    n->info=data;
    n->next=top;
    top=n;
}
void pop(){
    if(isEmpty())
        cout<<"Stack is empty"<<endl;
    else{
        cout<<"The data pop is: "<<top->info<<endl;
        top=top->next;
    }
}
void peek(){
    if(top==NULL)
        cout<<"Stack is Empty"<<endl;
    else
        cout<<"The peek item is: "<<top->info<<endl;
}
void display(){
    if(isEmpty())
        cout<<"Stack is empty."<<endl;
    else{
        Node* ptr;
        ptr=top;
        while(ptr!=NULL){
            cout<<ptr->info<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
}


int main(){
    int c,data;
    cout<<"1 --> Push in stack"<<endl;
    cout<<"2 --> Pop from stack"<<endl;
    cout<<"3 --> Peek of stack"<<endl;
    cout<<"4 --> Stack is Empty?"<<endl;
    cout<<"5 --> Display stack"<<endl;
    cout<<"6 --> Exit"<<endl;

    cout<<"*********************************"<<endl;

    do{
        cout<<"Enter choice: ";
        cin>>c;

        switch(c){
            case 1:{
                cout<<"Enter the data: ";
                cin>>data;
                push(data);
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                peek();
                break;
            }
            case 4:{
                if(isEmpty())
                    cout<<"Stack is empty"<<endl;
                else 
                    cout<<"Not empty"<<endl;
                break;
            }
            case 5:{
                display();
                break;
            }
            case 6:{
                cout<<"Thank you!!"<<endl;
                cout<<"E X I T"<<endl;
                break;
            }
            default :{
                cout<<"Please enter valid choice."<<endl;
            }     
        }
        cout<<"*********************************"<<endl;
    }while(c!=6);

    return 0;
}