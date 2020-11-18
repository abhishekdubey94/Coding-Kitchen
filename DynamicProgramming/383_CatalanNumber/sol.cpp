#include<bits/stdc++.h>
using namespace std;

int catalan(int n){
    int dp[n+1] ;
    dp[0] = 1;
    dp[1] = 1;

    for(int t=1;t<n;t++){
        dp[t+1] = 0;
        for(int i=0;i<=t;i++){
            dp[t+1] = dp[t+1]+dp[i]*dp[t-i];
        }
    }

    return dp[n];
}

int main(){

    for (int i = 0; i < 10; i++) 
        cout << catalan(i) << " "; 
    return 0;
}