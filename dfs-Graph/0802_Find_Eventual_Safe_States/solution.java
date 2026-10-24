package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*

802. Find Eventual Safe States

 */
public class LC_0802_FindEventualSafeStates {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        // 0: 没有 color
        // 1 : safe
        // 2 : unsafe

        // 默认都是 没有颜色的
        int[] colors = new int[graph.length];
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < graph.length; i++) {
            if (dfs(graph, i, colors)) {
                res.add(i);
            }
        }
        return res;
    }

    public boolean dfs(int[][] graph, int node, int[] colors) {
        // 如果 这点已经有颜色了
        if (colors[node] != 0) {
            return colors[node] == 1; // 看他是否 safe
        }
        // 先把这点 置为不安全，只有他的后继节点都安全， 才把他置为安全
        colors[node] = 2;
        for (int color_next : graph[node]) {
            if (!dfs(graph, color_next, colors)) {
                return false;
            }
        }
        colors[node] = 1;
        return true;
    }
}
