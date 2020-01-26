/*
133. Clone Graph

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

*/
using System.Linq;
using System.Collections.Generic;

public class UndirectedGraphNode {
      public int label;
      public IList<UndirectedGraphNode> neighbors;
      public UndirectedGraphNode(int x) { label = x; neighbors = new List<UndirectedGraphNode>(); }
};


public class Solution133 {
    
    Dictionary<int, UndirectedGraphNode> dict = new Dictionary<int, UndirectedGraphNode>();
    // DFS solution   
    public UndirectedGraphNode CloneGraph(UndirectedGraphNode node) {
        if (node == null) return null;
        if (dict.ContainsKey(node.label))
        {
            return dict[node.label];
        }

        var newnode = new UndirectedGraphNode(node.label);
        dict.Add(node.label, newnode);
        foreach (var neighbor in node.neighbors)
        {
            newnode.neighbors.Add(CloneGraph(neighbor));
        }

        return newnode;
    }

    // BFS solution
    Dictionary<UndirectedGraphNode, UndirectedGraphNode> dict2 = new Dictionary<UndirectedGraphNode, UndirectedGraphNode>();
    public UndirectedGraphNode CloneGraph2(UndirectedGraphNode node)
    {
        if (node == null) return null;
        var queue = new Queue<UndirectedGraphNode>();
        queue.Enqueue(node);
        
        var newnode = new UndirectedGraphNode(node.label);
        dict2.Add(node, newnode);
        while (queue.Any())
        {
            var top = queue.Dequeue();
            foreach (var neighbor in top.neighbors)
            {
                if (dict2.ContainsKey(neighbor))
                {
                    dict2[top].neighbors.Add(dict2[neighbor]);
                }
                else
                {
                    var newneighbor = new UndirectedGraphNode(neighbor.label);
                    dict2.Add(neighbor, newneighbor);
                    dict2[top].neighbors.Add(newneighbor);
                    queue.Enqueue(neighbor);
                }
            }
        }

        return newnode;
    }

}