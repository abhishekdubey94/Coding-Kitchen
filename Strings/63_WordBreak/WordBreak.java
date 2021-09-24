import java.util.Arrays;
import java.util.List;

public class WordBreak {
    public static boolean wordBreak(String s, List<String> dict) {
        if (dict.contains(s)) {
            return true;
        }
        boolean dp[] = new boolean[s.length() + 1];
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }

    public static void main(String[] args) {
        String[] B = { "i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go",
                "mango" };
        List<String> list = Arrays.asList(B);
        String A = "ilike";
        System.out.println(wordBreak(A, list));
    }
}
