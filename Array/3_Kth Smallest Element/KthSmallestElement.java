public class KthSmallestElement {
    public static int kthSmallest(int[] arr, int l, int r, int k) {

        while (l <= r) {
            int slow = l;
            int fast = l;
            int pivot = r;

            while (fast < pivot) {
                if (arr[fast] < arr[pivot]) {
                    int temp = arr[fast];
                    arr[fast] = arr[slow];
                    arr[slow] = temp;
                    slow++;
                }
                fast++;
            }

            int temp = arr[slow];
            arr[slow] = arr[pivot];
            arr[pivot] = temp;

            if (k - 1 == slow) {
                return arr[k - 1];
            } else if (k - 1 > slow) {
                l = slow + 1;
            } else {
                r = slow - 1;
            }
        }
        return -1;

    }

    public static void main(String[] args) {
        int arr[] = { 7, 3, 9, 2, 5, 0, 1 };
        System.out.println(kthSmallest(arr, 0, 6, 6));
    }
}

// 1 2 3 8 5 6 7 4