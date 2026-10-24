/*
399. Evaluate Division

https://leetcode.com/problems/evaluate-division/

Note: x/x is -1 if x is not in the graph
*/

/*
HuaHua: Graph + DFS
https://www.youtube.com/watch?v=UwpvInpgFmo

有向图，每两个节点之间的边有权重，
两个数的运算结果等于两个节点之间的路径的权重之乘积

Time complexity: O(E + Q*E)   E is the number of equations and Q is the number of queries
Space complexity: O(E)
*/

// key: Start node, value: {key: End node, value: weight}
// g[A][B] = k means A / B = k
type Graph = { [key: string]: { [key: string]: number } };

function calcEquation(
  equations: [string, string][],
  values: number[],
  queries: [string, string][]
): number[] {
  const g: Graph = {};

  // Build the graph
  for (let i = 0; i < equations.length; ++i) {
    const [A, B] = equations[i];
    const k = values[i];
    if (!g[A]) g[A] = {};
    if (!g[B]) g[B] = {};
    g[A][B] = k;
    g[B][A] = 1.0 / k;
  }

  // Process each query
  const ans: number[] = [];
  for (const [X, Y] of queries) {
    if (!g[X] || !g[Y]) {
      ans.push(-1.0);
      continue;
    }
    const visited: Set<string> = new Set();
    ans.push(divide(X, Y, g, visited));
  }
  return ans;
}

// DFS to find the path from A to B, get result of A / B
function divide(A: string, B: string, g: Graph, visited: Set<string>): number {
  if (A === B) return 1.0;
  visited.add(A);

  for (const C in g[A]) {
    if (visited.has(C)) continue;
    const d = divide(C, B, g, visited); // d = C / B
    // A / B = C / B * A / C
    // The path A - C - B exist
    // from A to B is the path from A to C + the path from C to B
    if (d > 0) return d * g[A][C];
  }

  return -1.0;
}

export {};
