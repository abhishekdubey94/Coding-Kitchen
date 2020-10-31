#include<bits/stdc++.h>
#define MAX 5
using namespace std;

vector<string> printPath(int m[MAX][MAX], int n);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int m[MAX][MAX];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>m[i][j];
            }
        }
        vector<string> res = printPath(m,n);
        if(res.size()==0){
            cout<<-1;
        }
        else{
            for(int i=0;i<res.size();i++){
                cout<<res[i]<<" ";
            }
        }
        cout<<endl;
    }
return 0;
}
bool isSafe(int x,int y,int n,bool visited[MAX][MAX]){
    if(x>=n || y>=n || x<0 ||y<0 || visited[x][y]){
        return false;
    }
    return true;
}

void printPathUtil(int m[MAX][MAX],int n,string& str,vector<string>& ans,int x,int y,bool visited[MAX][MAX]){
    if(x==n-1 && y==n-1){
        ans.push_back(str);
    }
    visited[x][y] = true;
    if(isSafe(x+1,y,n,visited) && m[x+1][y]){
            str.append("D");
            printPathUtil(m,n,str,ans,x+1,y,visited);
            str.pop_back();
            visited[x+1][y] = false;
    }
    if(isSafe(x,y-1,n,visited) && m[x][y-1]){
            str.append("L");
            printPathUtil(m,n,str,ans,x,y-1,visited);
            str.pop_back();
            visited[x][y-1] = false;
    }
    if(isSafe(x,y+1,n,visited) && m[x][y+1]){
            str.append("R");
            printPathUtil(m,n,str,ans,x,y+1,visited);
            str.pop_back();
            visited[x][y+1] = false;
    }
    if(isSafe(x-1,y,n,visited) && m[x-1][y]){
            str.append("U");
            printPathUtil(m,n,str,ans,x-1,y,visited);
            str.pop_back();
            visited[x-1][y] = false;
    }
}

vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string> ans;
    bool visited[MAX][MAX];
    string path="";
    memset(visited,false,sizeof(visited));
    printPathUtil(m,n,path,ans,0,0,visited);
    return ans;
}