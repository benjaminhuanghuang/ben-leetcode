package cn.huang.leetcode;
/*
488. Zuma Game

Think about Zuma Game. You have a row of balls on the table, colored red(R), yellow(Y), blue(B), green(G), and white(W). You also have several balls in your hand.

Each time, you may choose a ball in your hand, and insert it into the row (including the leftmost place and rightmost place). Then, if there is a group of 3 or more balls in the same color touching, remove these balls. Keep doing this until no more balls can be removed.

Find the minimal balls you have to insert to remove all the balls on the table. If you cannot remove all the balls, output -1.

Examples:

Input: "WRRBBW", "RB"
Output: -1
Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW

Input: "WWRRBBWW", "WRBRW"
Output: 2
Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty

Input:"G", "GGGGG"
Output: 2
Explanation: G -> G[G] -> GG[G] -> empty

Input: "RBYYBBRRB", "YRBGB"
Output: 3
Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty

Note:

    You may assume that the initial row of balls on the table won’t have any 3 or more consecutive balls with the same color.
    The number of balls on the table won't exceed 20, and the string represents these balls is called "board" in the input.
    The number of balls in your hand won't exceed 5, and the string represents these balls is called "hand" in the input.
    Both input strings will be non-empty and only contain characters 'R','Y','B','G','W'.

 */

import java.util.HashMap;
import java.util.Map;

/*
根据当前手上求球的颜色, 每次消除桌面上相同颜色的球, 然后递归, 直到桌面上没球了或者手上没球了. 最后统计当桌面上没球的时候, 花费球的数量.
 */
public class LC_0488_ZumaGame {
    int min = Integer.MAX_VALUE;
    Map<Character, Integer> map = new HashMap<Character, Integer>();

    public int findMinStep(String board, String hand) {
        for (char c : "RYBGW".toCharArray()) map.put(c, 0);
        for (char c : hand.toCharArray()) map.put(c, 1 + map.get(c));
        min = hand.length() + 1;
        dfs(board, 0);
        return min == hand.length() + 1 ? -1 : min;
    }

    private void dfs(String board, int step) {
        if (step >= min) return;
        if ("".equals(board)) {
            min = Math.min(min, step);
            return;
        }

        for (int i = 0; i < board.length(); i++) {
            int j = i + 1;
            while (j < board.length() && board.charAt(j) == board.charAt(i))
                j++;
            int needToDismiss = 3 - (j - i);
            char c = board.charAt(i);
            if (map.get(c) >= needToDismiss) {
                map.put(c, map.get(c) - needToDismiss);
                dfs(process(board.substring(0, i) + board.substring(j)), step + needToDismiss);
                map.put(c, map.get(c) + needToDismiss);
            }
        }
    }

    public String process(String s) {
        while (true) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < s.length(); i++) {
                int j = i + 1;
                while (j < s.length() && s.charAt(j) == s.charAt(i))
                    j++;
                if (j - i < 3) sb.append(s.substring(i, j));
                i = j - 1;    // i++还会加回去
            }

            if (s.equals(sb.toString())) break;
            s = sb.toString();
        }

        return s;
    }
}
