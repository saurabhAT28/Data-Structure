/*
Count Sort
Valid for negative numbers also

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

int minElement(int n,int a[]){
    int min=a[0];
    for(int i=1;i<n;i++){
        if(a[i]<min)
            min=a[i];
    }
    return min;
}


void countSort(int n,int a[]){
    int max,min;
    max=maxElement(n,a);
    min=minElement(n,a);

    int range=max-min+1;

    int count[range];
    int output[n];

    for(int i=0;i<range;i++)
        count[i]=0;

    for(int i=0;i<range;i++){
        count[a[i]-min]++;
    }

    for(int i=1;i<range;i++){
        output[count[a[i]-min]-1]=a[i];
        count[a[i]-min]--;
    }

    for(int i=0;i<n;i++){
        a[i]=output[i];
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