/*
797. All Paths From Source to Target

https://leetcode.com/problems/all-paths-from-source-to-target/
*/

function allPathsSourceTarget(graph: number[][]): number[][] {
  const ans: number[][] = [];
  const path: number[] = [0]; // path starts from 0

  function dfs(graph: number[][], path: number[], ans: number[][]): void {
    // last node in the path is the target
    if (path[path.length - 1] === graph.length - 1) {
      ans.push([...path]);
      return;
    }

    for (const next of graph[path[path.length - 1]]) {
      path.push(next);
      dfs(graph, path, ans);
      path.pop();
    }
  }

  dfs(graph, path, ans);
  return ans;
}
