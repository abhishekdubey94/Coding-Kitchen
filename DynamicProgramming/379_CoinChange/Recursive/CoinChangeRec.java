public class CoinChangeRec {

    public static int coinChangeWays(int coins[], int m, int N) {
        if (N == 0) {
            return 1;
        }

        if (N < 0) {
            return 0;
        }

        if (m == 0 && N != 0) {
            return 0;
        }

        return coinChangeWays(coins, m - 1, N) + coinChangeWays(coins, m, N - coins[m - 1]);
    }

    public static void main(String[] args) {
        int coins[] = { 1, 2, 3 };
        int m = coins.length;
        int N = 4;
        System.out.println(coinChangeWays(coins, m, N));
    }
}


//                             C({1,2,3}, 5)                     
//                            /             \    
//                          /                 \                  
//              C({1,2,3}, 2)                 C({1,2}, 5)
//             /       \                      /      \         
//            /         \                    /         \   
// C({1,2,3}, -1)  C({1,2}, 2)        C({1,2}, 3)    C({1}, 5)
//                /    \             /     \           /     \
//              /       \           /       \         /        \
//     C({1,2},0)  C({1},2)   C({1,2},1) C({1},3)    C({1}, 4)  C({}, 5)
//                    / \     / \        /\         /     \         
//                   /   \   /   \     /   \       /       \  
//                 .      .  .     .   .     .   C({1}, 3) C({}, 4)
//                                                / \ 
//                                               /   \   
//                                              .      .