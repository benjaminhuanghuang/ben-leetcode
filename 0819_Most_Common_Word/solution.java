package cn.huang.leetcode;

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

/*
    819	 Most Common Word

    Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.
    It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

    Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not
    case sensitive.  The answer is in lowercase.


 */
public class LC_0819_MostCommonWord {
    public String mostCommonWord(String paragraph, String[] banned) {
        HashSet<String> set = new HashSet<>(Arrays.asList(banned));
        HashMap<String, Integer> map = new HashMap<>();
        // Good!
        String[] ps = paragraph.toLowerCase().split("[^a-z]");

        for (String p : ps) {
            if ("".equals(p)) {
                continue;
            }
            if (!set.contains(p)) {
                if (map.containsKey(p)) {
                    map.put(p, map.get(p) + 1);
                } else {
                    map.put(p, 1);
                }
            }
        }
        int max = 0;
        String mcw = "";
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            if (entry.getValue() > max) {
                max = entry.getValue();
                mcw = entry.getKey();
            }
        }
        return mcw;
    }
}
