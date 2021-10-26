package word_break;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class WordBreakAllPossible {

	public static void main(String[] args) {
		String s = "catsanddog";
		String[] dict = {"cats", "cat", "and", "sand", "dog"};
		int n = 5;
		
		List<String> ans = new ArrayList<>();
		HashSet<String> dic = new HashSet<>();
		for(String t : dict) {
			dic.add(t);
		}
		wordBreak(ans,s,dic,"");
		
		System.out.println(ans);

	}

	private static void wordBreak(List<String> ans, String s, HashSet<String> dic,String currWord) {
		if(s.isEmpty()) {
			ans.add(currWord.trim());
			return;
		}
		for(int i=1;i<=s.length();i++) {
			String test = s.substring(0,i);
			if(dic.contains(test)) {
				wordBreak(ans,s.substring(i, s.length()),dic,currWord+" "+test);
			}
		}
		
	}

}