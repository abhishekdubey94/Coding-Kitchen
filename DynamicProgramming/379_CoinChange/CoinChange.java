public class CoinChange {
    public static void main(String[] args) {

    }

    long countChange(int S[], int m, int n) {
        long dp[] = new long[n + 1];
        dp[0] = 1;
        for (int coin : S) {
            for (int i = 0; i <= n; i++) {
                if (i >= coin) {
                    dp[i] = dp[i - coin] + dp[i];
                }
            }
        }

        return dp[n];
    }
}
