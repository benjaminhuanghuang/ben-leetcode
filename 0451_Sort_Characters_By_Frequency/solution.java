package cn.huang.leetcode;

import java.util.*;

/*
451. Sort Characters By Frequency
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

 */
public class LC_0451_SortCharactersByFrequency {
    public String frequencySort(String s) {
        HashMap<Character, Integer> charFreqMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            charFreqMap.put(c, charFreqMap.getOrDefault(c, 0) + 1);
        }
        ArrayList<Map.Entry<Character, Integer>> list = new ArrayList<>(charFreqMap.entrySet());
        list.sort(new Comparator<Map.Entry<Character, Integer>>(){
            public int compare(Map.Entry<Character, Integer> o1, Map.Entry<Character, Integer> o2) {
                return o2.getValue().compareTo(o1.getValue());
            }
        });

        StringBuffer sb = new StringBuffer();
        for (Map.Entry<Character, Integer> e : list) {
            for (int i = 0; i < e.getValue(); i++) {
                sb.append(e.getKey());
            }
        }
        return sb.toString();
    }

    public String frequencySort_2(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0)+1);
        }

        PriorityQueue<Map.Entry<Character, Integer>> queue = new PriorityQueue<>((a, b)->b.getValue()-a.getValue());
        queue.addAll(map.entrySet());

        StringBuilder sb = new StringBuilder();
        while (!queue.isEmpty()) {
            Map.Entry entry = queue.poll();
            for (int i = 0; i < (int)entry.getValue(); i++)
                sb.append(entry.getKey());
        }

        return sb.toString();
    }
}
