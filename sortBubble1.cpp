// Bubble Sort

#include<iostream>
using namespace std;

void bubbleSort(int n,int a[]){
    int temp;
    for(int i=0;i<n-1;i++){
        cout<<"PASS: "<<i+1<<endl;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<"**Elements after sorting:"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" "; 
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    bubbleSort(n,a);
    return 0;
}