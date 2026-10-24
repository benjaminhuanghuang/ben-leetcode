package cn.huang.leetcode;

import java.util.*;

/*
133. Clone Graph  [138]

 */
public class LC_0133_CloneGraph {

    // Definition for undirected graph.
    class UndirectedGraphNode {
        int label;
        List<UndirectedGraphNode> neighbors;

        UndirectedGraphNode(int x) {
            label = x;
            neighbors = new ArrayList<UndirectedGraphNode>();
        }
    }

    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (node == null)
            return null;

        // Clone the start node
        UndirectedGraphNode newNode = new UndirectedGraphNode(node.label);
        HashMap<UndirectedGraphNode, UndirectedGraphNode> visited = new HashMap<>();
        visited.put(node, newNode);

        Queue<UndirectedGraphNode> queue = new LinkedList<>();
        queue.offer(node);

        while (!queue.isEmpty()) {
            UndirectedGraphNode originalNode = queue.poll();
            List<UndirectedGraphNode> neighbors = originalNode.neighbors;

            for (UndirectedGraphNode neighbour : neighbors) {
                if (!visited.containsKey(neighbour)) {
                    // this neighbour is not copied/processed yet
                    UndirectedGraphNode newTmpNode = new UndirectedGraphNode(neighbour.label);
                    visited.put(neighbour, newTmpNode);
                    queue.offer(neighbour);
                }
                // add neighbor, visited.get(originalNode) is cloned node of originalNode,
                visited.get(originalNode).neighbors.add(visited.get(neighbour));
            }
        }
        return newNode;
    }

}
