package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
    290. Word Pattern
 */
public class LC_0290_WordPattern {
    public boolean wordPattern(String pattern, String str) {
        Map<Character, String> map = new HashMap<>();
        int length = pattern.length();
        String[] arr = str.split(" ");
        if (length != arr.length)
            return false;

        for (int i = 0; i < length; i++) {
            char c = pattern.charAt(i);
            if (map.containsKey(c)) {
                if (!map.get(c).equals(arr[i])) {
                    return false;
                }
            } else {
                if(map.containsValue(arr[i]))
                    return false;
                map.put(c, arr[i]);
            }
        }
        return true;
    }
}
