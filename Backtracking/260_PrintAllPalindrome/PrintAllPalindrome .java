import java.util.ArrayList;

class PrintAllPalindrome {
    // Driver program
    public static void main(String[] args) {
        String input = "nitin";

        System.out.println("All possible palindrome" + "partions for " + input + " are :");

        allPalPartitions(input);
    }

    public static void allPalPartitions(String input) {
        int n = input.length();

        ArrayList<ArrayList<String>> allPal = new ArrayList<>();
        ArrayList<String> currPal = new ArrayList<>();

        allPalPartitonsUtil(allPal, currPal, 0, n, input);

        for (ArrayList<String> l : allPal) {
            for (String s : l) {
                System.out.print(s + " ");
            }
            System.out.println();
        }
    }

    public static void allPalPartitonsUtil(ArrayList<ArrayList<String>> allPal, ArrayList<String> currPal, int start,
            int end, String input) {

        if (start >= end) {
            allPal.add(new ArrayList<>(currPal));
        }

        for (int i = start; i < end; i++) {
            if (isPalindrome(input, start, i)) {
                currPal.add(input.substring(start, i + 1));
                allPalPartitonsUtil(allPal, currPal, i + 1, end, input);
                currPal.remove(currPal.size() - 1);
            }
        }

    }

    public static boolean isPalindrome(String input, int start, int end) {
        while (start < end) {
            if (input.charAt(start) != input.charAt(end)) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
}