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