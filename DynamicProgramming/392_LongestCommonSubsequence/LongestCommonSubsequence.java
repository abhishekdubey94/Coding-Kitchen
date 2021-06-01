public class LongestCommonSubsequence {

    public static int longestcommonsubsequence(String s1, String s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 == 0 || n2 == 0) {
            return 0;
        }
        int dp[][] = new int[n1 + 1][n2 + 1];

        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                    if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }

        }
        return dp[n1][n2];
    }

    public static int longestcommonsubsequenceRECURSIVE(String S1, String S2) {
        if (S1.length() == 0 || S2.length() == 0) {
            return 0;
        }
        if (S1.charAt(S1.length() - 1) == S2.charAt(S2.length() - 1)) {
            return longestcommonsubsequenceRECURSIVE(S1.substring(0, S1.length() - 1), S2.substring(0, S2.length() - 1))
                    + 1;
        } else {
            return Math.max(longestcommonsubsequenceRECURSIVE(S1.substring(0, S1.length() - 1), S2),
                    longestcommonsubsequenceRECURSIVE(S1, S2.substring(0, S2.length() - 1)));
        }
    }

    public static void main(String[] args) {
        String S1 = "ABCDGH";
        String S2 = "AEDFHR";

        System.out.println(longestcommonsubsequenceRECURSIVE(S1, S2));
        System.out.println(longestcommonsubsequence(S1, S2));
    }
}
