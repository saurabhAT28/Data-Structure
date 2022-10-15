#include<iostream>
using namespace std;

class Stack{
    struct Node{
        int info;
        Node* next;
    };
    Node* top=NULL;
    public:
        int isEmpty();
        void push(int data);
        void pop();
        void peek();
        void display();
};

int Stack :: isEmpty(){
    if(top==NULL)
        return 1;
    return 0;
}
void Stack :: push(int data){
    Node* n=new Node;
    n->info=data;
    n->next=top;
    top=n;
}
void Stack :: pop(){
    if(isEmpty())
        cout<<"Stack is empty"<<endl;
    else{
        cout<<"The data pop is: "<<top->info<<endl;
        top=top->next;
    }
}
void Stack :: peek(){
    cout<<"The peek item is: "<<top->info<<endl;
}
void Stack :: display(){
    if(isEmpty())
        cout<<"Stack is empty."<<endl;
    else{
        Node* ptr;
        ptr=top;
        while(ptr!=NULL){
            cout<<"|  "<<ptr->info<<"  |\n";
            ptr=ptr->next;
            cout<<"|______|\n";
        }
        cout<<endl;
    }
}


int main(){
    int c,data;
    Stack s;
    s.push(10);
    s.push(23);
    s.push(12);

    s.display();
    return 0;
}






