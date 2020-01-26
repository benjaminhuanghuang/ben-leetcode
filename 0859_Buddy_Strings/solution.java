package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashMap;

/*
 859	 Buddy Strings
 */
public class LC_0859_BuddyStrings {
    public boolean buddyStrings(String A, String B) {
        if (A.length() != B.length())
            return false;
        int diff = 0;
        ArrayList<Integer> diffIndex = new ArrayList<>();

        for (int i = 0; i < A.length(); i++) {
            char a = A.charAt(i);
            char b = B.charAt(i);
            if (a != b) {
                diff++;
                diffIndex.add(i);
            }
        }
        if (diff == 0) {
            // A ==B, any same chars in A
            HashMap<Character, Boolean> map = new HashMap<>();
            for (char a : A.toCharArray()) {
                if (map.containsKey(a)) {
                    return true;
                } else {
                    map.put(a, true);
                }
            }

        }
        if (diff != 2)
            return false;

        return A.charAt(diffIndex.get(0)) == B.charAt(diffIndex.get(1)) &&
                A.charAt(diffIndex.get(1)) == B.charAt(diffIndex.get(0));
    }
}
