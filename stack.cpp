#include<iostream>
# define CAPACITY 30
using namespace std;

class Stack{
    private:
        int top=-1;
        int st[CAPACITY];
    public:
        int isFull();
        int isEmpty();
        void push(int val);
        int pop();
        void peek();
        void display();
};

int Stack :: isFull()
{
    if(top==CAPACITY-1){
        return 1;
    }
    return 0;   
}
int Stack :: isEmpty()
{
    if(top==-1){
        return 1;
    }
    return 0;
}
void Stack :: push(int val)
{
    if(isFull()){
        cout<<"The stack is FULL."<<endl;
    }
    else{
        top++;
        st[top]=val;
    }
}
int Stack :: pop()
{
    if(isEmpty())
        return 0;
    else
        return st[top--];           
}
void Stack :: peek()
{
    if(isEmpty()){
        cout<<"The stack is EMPTY."<<endl;
    }
    else{
        cout<<"The peek element is "<<st[top]<<endl;
    }
}
void Stack :: display()
{
    if(isEmpty()){
        cout<<"The stack is EMPTY."<<endl;
    }
    else{
        cout<<"The elements in stack are: ";
        for(int i=0;i<=top;i++)
            cout<<st[i]<<" ";
        cout<<endl;
    }
}


int main(){
    Stack s;
    int c,data;
    cout<<"1 --> Push in stack"<<endl;
    cout<<"2 --> Pop from stack"<<endl;
    cout<<"3 --> Peek of stack"<<endl;
    cout<<"4 --> Stack is Empty?"<<endl;
    cout<<"5 --> Display stack"<<endl;
    cout<<"6 --> Stack is full?"<<endl;
    cout<<"7 --> Exit"<<endl;
    
    cout<<"*********************************"<<endl;

    do{
        cout<<"Enter choice: ";
        cin>>c;

        switch(c){
            case 1:{
                cout<<"Enter the data: ";
                cin>>data;
                s.push(data);
                break;
            }
            case 2:{
                cout<<"The item is pop"<<endl;
                s.pop();
                break;
            }
            case 3:{
                s.peek();
                break;
            }
            case 4:{
                if(s.isEmpty())
                    cout<<"Stack is empty"<<endl;
                else 
                    cout<<"Not empty"<<endl;
                break;
            }
            case 5:{
                s.display();
                break;
            }
            case 6:{
                if(s.isFull())
                    cout<<"Stack is full"<<endl;
                else 
                    cout<<"Not full"<<endl;
                break;
            }
            case 7:{
                cout<<"Thank you!!"<<endl;
                cout<<"E X I T"<<endl;
                break;
            }
            default :{
                cout<<"Please enter valid choice."<<endl;
            }     
        }
        cout<<"*********************************"<<endl;
    }while(c!=7);

    return 0;
}