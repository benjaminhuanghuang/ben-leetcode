package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/*

49. Group Anagrams

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.


 */
public class LC_0049_GroupAnagrams {
    /*
    Time O(m * n * logN), space O(n)

     */

    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<>();
        if(strs == null || strs.length ==0)
            return res;

        HashMap<String, Integer> map = new HashMap<>(); // string, index

        for(String s: strs)
        {
            char[] ch = s.toCharArray();
            Arrays.sort(ch);
            String k = new String(ch);
            if(map.containsKey(k))
            {
                List<String> list = res.get(map.get(k));
                list.add(s);
            }
            else
            {
                List<String> list = new ArrayList<>();
                list.add(s);
                map.put(k, res.size());
                res.add(list);
            }
        }
        return res;
    }

    /*
    Time O(m * n), space O(n)

     */

    public List<List<String>> groupAnagrams2(String[] strs) {

        HashMap<String, List<String>> map = new HashMap<>();

        for(String str: strs)
        {
            int[] count = new int[26];
            for(Character ch : str.toCharArray())
            {
                count[ch - 'a']++;
            }
            String s = "";
            for(int i = 0; i < count.length; i++)
            {
                if(count[i] != 0){
                    s += String.valueOf(count[i] + String.valueOf((char)(i + 'a')));
                }
            }
            if(map.containsKey(s))
            {
                List<String> list = map.get(s);
                list.add(str);
            }
            else
            {
                List<String> list = new ArrayList<>();
                list.add(str);
                map.put(s, list);
            }
        }

        return new ArrayList<>(map.values());
    }
}
