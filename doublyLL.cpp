#include<iostream>
using namespace std;

class DoublyLL{
    private:
        struct node{
            int item;
            node* next;
            node* prev;
        };
        node* head;
        node* search(int data){
            if(head==NULL)
                return NULL;
            node* t;
            t=head;
            while(t!=NULL){
                if(t->item==data)
                    return t;
                t=t->next;
            }
            return NULL;
        }
    public:
        DoublyLL(){
            head=NULL;
        }
        void insertAtStart(int data);
        void insertAtLast(int data);
        void insertAfter(int currentData,int data);
        void deleteFirst();
        void deleteLast();
        void deleteGivenNode(int currentData);
        void display();

};

void DoublyLL :: insertAtStart(int data){
    node* n=new node;
    n->item=data;
    n->next=head;
    n->prev=NULL;
    if(head!=NULL)
        head->prev=n;
    head=n;   
}
void DoublyLL :: insertAtLast(int data){
    node* t;
    node* n=new node;
    n->item=data;
    n->next=NULL;
    t=head;
    if(t==NULL){
        n->prev=NULL;
        head=n;
    }
    else{
        t=head;
        while(t->next!=NULL)
            t=t->next;
        n->prev=t;
        t->next=n;
    }
    

}
void DoublyLL :: insertAfter(int currentData,int data){
    node* t=search(currentData);
    node* n=new node;
    if(t==NULL)
        cout<<"No such a value!!"<<endl;
    else{
        n->item=data;
        n->prev=t;
        n->next=t->next;
        if(t->next!=NULL)
            t->next->prev=n;
        t->next=n;
    }
}
void DoublyLL :: deleteFirst(){
    node* t;
    if(head==NULL)
        cout<<"INVALID"<<endl;
    else{
        t=head;
        head=head->next;
        head->prev=NULL;
        free(t);
    }
}
void DoublyLL :: deleteLast(){
    if(head==NULL)
        cout<<"INVALID!!"<<endl;
    node* t=head;
    while(t->next!=NULL)
        t=t->next;
    if(head->next==NULL)
        head=NULL;
    else 
        t->prev->next=NULL;
    
}
void DoublyLL :: deleteGivenNode(int currentData){
    node* t=search(currentData);
    if(head==NULL)
        cout<<"Not Present!!"<<endl;
    if(t->prev==NULL)
        head=t->next;
    if(t->next==NULL)
        t->prev->next=t->next;
    t->prev->next=t->next;
    t->next->prev=t->prev;
}
void DoublyLL :: display(){
    node* p;
    p=head;
    while(p!=NULL){
        cout<<p->item<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    DoublyLL d;
    d.insertAtStart(10);
    d.insertAtStart(20);
    d.insertAtStart(30);
    d.insertAtStart(40);
    d.insertAtLast(50);
    d.insertAfter(30,35);
    d.display();
    d.deleteFirst();
    d.display();
    d.deleteLast();
    d.display();
    d.deleteGivenNode(35);
    d.display();
    return 0;
}
