#include<iostream>
using namespace std;

class Solution{
    public:
        long long int count(int S[], int m, int n){
            long long dp[n+1];
            dp[0] = 1;
            for(int i=1;i<=n;i++){
                dp[i] = 0;
            }
            for(int i=0;i<m;i++){
                int coin = S[i];
                for(int j=0;j<=n;j++){
                    if(j-coin>=0)
                        dp[j] = dp[j]+dp[j-coin];
                }
            }
            return dp[n];
        }

        
};

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[m];
        for(int i=0;i<m;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.count(arr,m,n)<<endl;
    }

    return 0;
}