/*
Count Sort
This intuition is only valid for positive numbers because there are no negative indices.

*/


#include<iostream>
using namespace std;

int maxElement(int n,int a[]){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max)
            max=a[i];
    }
    return max;
}

void countSort(int n,int a[]){
    int max;
    max=maxElement(n,a);
    int count[max+1];

    for(int i=0;i<max+1;i++)
        count[i]=0;

    for(int i=0;i<n;i++){
        count[a[i]]=count[a[i]]+1;
    }
    int j=0,k=0;
    while(j<=max){
        if(count[j]>0){
            a[k]=j;
            k++;
            count[j]=count[j]-1;
        }
        else  
            j++;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    countSort(n,a);
    cout<<"**Elements after sorting:"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}