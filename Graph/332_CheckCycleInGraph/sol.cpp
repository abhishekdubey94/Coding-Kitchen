#include<bits/stdc++.h>
using namespace std;

bool isCyclic(vector<int> a[],int n);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,e;
        cin>>n>>e;
        vector<int> a[n];
        for(int i=0;i<e;i++){
            int u,v;
            cin>>u>>v;
            a[u].push_back(v);
        }

        if(isCyclic(a,n)){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
    }
    return 0;
}

bool isCyclicUtil(int i,vector<int> a[],bool *rec,bool *visited){
    visited[i] = true;
    rec[i] = true;

    for(int j=0;j<a[i].size();j++){
        if(!visited[a[i][j]] && isCyclicUtil(a[i][j],a,rec,visited)){
            return true;
        }
        else if(rec[a[i][j]]){
            return true;
        }
    }

    rec[i] = false;
    return false;
}
bool isCyclic(vector<int> a[],int n){
    bool visited[n];
    memset(visited,false,sizeof(visited));
    bool rec[n];
    memset(rec,false,sizeof(rec));
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(isCyclicUtil(i,a,rec,visited))
                return true;
        }
    }
    return false;
}