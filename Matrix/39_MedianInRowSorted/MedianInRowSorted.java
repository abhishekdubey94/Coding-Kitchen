import java.lang.reflect.Array;
import java.util.Arrays;

public class MedianInRowSorted {
    static int binaryMedian(int m[][], int r, int c) {

        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (int i = 0; i < r; i++) {
            min = Math.min(min, m[i][0]);
            max = Math.max(max, m[i][c - 1]);
        }

        int desired = (r * c + 1) / 2;
        while (min < max) {
            int mid = min + (max - min) / 2;

            int get = 0, place = 0;

            // count the number of elements less than this number
            // if the number of elements is less than mid are less than N/2, it means median
            // lies on right side, so move min to mid+1 and continue;
            for (int i = 0; i < r; i++) {
                get = Arrays.binarySearch(m[i], mid);
                // If element is not found in the array the
                // binarySearch() method returns
                // (-(insertion_point) - 1). So once we know
                // the insertion point we can find elements
                // Smaller than the searched element by the
                // following calculation

                if (get < 0) {
                    get = Math.abs(get) - 1;
                } else {
                    // If element is found in the array it returns
                    // the index(any index in case of duplicate). So we go to last
                    // index of element which will give the number of
                    // elements smaller than the number including
                    // the searched element.
                    while (get < c && m[i][get] == mid) {
                        get += 1;
                    }
                }

                place = place + get;

            }

            if (place < desired) {
                min = mid + 1;
            } else {
                max = mid;
            }
        }

        return min;
    }

    public static void main(String[] args) {
        int r = 3, c = 3;
        int m[][] = { { 1, 3, 5 }, { 2, 6, 9 }, { 3, 6, 9 } };

        System.out.println("Median is " + binaryMedian(m, r, c));
    }
}
