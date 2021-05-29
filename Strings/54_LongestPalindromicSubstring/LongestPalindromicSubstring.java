import java.net.MalformedURLException;

public class LongestPalindromicSubstring {
    static int longestPalSubstr(String str) {
        int n = str.length();
        if (n == 1) {
            return 1;
        }

        boolean dp[][] = new boolean[n][n];
        int start = 0;
        int maxLength = 1;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            if (str.charAt(i) == str.charAt(i + 1)) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        for (int k = 3; k <= n; k++) {
            for (int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;

                if (dp[i + 1][j - 1] && str.charAt(i) == str.charAt(j)) {
                    dp[i][j] = true;

                    if (k > maxLength) {
                        maxLength = k;
                        start = i;
                    }
                }
            }
        }

        return maxLength;
    }

    public static void main(String[] args) {

        String str = "forgeeksskeegfor";
        System.out.println("Length is: " + longestPalSubstr(str));
    }
}
