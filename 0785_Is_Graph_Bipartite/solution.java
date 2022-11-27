package cn.huang.leetcode;

import java.util.Arrays;

/*
785. Is Graph Bipartite?

 */
public class LC_0785_IsGraphBipartite {
    public boolean isBipartite(int[][] graph) {
        // -1: Haven't been colored.
        // 0: Blue.
        // 1: Red.
        int n = graph.length;
        int[] colors = new int[n];
        Arrays.fill(colors, -1);

        for (int i = 0; i < n; i++) {              //This graph might be a disconnected graph. So check each unvisited node.
            if (colors[i] == -1 && !validColor(graph, colors, 0, i)) {
                return false;
            }
        }
        return true;
    }

    public boolean validColor(int[][] graph, int[] colors, int color, int node) {
        if (colors[node] != -1) {
            return colors[node] == color;
        }
        colors[node] = color;
        for (int next : graph[node]) {
            // change color to fill the adjacent nodes
            if (!validColor(graph, colors, 1 - color, next)) {
                return false;
            }
        }
        return true;
    }
}
