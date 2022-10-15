#include<iostream>
using namespace std;

void selectionSort(int n,int a[]){
    int temp,indexMin;
    for(int i=0;i<n-1;i++){
        indexMin=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[indexMin])
                indexMin=j;
        }
        temp=a[i];
        a[i]=a[indexMin];
        a[indexMin]=temp;
    }  
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    selectionSort(n,a);
    cout<<"**Elements after sorting:"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}