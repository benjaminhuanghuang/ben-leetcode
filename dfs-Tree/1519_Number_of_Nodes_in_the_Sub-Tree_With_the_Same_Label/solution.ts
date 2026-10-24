/*
1519. Number of Nodes in the Sub-Tree With the Same Label

https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
*/

import { TreeNode } from "../Common/TreeNode";

/*
https://www.youtube.com/watch?v=FgLmFu_OwNA
*/
function countSubTrees(n: number, edges: number[][], labels: string): number[] {
  // create a graph
  const graph: number[][] = Array.from({ length: n }, () => []);
  for (let edge of edges) {
    graph[edge[0]].push(edge[1]);
    graph[edge[1]].push(edge[0]);
  }

  const res: number[] = new Array(n).fill(0);
  const visited: boolean[] = new Array(n).fill(false);
  // 在每个节点上，记录每个字母各自出现的次数
  const times: number[] = new Array(26).fill(0);

  function dfs(
    graph: number[][],
    res: number[],
    visited: boolean[],
    times: number[],
    labels: string,
    curr: number
  ): void {
    if (visited[curr]) {
      return;
    }
    visited[curr] = true;
    const currChar = labels[curr].charCodeAt(0) - "a".charCodeAt(0);
    const curr_times = times[currChar]++;
    for (let next of graph[curr]) {
      dfs(graph, res, visited, times, labels, next);
    }
    // 当前节点的字母出现的次数 - 之前的次数
    res[curr] = times[currChar] - curr_times;
  }

  dfs(graph, res, visited, times, labels, 0);

  return res;
}

/*
https://zxi.mytechroad.com/blog/tree/leetcode-1519-number-of-nodes-in-the-sub-tree-with-the-same-label/#google_vignette

Solution: Post order traversal + hashtable
For each label, record the count. When visiting a node, we first record the current count of its label as before, and traverse its children, when done, increment the current count, ans[i] = current – before.

Time complexity: O(n)
Space complexity: O(n)

*/
function countSubTrees2(
  n: number,
  edges: number[][],
  labels: string
): number[] {
  return [];
}
