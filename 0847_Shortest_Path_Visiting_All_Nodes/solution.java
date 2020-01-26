package cn.huang.leetcode;

import java.util.LinkedList;
import java.util.Queue;

/*
847. Shortest Path Visiting All Nodes

An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.

graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes i and j are connected.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may
revisit nodes multiple times, and you may reuse edges.



Example 1:

Input: [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]

Example 2:

Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]



Note:

    1 <= graph.length <= 12
    0 <= graph[i].length < graph.length


 */


/*
https://www.youtube.com/watch?v=Vo3OEN2xgwk
 */
public class LC_0847_ShortestPathVisitingAllNodes {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        // 采用 入队列时判断 的BFS做法，因此需要处理一下起始情况。
        if (n <= 1) {
            return 0;
        }

        Queue<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[n][1 << n];
        // 可以选择任意点作为起点，因此开始时需要将所有的节点都 add 到队列中
        for (int i = 0; i < n; i++) {
            queue.offer(new int[]{i, 1 << i});
            visited[i][1 << i] = true;
        }
        // 采用二进制记录状态信息
        int target = (1 << n) - 1;

        int step = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] curr = queue.poll();
                int pos = curr[0], state = curr[1];

                for (int neigh : graph[pos]) {
                    int nextState = state | (1 << neigh);
                    if (nextState == target) {
                        return step + 1;
                    }
                    if (visited[neigh][nextState]) {
                        continue;
                    }
                    visited[neigh][nextState] = true;
                    queue.offer(new int[]{neigh, state | (1 << neigh)});
                }
            }
            step++;
        }

        return -1;
    }
}
