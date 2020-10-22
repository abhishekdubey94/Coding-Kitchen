#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

class Solution{
    public:
        int nCr(int n,int r){
            int dp[r+1];
            memset(dp,0,sizeof(dp));
            dp[0] = 1;
            int j,i;
            for(i=n;i>0;i--){
                int temp = 1;
                for(j=1;j<n;j++){
                    int k = (temp+dp[j])%mod;
                    temp = dp[j];
                    dp[j] = k;
                }
                dp[j] = 1;
            }
            return dp[r];
        }
};
int main(){

    int t;
    cin>>t;
    while(t--){
        int n,r;
        cin>>n>>r;
        Solution ob = Solution();
        cout<<ob.nCr(n,r);
    }
    return 0;
}