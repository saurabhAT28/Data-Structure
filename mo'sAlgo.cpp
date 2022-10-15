// Mo's Algorithm
// Square Root Decomposition
// Efficien Approach

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+2;
typedef long long ll;
int rootN;

struct Q{
    int idx,l,r;
};

Q q[N];

bool compare(Q q1,Q q2){
    if(q1.l/rootN==q2.l/rootN)
        return q1.r>q2.r;
    return q1.l/rootN<q2.l/rootN;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    rootN=sqrtl(n);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int l,r;
        cin>>l>>r;
        q[i].idx=i;
        q[i].l=l;
        q[i].r=r;
    }

    sort(q,q+t,compare);

    int curL=0,curR=-1,l,r;
    int curAns=0;

    vector<int>ans(t);

    for(int i=0;i<t;i++){
        l=q[i].l;
        r=q[i].r;
        l--;
        r--;

        while(curR<r){
            curR++;
            curAns+=a[curR];
        }

        while(curL>l){
            curL--;
            curAns+=a[curL];
        }

        while(curL<l){
            curAns-=a[curL];
            curL++;
        }

        while(curR>r){
            curAns-=a[curR];
            curR--;
        }
        ans[q[i].idx]=curAns;
    }

    cout<<"Ans: ";
    for(int i=0;i<t;i++){
        cout<<ans[i];
    }

    return 0;
}