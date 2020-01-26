/*
310. Minimum Height Trees

For a undirected graph with tree characteristics, we can choose any node as the root. The result 
graph is then a rooted tree. 
Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). 
Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a 
list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] 
is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]

Hint:

How many MHTs can a graph have at most?
*/
using System.Collections.Generic;

//https://www.hrwhisper.me/leetcode-minimum-height-trees/
public class Solution310 {
    //我们要的是中间结点，沿着树的外围每次把叶子结点砍掉，那么，最后剩下的不就是中间结点了么？
    // 让蚂蚁从各个叶子往中间爬，每次爬一步之后，丢弃上一个叶子节点，并且判断此时哪些成为了叶子节点，然后继续爬，
    // 直到最后蚂蚁相遇或者差一步就是最长的一个距离了。最后，蚂蚁的位置就是根的位置。
    //http://www.voidcn.com/blog/niuooniuoo/article/p-6082436.html
    public IList<int> FindMinHeightTrees(int n, int[,] edges) {
        if (n == 1) 
        {
            return new List<int>(){0};
        }

        List<int> leaves = new List<int>();
        // List[i] contains all nodes connected to node i 
		List<HashSet<int>> graph = new List<HashSet<int>>();
        for (int i = 0; i < n; i++) 
            graph.Add(new HashSet<int>());

        // Build the Graph
        for (int i = 0; i < edges.GetLength(0); i++) {
		//for (int i = 0; i < n; i++) {    // Error!
 			graph[edges[i,0]].Add(edges[i,1]);
            graph[edges[i,1]].Add(edges[i,0]);
		}

        // Find all leaves, leaf node has only one neighbor
		for (int i = 0; i < n; i++) 
            if (graph[i].Count == 1) 
                leaves.Add(i);

		/**从叶子开始遍历所有节点*/
		while (n > 2) {
			List<int> newLeaves = new List<int>();
			foreach (var leaf in leaves)
				foreach (int j in graph[leaf]) { // node j connected to leaf
					graph[j].Remove(leaf);  // cut leaf from node j 
					if (graph[j].Count == 1) { //找到下个叶子节点
						newLeaves.Add(j);
					}
				}
			n -= leaves.Count;
			leaves = newLeaves;
		}
		return leaves;
    }
}