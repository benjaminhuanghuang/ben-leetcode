package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
887. Super Egg Drop

You are given K eggs, and you have access to a building with N floors from 1 to N.

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break,
and any egg dropped at or below floor F will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N).

Your goal is to know with certainty what the value of F is.

What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?



Example 1:

Input: K = 1, N = 2
Output: 2
Explanation:
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.

Example 2:

Input: K = 2, N = 6
Output: 3

Example 3:

Input: K = 3, N = 14
Output: 4



Note:

    1 <= K <= 100
    1 <= N <= 10000


 */
public class LC_0887_SuperEggDrop {
    /*
    https://leetcode.com/problems/super-egg-drop/discuss/173895/Simple-intuition-w-Java-solution-(7ms).
     */
    public int superEggDrop(int K, int N) {
        if (N <= 0) {
            return 1;
        }
        if (K <= 1) {
            return N;
        }
        List<List<Integer>> nodes = new ArrayList<>();
        // Initialize DP table for K = 1
        for (int k = 0; k < K - 1; k++) {
            List<Integer> list = new ArrayList<>();
            list.add(1);
            nodes.add(list);
        }
        int level = 0; // Current level
        int sum = 1; // Total number of nodes in the K-Tree up to current level
        while (sum < N) {
            nodes.get(0).add(nodes.get(0).get(level) + 1);
            for (int k = 1; k < K - 1; k++) {
                nodes.get(k).add(nodes.get(k - 1).get(level) + nodes.get(k).get(level));
            }
            level++;
            sum += nodes.get(K - 2).get(level);
        }
        return level + 1;
    }
}
