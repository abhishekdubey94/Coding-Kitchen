#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<int> g[], int N);
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,e;
        cin>>n,e;
        vector<int> adj[n];
        for(int i=0;i<e;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        vector<int> res = bfs(adj,n);
        for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
        cout<<endl;
    }

    return 0;
}

vector <int> bfs(vector<int> g[], int N) {
    queue<int> q;
    vector<int> res;
    bool visited[N];
    for(int i = 0; i < N; i++) 
        visited[i] = false;
    visited[0] = true;
    q.push(0);
    while(!q.empty()){
        int p = q.front();
        res.push_back(p);
        q.pop();
        for(int i=0;i<g[p].size();i++){
            int l = g[p].at(i);
            if(!visited[l]){
                q.push(l);
                visited[l] = true;
            }
        }
    }
    return res;
}