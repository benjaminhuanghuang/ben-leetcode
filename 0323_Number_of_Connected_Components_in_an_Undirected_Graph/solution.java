package cn.huang.leetcode;

import java.util.Arrays;

/*
323. Number of Connected Components in an Undirected Graph

 Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write
 a function to find the number of connected components in an undirected graph.

Example 1:

     0          3
     |          |
     1 --- 2    4

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:

     0           4
     |           |
     1 --- 2 --- 3

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same
as [1, 0] and thus will not appear together in edges.


 */

/*
Union Find的题，find加union之后，roots为-1的是它的根，有几个根就有几个union。
root数组，下标和节点值相同，此时root[i]表示节点i属于group i，我们初始化了n个部分 (res = n)，
假设开始的时候每个节点都属于一个单独的区间，然后我们开始遍历所有的edge，对于一条边的两个点，他们起始时在root中的值不相同，
这时候我们我们将结果减1，表示少了一个区间，然后更新其中一个节点的root值，使两个节点的root值相同，
那么这样我们就能把连通区间的所有节点的root值都标记成相同的值，不同连通区间的root值不相同，这样也能找出连通区间的个数。
 */
public class LC_0323_NumberofConnectedComponentsinanUndirectedGraph {
    /*
    https://blog.csdn.net/qq508618087/article/details/50874303

     */
    public int countComponents(int n, int[][] edges) {
        int[] roots = new int[n];
        for(int i =0; i < n; i++)
            roots[i] = i;

        for (int[] edge: edges) {
            int start = edge[0];
            int end = edge[1];
            while(roots[start] != start)
                start = roots[start];
            while(roots[end] != end)
                end = roots[end];
            if(start != end) {
                roots[end] = start;
                n--;
            }
           }

        return n;
    }

   /*
        https://zhuhan0.blogspot.com/2017/03/leetcode-323-number-of-connected.html
        The idea is to think of each connected component as a tree.
        As we iterate through the edges, we set one of the node as the parent node of the other and decrement n.
        This process is called union, which essentially adds the nodes into the tree they belong to.
        Before we can union two nodes, we need to check if they are already on the same tree, in order not to decrement
        n by mistake. This can be done by comparing the two root nodes of the trees the nodes belong to.

    */
    public int countComponents1(int n, int[][] edges) {
        int[] roots = new int[n];

        for (int i = 0; i < n; i++) {
            roots[i] = i;
        }

        for (int i = 0; i < edges.length; i++) {
            int r1 = find(roots, edges[i][0]);
            int r2 = find(roots, edges[i][1]);
            //check if they are already on the same tree.
            //comparing the two root nodes of the trees the nodes belong to.
            if (r1 != r2) {
                roots[r1] = r2;
                n--;
            }
        }

        return n;
    }
    private int find(int[] roots, int key) {
        while (roots[key] != key) {
            key = roots[key];
        }

        return key;
    }
}