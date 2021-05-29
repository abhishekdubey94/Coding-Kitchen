public class minJumpDP {

    public static void main(String args[]) {
        int arr[] = { 1, 3, 6, 3, 2, 3, 6, 8, 9, 5 };
        int n = arr.length;
        System.out.print("Minimum number of jumps to reach end is " + minJumps(arr, 0, n - 1));
    }

    private static int minJumps(int[] arr, int l, int h) {
        if (l == h) {
            return 0;
        }
        if (arr[l] == 0) {
            return Integer.MAX_VALUE;
        }

        int dp[] = new int[arr.length];
        dp[0] = 0;
        for (int i = 1; i < arr.length; i++) {
            dp[i] = Integer.MAX_VALUE;
            for (int j = 0; j < i; j++) {
                if (i <= j + arr[j] && dp[j] != Integer.MAX_VALUE) {
                    dp[i] = Math.min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[arr.length - 1];
    }
}
