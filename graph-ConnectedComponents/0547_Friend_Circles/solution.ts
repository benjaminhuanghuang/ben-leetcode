/*
547. Number of Provinces

https://leetcode.com/problems/number-of-provinces/
*/

/*
Huahua: Connected Components
https://www.youtube.com/watch?v=HHiHno66j40

在无向图中找出连通分量的个数
Time Complexity: O(N^2)
Space Complexity: O(N)

Give a node, find the maximum connected components 
and mark all nodes as visited

200. Number of Islands
*/
function findCircleNum(isConnected: number[][]): number {
  if (isConnected.length === 0) return 0;
  const n = isConnected.length;
  let ans = 0;
  const visited = Array(n).fill(false);

  for (let i = 0; i < n; ++i) {
    if (visited[i]) continue;
    dfs(isConnected, i, n, visited); // mark all friends as visited
    ++ans;
  }
  return ans;
}

// Curr is the center of the connected components
function dfs(
  isConnected: number[][],
  curr: number,
  n: number,
  visited: boolean[]
): void {
  if (visited[curr]) return;
  visited[curr] = true;

  // Visit all friends (neighbors)
  for (let i = 0; i < n; ++i) {
    if (isConnected[curr][i] === 1 && !visited[i])
      // Mark as visited
      dfs(isConnected, i, n, visited);
  }
}

/*
    Cut of the visit element instead of marking it as visited
*/
function findCircleNum2(isConnected: number[][]): number {
  if (isConnected.length === 0) return 0;
  const n = isConnected.length;
  let ans = 0;

  for (let i = 0; i < n; ++i) {
    if (isConnected[i][i] === 0) continue;
    ++ans;
    dfs2(isConnected, i, n);
  }
  return ans;
}

function dfs2(isConnected: number[][], curr: number, n: number): void {
  // Visit all friends (neighbors)
  for (let i = 0; i < n; ++i) {
    if (isConnected[curr][i] === 0) continue;
    isConnected[curr][i] = isConnected[i][curr] = 0; // Mark as visited
    dfs2(isConnected, i, n);
  }
}
