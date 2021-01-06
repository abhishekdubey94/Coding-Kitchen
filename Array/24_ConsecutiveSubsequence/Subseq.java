class Subseq {
    // arr[] : the input array
    // N : size of the array arr[]

    // return the length of the longest subsequene of consecutive integers
    static int findLongestConseqSubseq(int arr[], int N) {
        int globalMax = 0;
        int localMax = 0;
        HashSet<Integer> set = new HashSet<Integer>();

        for (int i : arr) {
            set.add(i);
        }

        for (int i : set) {
            if (!set.contains(i - 1)) {
                int t = i;
                while (set.contains(t)) {
                    localMax++;
                    t++;
                }
                if (globalMax < localMax) {
                    globalMax = localMax;
                }
            }
            localMax = 0;
        }

        return globalMax;
    }
}