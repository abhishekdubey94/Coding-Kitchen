#include<bits/stdc++.h>
using namespace std;
vector<int> dfs(vector<int> g[], int N);
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
        vector<int> res = dfs(adj,n);
        for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
        cout<<endl;
    }

    return 0;
}

vector<int> dfs(vector<int> a[],int n){
    bool visited[n];
    memset(visited,false,sizeof(visited));
    stack<int> st;
    st.push(0);
    vector<int> ans;
    while(!st.empty()){
        int p = st.top();
        ans.push_back(p);
        visited[p]=true;
        st.pop();
        for(int i=a[p].size()-1;i>=0;i--){
            if(!visited[a[p][i]])
                st.push(a[p][i]);
        }
    }
    return ans;

}