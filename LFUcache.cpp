#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key,value,cnt;
    Node* next;
    Node* prev;

    Node(int key,int value){
        this->key=key;
        this->value=value;
        cnt=1;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;

    List(){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }

    void addFront(Node* n){
        Node* temp=head->next;
        n->next=temp;
        n->prev=head;
        head->next=n;
        temp->prev=n;
        size++;
    }

    void removeNode(Node* n){
        Node* dp=n->prev;
        Node* dn=n->next;
        dp->next=dn;
        dn->prev=dp;
        size--;
    }
};


class LFUcache{
    map<int,Node* >keyNode;
    map<int,List* >freqList;
    int maxSizeCache;
    int minFreq;
    int curSize;
    
    public:

    LFUcache(int capacity){
        maxSizeCache=capacity;
        minFreq=0;
        curSize=0;
    }

    void updateFreqList(Node* node){
        keyNode.erase(node->key);
        freqList[node->cnt]->removeNode(node);

        if(node->cnt==minFreq && freqList[node->cnt]->size==0)
            minFreq++;
        
        List* nextHigherFreqList=new List();

        if(freqList.find(node->cnt+1)!=freqList.end())
            nextHigherFreqList=freqList[node->cnt+1];
        
        node->cnt+=1;
        nextHigherFreqList->addFront(node);
        freqList[node->cnt]=nextHigherFreqList;
        keyNode[node->key]=node;
    }

    int get(int key){
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            int val=node->value;
            updateFreqList(node);
            return val;
        }
        return -1;
    }

    void put(int key,int value){
        if(maxSizeCache==0)
            return ;
        
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            node->value=value;
            updateFreqList(node);
        }
        else{
            if(curSize==maxSizeCache){
                List* list=freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqList[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }

            curSize++;

            minFreq=1;
            List * listFreq=new List();

            if(freqList.find(minFreq)!=freqList.end())
                listFreq=freqList[minFreq];
            
            Node* node=new Node(key,value);
            listFreq->addFront(node);
            keyNode[key]=node;
            freqList[minFreq]=listFreq;
        }

    }


};



int main(){


    return 0;
}