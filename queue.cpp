#include<iostream>
using namespace std;

class Queue{
    private:
        int front=-1;
        int rear=-1;
        int a[5];
    public:
        int isEmpty();
        int isFull();
        void enqueue(int v);
        void dequeue();
        void dislayQueue();
        void countQueue();
        void clear();
        void frontEle();
        void lastEle();
};

int Queue :: isEmpty()
{
    if(front==-1 && rear==-1)
        return 1;
    return 0;
}
int Queue :: isFull()
{
    if(rear==sizeof(a)-1)
        return 1;
    return 0;
}
void Queue :: enqueue(int v)
{
    if(isFull()){
        return;
    }
    else if(isEmpty()){
        front=0;
        rear=0;
    }
    else{
        rear++;
    }
    a[rear]=v;
}
void Queue :: dequeue()
{
    if(isEmpty())
        cout<<"Invalid Operation"<<endl;
    else{
        for(int i=0;i<rear;i++){
            a[i]=a[i+1];
        }
        rear--;
        front=a[0];
    }
}
void Queue :: dislayQueue()
{   
    if(isEmpty())
        cout<<"The QUEUE is empty.";
    else{
        cout<<"The elements inside QUEUE are: ";
        for(int i=0;i<=rear;i++)
            cout<<a[i]<<" ";
    }  

    cout<<endl; 
}
void Queue :: countQueue()
{   
    cout<<"The total elements inside the QUEUE are: "<<rear+1<<endl;
}
void Queue :: clear()
{
    for(int i=0;i<rear+1;i++)
        dequeue();
}
void Queue :: frontEle()
{
    cout<<"The front element of QUEUE: "<<a[front]<<endl;
}
void Queue :: lastEle()
{
    cout<<"The last element of the QUEUE: "<<a[rear]<<endl;
}


int main(){
    Queue q;
    q.dislayQueue();
    // q.countQueue();
    // q.clear();
    q.enqueue(3);
    // q.enqueue(4);
    // q.enqueue(5);
    // q.enqueue(6);
    q.dislayQueue();
    q.dequeue();
    q.dislayQueue();  
    return 0;
}



/*
C H E C K I N G---->>>
1. check clear()

*/