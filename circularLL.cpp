#include<iostream>
using namespace std;

class circularLL{
    struct node{
        int info;
        node* next;
    };
    
    node* last;
    public:
        circularLL(){
            last=NULL;
        }
        node* Search(int data){
            node* t;
            if(last==NULL)
                return NULL;
            t=last->next;
            do{
                if(t->info==data)
                    return t;
                t=t->next;
            }while(t!=last->next);
            
            return NULL;
        }
        void insertInEmptyLL(int data);
        void insertAtStart(int data);
        void insertAfter(int currentData,int data);
        void insertAtLast(int data);
        void deleteFirstNode();
        void deleteLastNode();
        void deleteNode(int data);
        void displayData();
};

void circularLL :: insertInEmptyLL(int data){
    node* n=new node;
    n->info=data;
    last=n;
    last->next=last;
}
void circularLL :: insertAtStart(int data){
    node* n=new node;
    n->info=data;
    n->next=last->next;
    last->next=n;
}
void circularLL :: displayData(){
    node* t=last->next;
    do{
        cout<<t->info<<" ";
        t=t->next;
    }while(t!=last->next);
    cout<<endl;
}
void circularLL :: insertAtLast(int data){
    node* n=new node;
    n->info=data;
    n->next=last->next;
    last->next=n;
    last=n;
}
void circularLL :: insertAfter(int currentData,int data){
    node* t=Search(currentData);
    if(t==NULL)
        cout<<"Invalid argument!!"<<endl;
    else{
        node* n=new node;
        n->info=data;
        n->next=t->next;
        t->next=n;
    }
}
void circularLL :: deleteFirstNode(){
    last->next=last->next->next;
}
void circularLL :: deleteNode(int data){
    node* p,* t;
    if(node* a=Search(data)){
        if(last==NULL)
            cout<<"List is empty"<<endl;
        else if(last==last->next && last->info==data){
            p=last;
            last=NULL;
        }
        else if(last->next->info==data){
            p=last->next;
            last->next=t->next;
        }
        else if(last->info==data){
            t=last;
            p->next=last->next;
            last=p;
            
        }
        else{
            p=last->next;
            while(p->next!=last){
                if(p->next->info==data){
                    t=p->next;
                    p->next=t->next;
                }
            }
        }
    }
    else{
        cout<<"Given node not found!!"<<endl;
    }
}


int main(){
    circularLL c1;
    c1.insertInEmptyLL(20);
    c1.insertAtStart(15);
    c1.insertAtStart(10);
    c1.insertAtLast(30);
    cout<<c1.Search(30)<<endl;
    c1.displayData();
    c1.insertAfter(20,25);
    c1.displayData();
    c1.deleteFirstNode();
    c1.displayData();
    c1.deleteNode(30);
    c1.displayData();
    return 0;
}




