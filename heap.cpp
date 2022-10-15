#include<bits/stdc++.h>
#include<vector>
using namespace std;

void heapify(vector<int> &v,int i){
    int size=v.size();
    int large=i;
    int leftChildIndex=2*i+1;
    int rightChildIndex=2*i+2;

    if(leftChildIndex<size && v[large]<v[leftChildIndex])
        large=leftChildIndex;
    
    if(rightChildIndex<size && v[large]<v[rightChildIndex])
        large=rightChildIndex;
    
    if(large!=i){
        swap(v[large],v[i]);
        heapify(v,large);
    }
}
void insert(vector<int> &v,int data){
    int size=v.size();

    if(size==0)
        v.push_back(data);
    else{
        v.push_back(data);
        for(int j=size/2;j>=0;j--)
            heapify(v,j);
    }
}
void deleteFromHeap(vector<int> &v,int data){
    int size=v.size();
    int i;
    for(i=0;i<size;i++){
        if(data==v[i])
            break;
    }

    swap(v[i],v[size-1]);

    v.pop_back();
    for(int i=size/2;i>=0;i--)
        heapify(v,i);
}
void display(vector<int>&v){
    cout<<"**HEAP: ";
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}

int main(){
    vector<int>v;
    int c,data;

    cout<<"1 --> Insert in a heap"<<endl;
    cout<<"2 --> Delete from heap"<<endl;
    cout<<"3 --> Display heap"<<endl;
    cout<<"4 --> Exit"<<endl;

    cout<<"*********************************"<<endl;

    do{
        cout<<"Enter choice: ";
        cin>>c;

        switch(c){
            case 1:{
                cout<<"Enter the data: ";
                cin>>data;
                insert(v,data);
                break;
            }
            case 2:{
                cout<<"Enter the data: ";
                cin>>data;
                deleteFromHeap(v,data);
                cout<<endl;
                break;
            }
            case 3:{
                display(v);
                break;
            }
            case 4:{
                cout<<"Thank you!!"<<endl;
                cout<<"E X I T"<<endl;
                break;
            }
            default :{
                cout<<"Please enter valid choice."<<endl;
            }     
        }
        cout<<"*********************************"<<endl;
    }while(c!=4);
    return 0;
}