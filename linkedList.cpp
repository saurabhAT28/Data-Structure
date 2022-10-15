#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

class linkedListADT{
    private:
        struct node{
            int item;
            node* next;
        };
        node* start;
    public:
        linkedListADT(){
            start=NULL;
        }
        node* Search(int data)
        {
            node* t;
            if(start==NULL)
                return NULL;
            t=start;
            while(t!=NULL)
            {
                if(t->item==data)
                    return t;
                t=t->next;
            }
            return NULL;
        }
        int countItems();
        void insertAtStart(int data);
        void insertAtLast(int data);
        void insertAfter(int currentData,int data);
        int searchItem(int data);
        void deleteFirstNode();
        int deleteItemFromStart();
        int deleteItemFromLast();
        int deleteGivenItem(int currentDat);
        void sortList();
        void editItem(int currentData,int newData);
        void viewList(node* start);
        int getFirstItem();
        int getLastItem();
        void copyLL(node* head);
        ~linkedListADT()
        {
            while(start!=NULL){
                deleteItemFromStart();
            }
        }
};

void linkedListADT :: insertAtStart(int data)
{
    node* n=new node;
    n->item=data;
    n->next=start;
    start=n;
}
void linkedListADT :: insertAtLast(int data)
{
    node* t;
    node* n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else{
        t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;        
    }
}
void linkedListADT :: insertAfter(int currentData,int data)
{
    node* t=Search(currentData);
    if(t==NULL)
        cout<<"No such value exist."<<endl;
    else{
        node* n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
    }
}
void linkedListADT :: deleteFirstNode(){
    start=start->next;
}
int linkedListADT :: deleteItemFromStart()
{
    if(start==NULL){
        cout<<endl<<"Underflow";
        return 0;
    }
    node* r;
    r=start;
    start=start->next;
    delete r;
    return 1;
}
int linkedListADT :: deleteItemFromLast()
{
    if(start==NULL){
        cout<<"\nUnderflow";
        return 0;
    }
    if(start->next==NULL){
        delete start;
        start=NULL;
        return 1;
    }
    node* t1;
    node * t2;

    t1=t2=start;
    do{
        t2=t1;
        t1=t1->next;
    }while(t1->next!=NULL);
    t2->next=NULL;
    return 1;
}
int linkedListADT :: deleteGivenItem(int currentData)
{
    node* t=Search(currentData);
    if(t==NULL){
        cout<<"\nItem not found";
        return 0;
    }
    if(t->next==NULL){
        deleteItemFromLast();
        return 1;
    }
    while(t->next!=NULL){
        t->item=t->next->item;
        t=t->next;
    }
    deleteItemFromLast();
    return 1;
}
void linkedListADT :: editItem(int currentData,int newData)
{
    node* t=Search(currentData);
    if(t==NULL)
        cout<<"\nItem not found";
    else
        t->item=newData;   
}
int linkedListADT :: countItems()
{
    int count=0;
    node* t;
    t=start;
    while(t!=NULL){
        count++;
        t=t->next;
    }
    return count;
}
int linkedListADT :: getFirstItem()
{
    if(start==NULL){
        cout<<"\nList is empty";
        return -1;
    }
    return start->item;
}
int linkedListADT :: getLastItem()
{
    node* t;
    if(start==NULL){
        cout<<"\nList is empty";
        return -1;
    }
    t=start;
    while(t->next!=NULL)
        t=t->next;
    return (t->item);
}
void linkedListADT :: viewList(node* start)
{
    node* t;
    t=start;
    if(t==NULL)
        cout<<"\nList is empty";
    else{
        while(t!=NULL){
            cout<<t->item<<" ";
            t=t->next;
        }
    }
}
int linkedListADT :: searchItem(int data)
{
    node* t;
    int pos=0;
    t=start;
    while(t!=NULL){
        pos++;
        if(t->item==data)
            return pos;
        t=t->next;
    }
    return -1;
}
void linkedListADT :: sortList()
{   
    
    node* t;
    int j,r,x,n;
    n=countItems();  
    for(r=1;r<n-1;r++){  
        t=start;
        for(j=0;j<=n-r-1;j++){    
            if(t->item > t->next->item){
                x=t->item;
                t->item=t->next->item;
                t->next->item=x;
            }
            t=t->next;
        }
    }
}

void linkedListADT :: copyLL(node* head){
    node* h1=head;
    node* ch=new node;
    node* c1=ch;
    node* c2=ch;
    ch->item=h1->item;
    h1=h1->next;
    
    while(h1!=NULL){
        node* Node=new node;
        Node->item=h1->item;
        h1=h1->next;
        ch->next=Node;
        ch=Node;
    }
    
    viewList(c2);
}



int main(){
    linkedListADT l1;
    l1.insertAtStart(10);
    l1.insertAfter(10,20);
    l1.insertAfter(20,30);
    l1.insertAtLast(50);
    l1.insertAtLast(40);
    
    // l1.copyLL();



    // l1.viewList();
    // l1.editItem(20,100);
    // cout<<endl;
    // l1.viewList();
    // cout<<endl;
    // l1.deleteFirstNode();
    // l1.viewList();
    // l1.deleteGivenItem(30);
    // cout<<endl;
    // l1.viewList();
    // cout<<endl;
    // l1.deleteItemFromStart();
    // l1.viewList();
    
    // cout<<l1.countItems()<<endl;
    // cout<<l1.getFirstItem()<<endl;
    // cout<<l1.searchItem(100)<<endl;
    // cout<<l1.Search(100)<<endl;
    // cout<<l1.Search(40)<<endl;
    
    
    return 0;
}