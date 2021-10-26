package findAllAnagramsInAString_438;

import java.util.ArrayList;
import java.util.List;

class FindAllAnagramsInAString {
    public static void main(String[] args) {
        String s = "abbab";
        String p = "ab";
        System.out.println(findAnagrams(s,p));
    }

    public static List<Integer> findAnagrams(String s, String p) {
        List<Integer> list = new ArrayList<>();

        int[] hash = new int[26];

        for (char c : p.toCharArray()) {
            hash[c - 'a']++;
        }

        int left = 0, right = 0, count = p.length();

        while (right < s.length()) {

            if (hash[s.charAt(right++) - 'a']-- >= 1) count--;

            if (count == 0) list.add(left);

            if (right - left == p.length() && hash[s.charAt(left++) - 'a']++ >= 0) count++;
        }

        return list;
    }
}