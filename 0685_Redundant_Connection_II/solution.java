package cn.huang.leetcode;

/*
685. Redundant Connection II

 In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:

Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3

Example 2:

Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3

Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
 */
public class LC_0685_RedundantConnection_II {
    private static final int N = 1000;

    public int[] findRedundantDirectedConnection(int[][] edges) {
// 因为可能有节点存在两个父亲节点，此时答案必定在这两条边之中
        int[] candidate1 = new int[]{-1, -1};
        int[] candidate2 = new int[]{-1, -1};
        // 记录各个节点的父亲节点
        int[] parent = new int[N + 1];
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            // 如果节点 v 的父亲不唯一，则记录下两个可能的答案
            if (parent[v] != 0) {
                candidate1 = new int[]{parent[v], v};
                candidate2 = new int[]{u, v};
                // 无效化第二条边 (trick)
                edge[0] = -1;
                edge[1] = -1;
            }
            parent[v] = u;
        }

        // Do Union Find
        UnionFind uf = new UnionFind(N);
        for (int[] edge : edges) {
            // 如果遇到被无效化的边直接跳过
            if (edge[0] == -1 && edge[1] == -1) {
                continue;
            }
            if (!uf.union(edge[0], edge[1])) {
                // 如果在无效化了第二条边之后（存在的话）
                // 仍然遇到了环，那么要么是无重复父亲节点，由该条边产生
                // 要么是 存在重复父亲节点，并且由 第一条边 产生
                return candidate1[0] == -1 ? edge : candidate1;
            }
        }

        // 对应 Case2.1 与 Case2.2
        return candidate2;
    }

    class UnionFind {
        int[] parent, rank;

        UnionFind(int N) {
            parent = new int[N + 1];
            rank = new int[N + 1];
            for (int i = 1; i <= N; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        public int compressedFind(int index) {
            if (index != parent[index]) {
                parent[index] = compressedFind(parent[index]);
            }
            return parent[index];
        }

        public boolean union(int a, int b) {
            int aFather = compressedFind(a);
            int bFather = compressedFind(b);
            if (aFather == bFather) {
                return false;
            }
            if (rank[aFather] < rank[bFather]) {
                parent[aFather] = bFather;
                rank[bFather] += rank[aFather];
            } else {
                parent[bFather] = aFather;
                rank[aFather] += rank[bFather];
            }
            return true;
        }
    }
}
