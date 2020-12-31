public class LongestPalindromicSubstring {
    public static void main(String[] args) {
        LongestPalindromicSubstring l = new LongestPalindromicSubstring();
        System.out.println(l.longestPalindrome("Hello"));

    }

    public String longestPalindrome(String s) {
        String res = null;
        int n = s.length();
        boolean dp[][] = new boolean[n][n];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                dp[i][j] = s.charAt(i) == s.charAt(j) && (j - i < 3 || dp[i + 1][j - 1]);

                if (dp[i][j] && (res == null || res.length() <= j - i + 1)) {
                    res = s.substring(i, j + 1);
                }
            }
        }

        return res;
    }
}
