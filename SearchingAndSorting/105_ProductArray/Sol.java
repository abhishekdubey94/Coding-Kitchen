class Solution {
    public static long[] productExceptSelf(int arr[], int n) {
        long[] result = new long[n];
        result[0] = 1;
        for (int i = 1; i < n; i++) {
            result[i] = arr[i - 1] * result[i - 1];
        }
        long prod = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            result[i] = result[i] * prod;
            prod *= arr[i];
        }

        return result;
    }
}