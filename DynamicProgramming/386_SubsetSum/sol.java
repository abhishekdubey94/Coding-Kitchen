class Solution{
    static int equalPartition(int N, int arr[])
    {
        int sum = 0;
        
        for(int i:arr){
            sum+=i;
        }
        if(sum%2!=0){
            return 0;
        }
        sum = sum/2;
        
        boolean dp[][] = new boolean[N+1][sum+1];
        for(int j=0;j<=sum;j++){
            dp[0][j] = false;
        }
        for(int i=0;i<=N;i++){
            dp[i][0] = true;
        }
        for(int i=1;i<=N;i++){
            for(int j = 1;j<=sum;j++){
                    dp[i][j] =  dp[i-1][j];
                    if(j-arr[i-1]>=0)
                        dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
        }
        
        return dp[N][sum]?  1 :  0;
    }
}