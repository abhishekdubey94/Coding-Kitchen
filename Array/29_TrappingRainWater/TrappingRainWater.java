public class TrappingRainWater {
    // arr: input array
    // n: size of array
    // Function to find the trapped water between the blocks.
    static int trappingWater(int arr[], int n) {

        int maxLeft[] = new int[n];
        int maxRight[] = new int[n];
        int max = 0;
        for (int i = 0; i < n; i++) {
            maxLeft[i] = Math.max(max, arr[i]);
            max = maxLeft[i];
        }
        max = 0;
        for (int i = n - 1; i >= 0; i--) {
            maxRight[i] = Math.max(max, arr[i]);
            max = maxRight[i];
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += Math.min(maxRight[i], maxLeft[i]) - arr[i];
        }
        return sum;
    }
}
