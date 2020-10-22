#include<bits/stdc++.h>
using namespace std;

int maxValueInKnapsack(int n,int w,int V[],int W[]){
    int dp[n+1][w+1] = {0};
    memset(dp,0,sizeof(dp));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(W[i-1]>j){ //current weight selected is greater than the capacity of bag i.e j
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],V[i-1]+dp[i-1][j-W[i-1]]);
            }
        }
    }
    return dp[n][w];
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int N,W;
        cin>>N;
        cin>>W;
        int val[N];
        int weights[N];
        for(int i=0;i<N;i++){
            cin>>val[i];
        }

        for(int i=0;i<N;i++){
            cin>>weights[i];
        }

        cout<<maxValueInKnapsack(N,W,val,weights)<<" ";
    }
    return 0;
}