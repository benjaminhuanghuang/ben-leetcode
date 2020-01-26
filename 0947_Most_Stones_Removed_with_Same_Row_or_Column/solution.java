package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
947. Most Stones Removed with Same Row or Column

On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?



Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5

Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3

Example 3:

Input: stones = [[0,0]]
Output: 0



Note:

    1 <= stones.length <= 1000
    0 <= stones[i][j] < 10000


 */
public class LC_0947_MostStonesRemovedwithSameRoworColumn {
    int count = 0;
    public int removeStones(int[][] stones) {
        Map<String, String> parent = new HashMap<>();
        count = stones.length;
        // init Union Find
        for (int[] stone : stones) {
            String s = stone[0] + " " + stone[1];
            parent.put(s, s);
        }
        for (int[] s1 : stones) {
            String ss1 = s1[0] + " " + s1[1];
            for (int[] s2 : stones) {
                if (s1[0] == s2[0] || s1[1] == s2[1]) { // in the same column or row
                    String ss2 = s2[0] + " " + s2[1];
                    union(parent, ss1, ss2);
                }
            }
        }
        return stones.length - count;
    }
    private void union(Map<String, String> parent, String s1, String s2) {
        String r1 = find(parent, s1), r2 = find(parent, s2);
        if (r1.equals(r2)) {
            return;
        }
        parent.put(r1, r2);
        count--;
    }
    private String find(Map<String, String> parent, String s) {
        if (!parent.get(s).equals(s)) {
            parent.put(s, find(parent, parent.get(s)));
        }
        return parent.get(s);
    }
}
