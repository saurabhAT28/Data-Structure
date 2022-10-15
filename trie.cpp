#include<bits/stdc++.h>
using namespace std;

const int ALPHA_SIZE=26;

struct Trie{
    Trie* child[ALPHA_SIZE];
    bool endOfString;
};

Trie* createNode(void){
    Trie* t=new Trie;
    t->endOfString=false;
    for(int i=0;i<26;i++)
        t->child[i]=NULL;
    return t;
}

void insert(Trie* root,string key){
    Trie* cur=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'A';
        if(!cur->child[index])
            cur->child[index]=createNode();
        cur=cur->child[index];
    }
    cur->endOfString=true;
}

bool search(Trie* root,string key){
    Trie* cur=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'A';
        if(!cur->child[index])
            return false;
        cur=cur->child[index];
    }
    return (cur!=NULL && cur->endOfString);
}




int main(){
    Trie* root=createNode();

    string input[3]={"SAURABH","YASH","PAJU"};

    for(int i=0;i<3;i++){
        insert(root,input[i]);
    }

    insert(root,"RIDER");

    Trie* r=createNode();

    insert(r,"RIDER");
    insert(r,"ZZZ");
    insert(r,"RFV");

    cout<<"1.----->"<<search(r,"SAURABH")<<endl;
    cout<<"2.----->"<<search(r,"RIDER")<<endl;
    cout<<"3.----->"<<search(r,"RFV")<<endl;
    cout<<"4.----->"<<search(r,"ZZZ")<<endl;


    // cout<<"        "<<search(root,"SAURABHPO")<<endl;
    // cout<<"1.----->"<<search(root,"SAURABH")<<endl;
    // cout<<"2.----->"<<search(root,"PAJU")<<endl;
    // cout<<"3.----->"<<search(root,"YASH")<<endl;
    // cout<<"4.----->"<<search(root,"ABD")<<endl;
    // cout<<"5.----->"<<search(root,"RIDER")<<endl;

    return 0;
}