package cn.huang.leetcode;

/*
	884	 Uncommon Words from Two Sentences
    We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

    A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

    Return a list of all uncommon words.

    You may return the list in any order.
 */


import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class LC_0884_UncommonWordsfrom2Sentences {
    public String[] uncommonFromSentences(String A, String B) {
        String[] wordsA = A.split(" ");
        String[] wordsB = B.split(" ");

        HashMap<String, Integer> map = new HashMap<>();

        for(String w: wordsA)
        {
            if(map.containsKey(w))
            {
                map.put(w, map.get(w)+1);
            }
            else
            {
                map.put(w, 1);
            }
        }

        for(String w: wordsB)
        {
            if(map.containsKey(w))
            {
                map.put(w, map.get(w)+1);
            }
            else
            {
                map.put(w, 1);
            }
        }

        List<String> l = new ArrayList<>();

        for(String w: map.keySet())
        {
            if(map.get(w) == 1){
                l.add(w);
            }
        }

        return l.toArray(new String[l.size()]);

    }
}
