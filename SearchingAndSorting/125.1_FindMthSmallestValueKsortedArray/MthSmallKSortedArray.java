/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class GFG {

    // A class to store the row and column of current array. This will help us to
    // identify the Node value belongs to which array, so that we can insert the
    // next element from the same array
    public static class Node {
        int row;
        int col;
        int value;

        public Node(int row, int col, int value) {
            this.row = row;
            this.col = col;
            this.value = value;
        }

    }

    // This function takes an array of arrays as an
    // argument and all arrays are assumed to be
    // sorted. It returns m-th smallest element in
    // the array obtained after merging the given
    // arrays.
    public static int mThLargest(int[][] arr, int m) {
        int k = arr.length;

        // Create a min heap with k heap nodes. Every
        // heap node has first element of an array
        // The order is based on the value field of the node.
        PriorityQueue<Node> pq = new PriorityQueue<>(k, (a, b) -> a.value - b.value);

        // insert the first elements of all the arrays
        for (int i = 0; i < k; i++) {
            pq.add(new Node(i, 0, arr[i][0]));
        }

        // Now one by one get the minimum element
        // from min heap and replace it with next
        // element of its array
        int count = 0;
        int row = 0;
        int col = 0;
        while (count < m && !pq.isEmpty()) {
            // pop the top element which will be the minimum
            Node popped = pq.poll();
            row = popped.row;
            col = popped.col;

            // add next from same row only if the element popped out is not the last element
            // in that row
            if (col + 1 < arr[row].length)
                pq.add(new Node(row, col + 1, arr[row][col + 1]));

            // count++
            count++;

        }

        return arr[row][col];

    }

    // Driver program to test above functions
    public static void main(String[] args) {
        int[][] matrix = { { 2, 6, 12 }, { 1, 9 }, { 23, 34, 90, 2000 } };
        int m = 4;

        System.out.println(mThLargest(matrix, m));
    }
}
