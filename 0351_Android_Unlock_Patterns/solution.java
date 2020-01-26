package cn.huang.leetcode;
/*
    351. Android Unlock Patterns

    Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9,
    moves the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:

    Each pattern must connect at least m keys and at most n keys.
    All the keys must be distinct.
    If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
    The order of keys used matters.


 */

/*
有9个数字键，如果密码的长度范围在[m, n]之间，问所有的解锁模式共有多少种，
注意非法的滑动模式:
首先1不能直接到3，必须经过2，同理的有4到6，7到9，1到7，2到8，3到9，还有就是对角线必须经过5，例如1到9，3到7等。
我们建立一个二维数组jumps，用来记录两个数字键之间是否有中间键，然后再用一个一位数组visited来记录某个键是否被访问过，然后我们用递归来解，
我们先对1调用递归函数，在递归函数中，我们遍历1到9每个数字next，然后找他们之间是否有jump数字，如果next没被访问过，
并且jump为0，或者jump被访问过，我们对next调用递归函数。
数字1的模式个数算出来后，由于1,3,7,9是对称的，所以我们乘4即可
然后再对数字2调用递归函数，2,4,6,9也是对称的，再乘4，
最后单独对5调用一次，然后把所有的加起来就是最终结果了：
 */
public class LC_0351_AndroidUnlockPatterns {
    private int[][] jumps;
    private boolean[] visited;

    public int numberOfPatterns(int m, int n) {
        jumps = new int[10][10];
        jumps[1][3] = jumps[3][1] = 2;
        jumps[4][6] = jumps[6][4] = 5;
        jumps[7][9] = jumps[9][7] = 8;
        jumps[1][7] = jumps[7][1] = 4;
        jumps[2][8] = jumps[8][2] = jumps[1][9] = jumps[9][1] = 5;
        jumps[9][3] = jumps[3][9] = 6;
        jumps[3][7] = jumps[7][3] = 5;
        visited = new boolean[10];
        int count = 0;
        count += dfs(1, 1, 0, m, n) * 4;//1,3,7,9 are symmetric, so we only need to use 1 to do it once and then multiply the result by 4
        count += dfs(2, 1, 0, m, n) * 4;//2,4,6,8 are symmetric, so we only need to use 1 to do it once and then multiply the result by 4
        count += dfs(5, 1, 0, m, n);
        return count;
    }

    private int dfs(int num, int len, int count, int m, int n) {
        if (len >= m) {
            count++;
        }
        len++;
        if (len > n) {
            return count;
        }
        visited[num] = true;
        for (int next = 1; next <= 9; next++) {
            int jump = jumps[num][next];
            if (!visited[next] && (jump == 0 || visited[jump])) {
                count = dfs(next, len, count, m, n);
            }
        }
        visited[num] = false;//backtracking
        return count;
    }
}
