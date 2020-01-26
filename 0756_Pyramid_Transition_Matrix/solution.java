package cn.huang.leetcode;

import java.util.*;

/*
756. Pyramid Transition Matrix

 We are stacking blocks to form a pyramid. Each block has a color which is a one letter string, like `'Z'`.

For every block of color `C` we place not in the bottom row, we are placing it on top of a left block of color `A` and right block of color `B`. We are allowed to place the block there only if `(A, B, C)` is an allowed triple.

We start with a bottom row of bottom, represented as a single string. We also start with a list of allowed triples allowed. Each allowed triple is represented as a string of length 3.

Return true if we can build the pyramid all the way to the top, otherwise false.

Example 1:

Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
Output: true
Explanation:
We can stack the pyramid like this:
    A
   / \
  D   E
 / \ / \
X   Y   Z

This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.

Example 2:

Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
Output: false
Explanation:
We can't stack the pyramid to the top.
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.

Note:

    bottom will be a string with length in range [2, 8].
    allowed will have length in range [0, 200].
    Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.

 */
public class LC_0756_PyramidTransitionMatrix {
    private Map<Integer, Set<Character>> map;

    public boolean pyramidTransition(String bottom, List<String> allowed) {
        map = new HashMap<>();
        for (String s : allowed) {
            int key = buildKey(s.charAt(0), s.charAt(1));
            map.putIfAbsent(key, new HashSet<>());
            map.get(key).add(s.charAt(2));
        }
        return helper(bottom, new StringBuilder());
    }

    private boolean helper(String bottom, StringBuilder nextBottom) {
        if (bottom.length() == 1) {
            return true;
        }
        if (nextBottom.length() == bottom.length() - 1) {
            return helper(nextBottom.toString(), new StringBuilder());
        }
        int key = buildKey(bottom.charAt(nextBottom.length()), bottom.charAt(nextBottom.length() + 1));
        if (!map.containsKey(key)) {
            return false;
        }
        for (char c : map.get(key)) {
            nextBottom.append(c);
            if (helper(bottom, nextBottom)) {
                return true;
            }
            nextBottom.deleteCharAt(nextBottom.length() - 1);
        }
        return false;
    }

    private int buildKey(char a, char b) {
        return (1 << a - 'A') | (1 << b - 'A' + 10);
    }
}
