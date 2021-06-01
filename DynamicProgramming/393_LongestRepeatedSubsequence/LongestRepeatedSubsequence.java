public class LongestRepeatedSubsequence {
    static int findLongestRepeatingSubSeq(String str) {
        int n = str.length();
        if (n == 0) {
            return 0;
        }
        int dp[][] = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (str.charAt(j - 1) == str.charAt(i - 1) && i != j) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }

            }
        }
        return dp[n][n];
    }

    public static void main(String[] args) {
        String s = "aay";
        System.out.println(findLongestRepeatingSubSeq(s));
    }
}
