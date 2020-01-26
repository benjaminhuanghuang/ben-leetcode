package cn.huang.leetcode;

/*
834. Sum of Distances in Tree

An undirected, connected tree with N nodes labelled 0...N-1 and N-1 edges are given.

The ith edge connects nodes edges[i][0] and edges[i][1] together.

Return a list ans, where ans[i] is the sum of the distances between node i and all other nodes.

Example 1:

Input: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation:
Here is a diagram of the given tree:
  0
 / \
1   2
   /|\
  3 4 5
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.  Hence, answer[0] = 8, and so on.

 */


import java.util.ArrayList;
import java.util.List;

/*
题意：给出一棵树，求出树上每个节点到其他节点的距离总和。

题解：每个节点保存两个值，一个是其子树的节点个数（包括自身节点也要计数）nodesum[ ]，一个是其子树各点到它的距离 dp[ ]，
那么我们假设根节点为 u ，其仅有一个儿子 v ， u 到 v 的距离为 1 ，而 v 有若干儿子节点，那么 dp[v] 表示 v 的子树各点到 v 的距离和，
那么各个节点到达 u 的距离便可以这样计算： dp[u] = dp[v] + nodesum[ v ] *1; （式子的理解，v 的一个儿子节点为 f，那么 f
到达 u 的距离为  (sum[ f ->v] + sum [v- > u])*1 ，dp[v] 包含了 sum[f->v]*1，所以也就是式子的分配式推广到各个子节点计算出来的和）。
我们已经知道了各个节点到达根节点的距离和，那么从根节点开始递推下来可以得到各个点的距离和。另开一个数组表示每个节点的到其他节点的距离和，
那么对于根节点u来说， dissum[u] = dp[u]。以 u 的儿子 v 为例， v 的子节点到 v 不必经过 v->u 这条路径，因此 dissum[u] 多了
 nodesum[v] * 1，但是对于不是 v 的子节点的节点，只到达了 u ，因此要到达 v 必须多走 u->v 这条路径，因此 dissum[u] 少了 ( N - nodesum[v] ) * 1) ,所以 dissum[v] = dissum[u] - nodesum[v] * 1 + (N - nodesum[v] ) * 1，按照这个方法递推下去就可以得到各个点的距离和


　　样例：N为6，边为[[0,1],[0,2],[2,3],[2,4],[2,5]]，输出[8,12,6,10,10,10]。
解题思路

　　比较简单的一道题目，暴力解决N方，其实每个点的距离和可以由相邻点得到，减去这一侧的点数加上另一侧的点数即可。
　　因此可以先O(N)
算出某个点的距离和，再逐个往外算出每个点的距离和，每个点仅需O(1)

就能得到，当然要先预处理出这一侧所有点的个数。
复杂度分析

　　时间复杂度为O(N)
。
　　空间复杂度为O(N)。
 */
public class LC_0834_SumofDistancesinTree {
    public int[] sumOfDistancesInTree(int N, int[][] edges) {
        if (N == 1) {
            return new int[N];
        }
        if (N == 2) {
            return new int[]{1, 1};
        }

        List<int[]>[] graph = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < edges.length; i++) {
            // [0] = to  [1] = sum  [2] = num
            graph[edges[i][0]].add(new int[]{edges[i][1], 0, 0});
            graph[edges[i][1]].add(new int[]{edges[i][0], 0, 0});
        }

        int[] result = new int[N];
        boolean[] seen = new boolean[N];
        for (int i = 0; i < N; i++) {
            result[i] = dfs(graph, i, seen)[0];
        }
        return result;
    }

    private int[] dfs(List<int[]>[] graph, int i, boolean[] seen) {
        seen[i] = true;
        int sum = 0;
        int num = 1;
        for (int[] adj : graph[i]) {
            if (!seen[adj[0]]) {
                if (adj[1] == 0 && adj[2] == 0) {
                    int[] res = dfs(graph, adj[0], seen);
                    adj[1] = res[0];
                    adj[2] = res[1];
                }
                sum += (adj[1] + adj[2]);
                num += adj[2];
            }
        }
        seen[i] = false;
        return new int[]{sum, num};
    }
}
