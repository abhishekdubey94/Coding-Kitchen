public class KnapsackRec {

    public static int maxVal(int W, int[] weight, int values[], int n) {

        if (n == 0 || W <= 0) {
            return 0;
        }
        if (weight.length == 0) {
            return 0;
        }

        if (weight[n - 1] > W) {
            return maxVal(W, weight, values, n - 1);
        }

        // if we take the weight
        return Math.max((values[n - 1] + maxVal(W - weight[n - 1], weight, values, n - 1)),
                maxVal(W, weight, values, n - 1));
    }

    public static void main(String[] args) {

        int values[] = { 60, 100, 120 };
        int weight[] = { 10, 20, 30 };
        int W = 50;

        System.out.println(maxVal(W, weight, values, 3));
    }
}


// wt[] = {1, 1, 1}, W = 2, val[] = {10, 20, 30}
//                        K(n, W)
//                        K(3, 2)  
//                    /            \ 
//                  /                \               
//             K(2, 2)                  K(2, 1)
//           /       \                  /    \ 
//         /           \              /        \
//        K(1, 2)      K(1, 1)        K(1, 1)     K(1, 0)
//        /  \         /   \              /        \
//      /      \     /       \          /            \
// K(0, 2)  K(0, 1)  K(0, 1)  K(0, 0)  K(0, 1)   K(0, 0)