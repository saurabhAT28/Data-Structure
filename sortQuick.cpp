#include<iostream>
using namespace std;

int partition(int A[],int low,int high){
    int temp;
    int p=A[low];
    int i=low+1;
    int j=high;

    do{
        while(A[i]<=p)
            i++;
        
        while(A[j]>p)
            j--;
        
        if(i<j){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }      
    }while(i<j);

    temp=A[low];
    A[low]=A[j];
    A[j]=temp;

    return j;  
}

void quickSort(int A[],int low,int high){
    int partitionIndex;
    if(low<high){
        partitionIndex=partition(A,low,high);
        quickSort(A,low,partitionIndex-1);
        quickSort(A,partitionIndex+1,high);
    }

}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    quickSort(a,0,n-1);
    cout<<"**Elements after sorting:"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}