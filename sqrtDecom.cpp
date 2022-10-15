// Square Root Decomposition
// TC=O(n*Q)
// n=No. of element
// Q=No. of Query

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];
    
    int len=sqrtl(n)+1;

    vector<int>v(len);

    // Adding group sum to vector
    for(int i=0;i<n;i++){
        v[i/len]+=a[i];
    }

    // TESTCASES
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;

        // From one based indexing to zero based indexing
        l--;
        r--;

        int sum=0;

        for(int i=l;i<=r;){
            if(i%len==0 && i+len-1<=r){
                // Whole block lie in a range l and r
                sum+=v[i/len];
                i+=len;
            }
            else{
                sum+=a[i];
                i++;
            }
        }
        cout<<"SUM: "<<sum<<"\n";
    }

    return 0;
}