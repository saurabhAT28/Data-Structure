#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
        V=No of Vertex;
        E=No of edges;
    */
    cout<<"RIDER"<<endl;
    int V,E,a,b,wt;
    cin>>V>>E;
    vector<pair<int,int>>adj[V+1];

    for(int i=0;i<E;i++){
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
        // adj[a].push_back({b,wt});
    }

    vector<pair<int,int>>:: iterator it;
    for(auto it: adj[0]){
        cout<<it.first<<" "<<it.second<<endl;
    }


    return 0;
}