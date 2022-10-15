// Insertion sort 
// <<------- Ascending order ------->>

#include<iostream>
using namespace std;

void inSort(int n,int a[]){
    
    int key,j;
    for(int i=1;i<n;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;      
    } 
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    inSort(n,a);
    return 0;
}