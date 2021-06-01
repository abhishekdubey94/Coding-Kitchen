public class Knapsack_ {

    public static int getMaxVal(int[] weights, int values[], int n, int W) {

        int dp[][] = new int[n + 1][W + 1];

        // i index is for weights and values
        // j index is for W
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= W; j++) {

                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                if (j >= weights[i - 1]) {
                    dp[i][j] = Math.max((values[i - 1] + dp[i - 1][j - weights[i - 1]]), (dp[i - 1][j]));
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][W];
    }

    public static void main(String[] args) {
        int weights[] = { 10, 20, 30 };
        int values[] = { 60, 100, 120 };
        int W = 50;

        System.out.println(getMaxVal(weights, values, 3, W));
    }
}
