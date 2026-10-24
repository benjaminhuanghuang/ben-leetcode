package cn.huang.leetcode;

import java.util.*;

/*
684. Redundant Connection

 */
public class LC_0684_RedundantConnection {
    public int[] findRedundantConnection_DFS(int[][] edges) {
        HashMap<Integer, List<Integer>> graph  = new HashMap<>();

        for(int[] edge : edges)
        {
            int start = edge[0];
            int end = edge[1];

            HashSet<Integer> visited = new HashSet<>();
            if(hasPath(start, end, graph, visited))
            {
                return edge;
            }
            if(!graph.containsKey(start))
                graph.put(start, new ArrayList<Integer>());
            graph.get(start).add(end);

            if(!graph.containsKey(end))
                graph.put(end, new ArrayList<Integer>());
            graph.get(end).add(start);
        }
        return null;
    }

    private boolean hasPath(int start, int end, HashMap<Integer, List<Integer>> graph, HashSet<Integer> visited)
    {
        if(start == end)
            return true;

        visited.add(start);
        if(!graph.containsKey(start) || !graph.containsKey(end))
            return false;
        for(int next: graph.get(start)) {
            if (visited.contains(next))
                continue;

            if (hasPath(next, end, graph, visited))
                return true;
        }
        return false;
    }
    //http://www.noteanddata.com/leetcode-684-Redundant-Connection-java-union-find-solution.html

    public int[] findRedundantConnection(int[][] edges) {
        UnionFind uf = new UnionFind(edges.length);
        for (int i = 0; i < edges.length; ++i) {
            int from = edges[i][0] - 1;
            int to = edges[i][1] - 1;
            if (uf.root(from) == uf.root(to)) {
                return new int[]{from + 1, to + 1};
            }
            uf.union(from, to);
        }
        return null;
    }


    static class UnionFind {
        private int[] ids;

        public UnionFind(int n) {
            this.ids = new int[n];
            for (int i = 0; i < ids.length; ++i) {
                ids[i] = i;
            }
        }

        public int root(int i) {
            while (ids[i] != i) {
                i = ids[i];
            }
            return i;
        }

        public void union(int i, int j) {
            int rooti = root(i);
            int rootj = root(j);
            ids[rootj] = rooti;
        }

        public boolean find(int i, int j) {
            return root(i) == root(j);
        }
    }

    public int[] findRedundantConnection_2(int[][] edges) {
        //        unionfind
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < edges.length; i++) {
            int[] edge = edges[i];
            int i1 = unionFind(map, edge[0]);
            int i2 = unionFind(map, edge[1]);
            if (i1 == i2) {
                return edge;
            }
            map.put(i1, i2);
        }
        return null;
    }

    // find root
    private int unionFind(Map<Integer, Integer> map, int i) {
        while (true) {
            Integer va = map.get(i);
            if (va == null) {
                return i;
            } else {
                i = va;
            }
        }
    }
}
