/*
261. Graph Valid Tree
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Hint:

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two 
vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, 
[0, 1] is the same as [1, 0] and thus will not appear together in edges.

*/
using System.Collections.Generic;

/*
    https://segmentfault.com/a/1190000005687618

想象一开始这个图只有顶点，没有边，我们来一条一条的添加边。
每遇到一条边，判断这边的两个端点是否在同一个集合里？集合的property:表示一个连通分量，里面的任意两点有且只有一条路径可达

在的话，表示有环：因为两个点在一个集合里就表示这两个点已经有一条路径了，现在再加一条路径，必然构成环。
不在的话，表示不构成环，我们应该合并这两个集合：因为加上这条边，两个集合就被连起来了，合并成了一个集合
 */
public class Solution261
{
    public bool validTree(int n, int[][] edges)
    {
        HashSet<int> visited = new HashSet<int>();

        List<List<int>> adjList = new List<List<int>>();
        for (int i = 0; i < n; ++i)
            adjList.Add(new List<int>());

        // for (int[] edge: edges)
        // {
        //     adjList.get(edge[0]).add(edge[1]);
        //     adjList.get(edge[1]).add(edge[0]);
        // }
        // if (hasCycle(-1, 0, visited, adjList))  // has cycle?
        //     return false;
        // if (visited.size() != n) // is all connected?
        //     return false;
        return true;
    }

    private bool hasCycle(int pred, int vertex, HashSet<int> visited, List<List<int>> adjList)
    {
        // visited.Add(vertex);  // current vertex is being visited
        // foreach (int succ in adjList[vertex])
        // {  // successors of current vertex
        //     if (!succ.equals(pred))
        //     {  // exclude current vertex's predecessor
        //         if (visited.contains(succ))
        //         {
        //             return true; // back edge/loop detected!
        //         }
        //         else
        //         {
        //             if (hasCycle(vertex, succ, visited, adjList))
        //             {
        //                 return true;
        //             }
        //         }
        //     }
        // }
        return false;
    }
}