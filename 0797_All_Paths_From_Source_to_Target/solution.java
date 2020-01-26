package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

/*

797. All Paths From Source to Target

Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.
graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []]
Output: [[0,1,3],[0,2,3]]
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

 */
public class LC_0797_AllPathsFromSourcetoTarget {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        return solve(graph, 0);
    }


    public List<List<Integer>> solve(int[][] graph, int node) {
        int N = graph.length;
        List<List<Integer>> ans = new ArrayList();

        if (node == N - 1) {
            List<Integer> path = new ArrayList();
            path.add(N - 1);
            ans.add(path);
            return ans;
        }

        for (int neighbor : graph[node]) {
            for (List<Integer> path : solve(graph, neighbor)) {
                path.add(0, node);
                ans.add(path);
            }
        }
        return ans;
    }

    public List<List<Integer>> allPathsSourceTarget2(int[][] graph) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        path.add(0);
        dfs(graph, path, ans);
        return ans;
    }

    void dfs(int[][] graph, List<Integer> path, List<List<Integer>> ans) {
        if (path.get(path.size() - 1) == graph.length - 1) {
            ans.add(path);
            return;
        }

        for (int next : graph[path.get(path.size() - 1)]) {
            List<Integer> newPath = new ArrayList(path);
            newPath.add(next);
            dfs(graph, newPath, ans);
        }
    }
}
