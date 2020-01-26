package cn.huang.leetcode;
/*
771. Jewels and Stones
 */
import java.util.HashMap;

public class LC_0771_JewelsAndStones {
    public int numJewelsInStones_Slow(String J, String S) {
        if (J == null || S == null)
            return 0;
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < J.length(); i++) {
            char c = J.charAt(i);
            map.put(c, 0);
        }

        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            if (map.containsKey(c))
                map.put(c, map.get(c) + 1);
        }

        int num = 0;
        for (char key : map.keySet()) {
            num += map.get(key);
        }

        return num;
    }

    public int numJewelsInStones(String J, String S) {
        if (J == null || S == null)
            return 0;

        int num = 0;
        for (int i = 0; i < J.length(); i++) {
            char c1 = J.charAt(i);
            for (int j = 0; j < S.length(); j++) {
                char c2 = S.charAt(j);
                if (c1 == c2)
                    num++;
            }
        }

        return num;
    }
}
