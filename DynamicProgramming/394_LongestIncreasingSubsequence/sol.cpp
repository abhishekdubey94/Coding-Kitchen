#include<bits/stdc++.h>

using namespace std;

int lis(int a[],int n){
    int dp[n];
    dp[0] = 1;
    int max = 0;
    for(int i=1;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(a[j]<a[i] && dp[i]<1+dp[j]){
                dp[i] = dp[j]+1;
            }
        }
        max = dp[i]>max ? dp[i]: max;
    }
    return max;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        cout<<lis(a,n)<<endl;
    }
    return 0;
}