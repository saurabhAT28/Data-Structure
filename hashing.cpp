#include<iostream>
#include<list>
#include<string>
using namespace std;

class HashTable{
    private:
        static const int hashGroups=10;
        list<pair<int,string>> table[hashGroups];
    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key,string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTable :: isEmpty() const{
    int sum=0;
    for(int i=0;i<hashGroups;i++)
        sum+=table[i].size();
    if(!sum){
        return true;
    }
    return false;
}
int HashTable :: hashFunction(int key){
    return key%hashGroups;
}
void HashTable :: insertItem(int key,string value){
    int hashValue=hashFunction(key);
    auto& cell=table[hashValue];
    
}



int main(){
    HashTable ht1;
    cout<<ht1.isEmpty()<<endl;
    return 0;
}

