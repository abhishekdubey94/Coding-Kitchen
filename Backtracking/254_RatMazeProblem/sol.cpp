#include<bits/stdc++.h>
using namespace std;
#define MAX 5

bool isSafe(int row,int col,bool visited[][MAX],int n){
    if(row>=n || row<0 || col>=n || col<0 || visited[row][col]){
        return false;
    }
    return true;
}

void printPathUtil(int row,int col,vector<string>& ans,bool visited[][MAX],string& path,int n,int m[MAX][MAX]){
    if(!isSafe(row,col,visited,n) || m[row][col]==0){
        return;
    }

    if(row==n-1 && col==n-1){
        ans.push_back(path);
        return;
    }

    visited[row][col] = true;

    if(isSafe(row+1,col,visited,n) && m[row+1][col]!=0 ){
        path.append("D");
        printPathUtil(row+1,col,ans,visited,path,n,m);
        path.pop_back();
        visited[row+1][col]=false;
    }

    if(isSafe(row,col-1,visited,n) && m[row][col-1]!=0 ){
        path.append("L");
        printPathUtil(row,col-1,ans,visited,path,n,m);
        path.pop_back();
        visited[row][col-1]=false;
    }
    if(isSafe(row,col+1,visited,n) && m[row][col+1]!=0 ){
        path.append("R");
        printPathUtil(row,col+1,ans,visited,path,n,m);
        path.pop_back();
        visited[row][col+1]=false;
    }
    if(isSafe(row-1,col,visited,n) && m[row-1][col]!=0 ){
        path.append("U");
        printPathUtil(row-1,col,ans,visited,path,n,m);
        path.pop_back();
        visited[row-1][col]=false;
    }
}

vector<string> printPath(int m[MAX][MAX],int n){
    vector<string> ans ;
    bool visited[n][MAX]={false};
    memset(visited,false,sizeof(visited));
    string path;

    printPathUtil(0,0,ans,visited,path,n,m);
    

    return ans;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int m[MAX][MAX];
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>m[i][j];
            }
        }

        vector<string> v = printPath(m,n);
        if(v.size()==0){
            cout<<-1;
        }else{
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
        }
    }

    return 0;
}