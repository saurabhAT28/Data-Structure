/*
    1. Value of a3 and INT_MAX is same.
    2. Range of unsigned integer is double as compared to signed int(int).

*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    cout<<"INT_MAX: "<<INT_MAX<<endl;

    cout<<1e5+10<<endl;

    // Overflow
    // int a1=(1<<32)-1;

    unsigned int a2=(1LL<<32)-1;
    int a3=(1LL<<31)-1;

    // cout<<"a1: "<<a1<<endl;
    cout<<"a2: "<<a2<<endl;
    cout<<"a3: "<<a3<<endl;



    return 0;
}