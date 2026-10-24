/*
2642. Design Graph With Shortest Path Calculator

https://leetcode.com/problems/design-graph-with-shortest-path-calculator/
*/

/*
https://github.com/wisdompeak/LeetCode/tree/master/Graph/2642.Design-Graph-With-Shortest-Path-Calculator

Approach: Floyd-Warshall Algorithm
Time complexity: O(N^3)

根据题意，我们要时刻准备返回任意两点之间的最短路径，因此Dijkstra算法是不行的。
Dijkstra 用于求一个点到其他所有点的最短路径，而Floyd算法用于求任意两点之间的最短路径。
想求任意两点之间的最短路径，最经典的算法就是Floyd算法了，而o(N^3)的时间复杂度也是可以接受的
*/
class Graph {
  private n: number;
  private dp: number[][];

  constructor(n: number, edges: number[][]) {
    this.n = n;
    this.dp = Array.from({ length: n }, () => Array(n).fill(Infinity));

    // Initialize the dp matrix
    for (let i = 0; i < n; i++) {
      this.dp[i][i] = 0;
    }

    // Populate the dp matrix with edge weights
    for (const edge of edges) {
      this.dp[edge[0]][edge[1]] = edge[2];
    }

    // Apply Floyd-Warshall algorithm
    for (let k = 0; k < n; k++) {
      for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
          this.dp[i][j] = Math.min(
            this.dp[i][j],
            this.dp[i][k] + this.dp[k][j]
          );
        }
      }
    }
  }

  addEdge(edge: number[]) {
    const [a, b, weight] = edge;
    for (let i = 0; i < this.n; i++) {
      for (let j = 0; j < this.n; j++) {
        this.dp[i][j] = Math.min(
          this.dp[i][j],
          this.dp[i][a] + weight + this.dp[b][j]
        );
      }
    }
  }

  shortestPath(node1: number, node2: number): number {
    const ret = this.dp[node1][node2];
    return ret === Infinity ? -1 : ret;
  }
}
