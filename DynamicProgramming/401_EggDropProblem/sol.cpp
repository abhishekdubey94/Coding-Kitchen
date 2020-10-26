#include<bits/stdc++.h>
using namespace std;

int minAttempt(int n,int k){
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=k;i++){
        dp[1][i] = i;
    }

    for(int i=1;i<=n;i++){
        dp[i][1] = 1;
    }

    for(int i=2;i<=n;i++){
        for(int j=2;j<=k;j++){  
            dp[i][j] = INT_MAX;         // total number of floors are changing and also the value of n-x will change, the case when egg
                                        // does not break and we need to evaluate for remaining floors (n-x). this will change with every floor
                                        // that we choose to fill dp
            for(int p=1;p<=j;p++){    // for each floor, evaluate from 1st floor 

                dp[i][j] = min(dp[i][j],max(dp[i-1][p-1],dp[i][j-p])+1);

                //max represent the worst case scenario, and min is to find the minimum attempt to find the best from the worst case
            }
        }
    }

    return dp[n][k];
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<minAttempt(n,k)<<endl;
    }
    return 0;
}