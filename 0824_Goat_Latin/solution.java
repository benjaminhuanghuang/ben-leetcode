package cn.huang.leetcode;

import java.util.HashSet;
import java.util.Set;

/*
    824	Goat Latin

 */
public class LC_0824_GoatLatin {
    public String toGoatLatin(String S) {
        // vowel
        Set<Character> vowel = new HashSet<>();
        for (char c : new char[]{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}) {
            vowel.add(c);
        }

        int t = 1;
        StringBuilder ans = new StringBuilder();
        for (String word : S.split("\\s")) {
            char first = word.charAt(0);
            if (vowel.contains(first)) {
                ans.append(word);
            } else {
                // remove first letter
                ans.append(word.substring(1));
                // append first letter
                ans.append(word.substring(0, 1));
            }
            ans.append("ma");

            for (int i = 0; i < t; i++) {
                ans.append('a');
            }
            ans.append(" ");
            t++;
        }
        // delete last " "
        ans.deleteCharAt(ans.length() - 1);
        return ans.toString();
    }
}
