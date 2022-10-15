// Bubble Sort(Adaptive)
// Adaptive took less no. of passes

#include<iostream>
using namespace std;

void bubbleSortAdaptive(int n,int a[]){
    int temp;
    int sortingDone=0;
    for(int i=0;i<n-1;i++){
        cout<<"PASS: "<<i+1<<endl;
        sortingDone=1;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                sortingDone=0;
            }
        }
        if(sortingDone)
            return;    
    }
     
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    bubbleSortAdaptive(n,a);
    cout<<"**Elements after sorting:"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}