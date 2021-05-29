import java.util.Arrays;

public class MinimizeDifference {

    // Modifies the array by subtracting/adding
    // k to every element such that the difference
    // between maximum and minimum is minimized
    static int getMinDiff(int arr[], int n, int k) {
        if (n == 1) {
            return 0;
        }

        Arrays.sort(arr);

        // initial max differnce
        int ans = arr[n - 1] - arr[0];

        // add to lowest value and subtracting from high value to minimize the diff
        int small = arr[0] + k;
        int big = arr[n - 1] - k;

        int tem = 0;
        // In case, small becomes larger than big value or big value becomes smaller
        // than small value, we need to interchange
        if (big < small) {
            tem = big;
            big = small;
            small = tem;
        }

        // as we have already found the difference for the first number and the last
        // number, start from the 1 index to n-1 index
        for (int i = 1; i < n - 1; i++) {
            int sub = arr[i] - k;
            int add = arr[i] + k;

            // if sub is greater than small then it means the smallest value is still
            // 'small'
            // and as we need to minimize the difference between smallest and the largest
            // value.
            // incase sub is less than small, it will increase the difference and out
            // objective is to minimize the diff.
            // we have to select small value. Similarly add is smaller than the big value,
            // we will select the larger value.
            if (sub >= small || add <= big) {
                continue;
            }

            // In case of sub is less than small AND add is greater than the big, we need to
            // choose one of them.
            // As we have to minimize the difference, we have to go with the combination
            // which gives min value of differnce.
            if (big - sub <= add - small) {
                small = sub;
            } else {
                big = add;
            }
        }
        return Math.min(ans, big - small);

    }

    public static void main(String[] args) {
        int arr[] = { 4, 6 };
        int n = arr.length;
        int k = 10;
        System.out.println("Maximum difference is " + getMinDiff(arr, n, k));
    }
}
