package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
310. Minimum Height Trees


 */
public class LC_0310_MinimumHeightTrees {
    /*
    建立一个图g，是一个二维数组，其中g[i]是一个一维数组，保存了i节点可以到达的所有节点。
    我们开始将所有只有一个连接边的节点(叶节点)都存入到一个队列queue中，然后我们遍历每一个叶节点，通过图来找到和其相连的节点，
    并且在其相连节点的集合中将该叶节点删去，如果删完后此节点也也变成一个叶节点了，加入队列中，再下一轮删除。
    那么我们删到什么时候呢，当节点数小于等于2时候停止，此时剩下的一个或两个节点就是我们要求的最小高度树的根节点啦，
     */
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> leaves = new ArrayList<>();
        if (n == 1)
        {
            leaves.add(0);
            return leaves;
        }

        List<Set<Integer>> graph = new ArrayList<>(n);
        for (int i = 0; i < n; ++i)
            graph.add(new HashSet<>());

        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        for (int i = 0; i < n; ++i) {
            if (graph.get(i).size() == 1)
                leaves.add(i);
        }
        while (n > 2) {
            n -= leaves.size();
            List<Integer> newLeaves = new ArrayList<>();
            for (int i : leaves) {
                int t = graph.get(i).iterator().next();
                graph.get(t).remove(i);
                if (graph.get(t).size() == 1)
                    newLeaves.add(t);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
}
