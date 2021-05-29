public class ValidShuffle {
    // check if result string is valid shuffle of string first and second
    static boolean shuffleCheck(String first, String second, String result) {
        int l1 = first.length();
        int l2 = second.length();
        int l3 = result.length();
        if (l1 + l2 != l3) {
            return false;
        }
        int i = 0;
        int j = 0;

        for (int k = 0; k < l3; k++) {
            if (i < l1 && first.charAt(i) == result.charAt(k)) {
                i++;
            } else if (j < l2 && second.charAt(j) == result.charAt(k)) {
                j++;
            } else {
                return false;
            }
        }
        if (i < l1 | j < l2) {
            return false;
        }
        return true;
    }

    public static void main(String[] args) {

        String first = "XY";
        String second = "12";
        String[] results = { "1XY2", "Y12X" };

        // call the method to check if result string is
        // shuffle of the string first and second
        for (String result : results) {
            if (shuffleCheck(first, second, result) == true) {
                System.out.println(result + " is a valid shuffle of " + first + " and " + second);
            } else {
                System.out.println(result + " is not a valid shuffle of " + first + " and " + second);
            }
        }
    }
}
