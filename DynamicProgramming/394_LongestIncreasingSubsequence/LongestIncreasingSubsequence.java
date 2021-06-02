public class LongestIncreasingSubsequence {

    static int longestSubsequence(int size, int a[]) {

    }

    int maxRef = 1;

    static int longestSubsequenceRecursive(int n, int a[]) {

        if (n == 1) {
            return 1;
        }

        int res, maxEndingHere = 1;

        for (int i = 1; i < n; i++) {
            res = longestSubsequenceRecursive(i, a);
            if (a[i - 1] < a[n - 1] && res + 1 > maxEndingHere) {

            }
        }
    }

    public static void main(String[] args) {
        int n = 16;
        int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
        System.out.println(longestSubsequence(n, arr));
    }
}
