public class CoinChangeWaysDP {
    public static void main(String[] args) {
        int coins[] = { 1, 2, 3 };
        int m = coins.length;
        int N = 4;
        System.out.println(coinChangeWays(coins, m, N));
    }

    private static int coinChangeWays(int[] coins, int m, int n) {

        int dp[] = new int[n + 1];
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = coins[i]; j <= n; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[n];
    }
}
