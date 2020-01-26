package cn.huang.leetcode;

import java.util.Arrays;
import java.util.Stack;

/*
    943. Find the Shortest Superstring
    Given an array A of strings, find any smallest string that contains each string in A as a substring.

    We may assume that no string in A is substring of another string in A.

    Example 1:

    Input: ["alex","loves","leetcode"]
    Output: "alexlovesleetcode"

    Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
    Example 2:

    Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
    Output: "gctaagttcatgcatc"
 */
public class LC_0943_FindtheShortestSuperstring {

    /*
    Hua hua https://zxi.mytechroad.com/blog/searching/leetcode-943-find-the-shortest-superstring/
    Search, DFS/Backtracking, Try all permutation
    Time O(n!)
    Space O(n)
     */
    int[][] g;
    int[] best_path;
    int best_len;

    public String shortestSuperstring(String[] A) {
        int n = A.length;
        best_path = new int[n];
        g = new int[n][n];    // g[i][j] 表示把单词j放在单词i后面产生的cost
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = A[j].length();
                for (int k = 1; k <= Math.min(A[i].length(), A[j].length()); k++) {
                    if (A[i].substring(A[i].length() - k) == A[j].substring(0, k))
                        g[i][j] = A[j].length() - k;
                }
            }
        }
        int[] path = new int[n];
        int best_len = Integer.MAX_VALUE;
        dfs(A, 0, 0, 0, path);
        String ans = A[best_path[0]];
        for (int k = 1; k < best_path.length; ++k) {
            int i = best_path[k - 1];
            int j = best_path[k];
            ans += A[j].substring(A[j].length() - g[i][j]);
        }
        return ans;

    }

    void dfs(String[] A, int d, int used, int cur_len, int[] path) {
        if (cur_len >= best_len)
            return;
        if (d == A.length) {
            best_len = cur_len;
            best_path = path;
            return;
        }

        for (int i = 0; i < A.length; ++i) {
            if ((used & (1 << i)) > 0)
                continue;
            path[d] = i;
            dfs(A, d + 1, used | (1 << i), d == 0 ? A[i].length() : cur_len + g[path[d - 1]][i], path);
        }
    }

    /*

    graph[i][j] means the length of string to append when A[i] followed by A[j]. eg. A[i] = abcd, A[j] = bcde, then graph[i][j] = 1
    Then the problem becomes to: find the shortest path in this graph which visits every node exactly once. This is a Travelling Salesman Problem.
    Apply TSP DP solution. Remember to record the path.

     */
    public String shortestSuperstring_dp(String[] A) {
        int n = A.length;
        int[][] graph = new int[n][n];
        // build the graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = calc(A[i], A[j]);
                graph[j][i] = calc(A[j], A[i]);
            }
        }
        int[][] dp = new int[1 << n][n];
        int[][] path = new int[1 << n][n];
        int last = -1, min = Integer.MAX_VALUE;

        // start TSP DP
        for (int i = 1; i < (1 << n); i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    int prev = i - (1 << j);
                    if (prev == 0) {
                        dp[i][j] = A[j].length();
                    } else {
                        for (int k = 0; k < n; k++) {
                            if (dp[prev][k] < Integer.MAX_VALUE && dp[prev][k] + graph[k][j] < dp[i][j]) {
                                dp[i][j] = dp[prev][k] + graph[k][j];
                                path[i][j] = k;
                            }
                        }
                    }
                }
                if (i == (1 << n) - 1 && dp[i][j] < min) {
                    min = dp[i][j];
                    last = j;
                }
            }
        }

        // build the path
        StringBuilder sb = new StringBuilder();
        int cur = (1 << n) - 1;
        Stack<Integer> stack = new Stack<>();
        while (cur > 0) {
            stack.push(last);
            int temp = cur;
            cur -= (1 << last);
            last = path[temp][last];
        }

        // build the result
        int i = stack.pop();
        sb.append(A[i]);
        while (!stack.isEmpty()) {
            int j = stack.pop();
            sb.append(A[j].substring(A[j].length() - graph[i][j]));
            i = j;
        }
        return sb.toString();
    }

    private int calc(String a, String b) {
        for (int i = 1; i < a.length(); i++) {
            if (b.startsWith(a.substring(i))) {
                return b.length() - a.length() + i;
            }
        }
        return b.length();
    }
}


/*
["ift","efd","dnete","tef","fdn"]
Output:
"iftdnetefdn"
Expected:
"iftefdnete"
 */