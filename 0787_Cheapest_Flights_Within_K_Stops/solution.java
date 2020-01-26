package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/*
787. Cheapest Flights Within K Stops

There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to
find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.

Example 2:
Input:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.

Note:

    The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
    The size of flights will be in range [0, n * (n - 1) / 2].
    The format of each flight will be (src, dst, price).
    The price of each flight will be in the range [1, 10000].
    k is in the range of [0, n - 1].
    There will not be any duplicated flights or self cycles.


 */
public class LC_0787_CheapestFlightsWithinKStops {
    // 时间复杂度：O(K * m) //m 是 number of flights
    // 空间复杂度：O(K * n) //可以优化到O(2n),每次维护两行即可
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        int[][] dp = new int[K + 1][n];
        Arrays.fill(dp[0], Integer.MAX_VALUE);
        dp[0][src] = 0;
        for (int[] flight : flights) {
            if (flight[0] == src) {
                dp[0][flight[1]] = flight[2];
            }
        } // System.out.println(Arrays.toString(dp[0]));
        for (int i = 1; i <= K; i++) {
            dp[i] = Arrays.copyOf(dp[i - 1], n);
            for (int[] flight : flights) {
                if (dp[i - 1][flight[0]] != Integer.MAX_VALUE)
                    dp[i][flight[1]] = Math.min(dp[i][flight[1]], dp[i - 1][flight[0]] + flight[2]);
            } // System.out.println(Arrays.toString(dp[i]));
        }
        if (dp[K][dst] == Integer.MAX_VALUE) return -1;
        return dp[K][dst];
    }

    /*
    https://www.youtube.com/watch?v=PLY-lbcxEjg
     */
    HashMap<Integer, List<int[]>> g = new HashMap<>();
    int ans = Integer.MAX_VALUE;

    public int findCheapestPrice2(int n, int[][] flights, int src, int dst, int K) {
        for (int[] e : flights) {
            if (!g.containsKey(e[0]))
                g.put(e[0], new ArrayList<>());
            g.get(e[0]).add(new int[]{e[1], e[2]});
        }

        int[] visited = new int[n];
        visited[src] = 1;

        dfs(src, dst, K + 1, 0, visited);

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    void dfs(int src, int dst, int k, int cost, int[] visited) {
        if (src == dst) {
            ans = cost;
            return;
        }

        if (k == 0)
            return;

        if (g.containsKey(src)) {
            for (int[] p : g.get(src)) {
                if (visited[p[0]] == 1)
                    continue;
                if (cost + p[1] > ans)
                    continue;
                visited[p[0]] = 1;
                dfs(p[0], dst, k - 1, cost + p[1], visited);
                visited[p[0]] = 0;
            }
        }
    }
}
