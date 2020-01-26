package cn.huang.leetcode;

import java.util.HashMap;

public class LC_0914_XofKindInDeckofCards {

    // Input   [1,1,2,2,2,2]
    // Output  false
    // Expect  true
    public boolean hasGroupsSizeX_wrong(int[] deck) {
        if (deck == null || deck.length <= 1) {
            return false;
        }

        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int i = 0; i < deck.length; i++) {
            int curr = deck[i];
            if (map.containsKey(curr)) {
                map.put(curr, map.get(curr) + 1);
            } else {
                map.put(curr, 1);
            }
        }

        int count = -1;

        for(Integer key: map.keySet()) {

            if(count == -1)
            {
                count = map.get(key);
            }
            else
            {
                if(count != map.get(key))
                {
                    return false;
                }
            }
        }

        return true;
    }

    public boolean hasGroupsSizeX(int[] deck) {
        if (deck == null || deck.length <= 1) {
            return false;
        }

        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int i = 0; i < deck.length; i++) {
            int curr = deck[i];
            if (map.containsKey(curr)) {
                map.put(curr, map.get(curr) + 1);
            } else {
                map.put(curr, 1);
            }
        }

        int gcd = 0;
        for(Integer key: map.keySet()) {
            gcd = findGCDOfTwoNumbers(map.get(key), gcd);
        }

        return gcd >= 2;
    }

    public static int findGCDOfTwoNumbers (int a, int b) {
        if (b == 0) {
            return a;
        }
        return findGCDOfTwoNumbers(b, a%b);
    }
}
