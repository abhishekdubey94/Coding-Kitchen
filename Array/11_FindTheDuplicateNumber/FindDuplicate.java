public class FindDuplicate {

    public static int findDuplicate(int nums[]) {
        int n = nums.length;
        int sum = n * (n - 1) / 2;
        int realSum = 0;
        for (int i = 0; i < n; i++) {
            realSum += nums[i];
        }
        return realSum - sum;
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4, 7, 5, 6, 7 };
        System.out.println(findDuplicate(arr));
    }
}
