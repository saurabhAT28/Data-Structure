// DSU (Disjoint Set Union) (Graph)
// TC: O(alpha(n))

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+6;
typedef long long ll;

vector<int>parent(N);
vector<int>sz(N);

void makeSet(int v){
    parent[v]=v;
    sz[v]=1;
}

int findSet(int v){
    if(v==parent[v])
        return v;
    return parent[v]=findSet(parent[v]);
}

void unionSets(int a,int b){
    a=findSet(a);
    b=findSet(b);

    if(a!=b){
        if(sz[a]<sz[b])
            swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0;i<N;i++)
        makeSet(i);
    
    



    return 0;
}