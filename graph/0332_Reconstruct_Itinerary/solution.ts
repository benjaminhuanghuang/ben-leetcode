/*
332. Reconstruct Itinerary

https://leetcode.com/problems/reconstruct-itinerary/
*/

/*
Approach: directed graph， Greedy: sort children + post order traversal

https://zxi.mytechroad.com/blog/graph/leetcode-332-reconstruct-itinerary/
https://www.youtube.com/watch?v=4udFSOWQpdg

Time Complexity: O(n+e)
Space: O(n+e).
*/
function findItinerary(tickets: string[][]): string[] {
  // src -> {dst1, dest2, ..., destn}
  const graph: Map<string, string[]> = new Map(); // the directed graph
  // the answer
  const route: string[] = [];

  // Create directed graph(adjacency list)
  for (const [from, to] of tickets) {
    if (!graph.has(from)) {
      graph.set(from, []);
    }
    graph.get(from)!.push(to);
  }

  // Sort every to[] in the graph in lexical order
  for (const tos of graph.values()) {
    tos.sort();
  }

  const start = "JFK";
  dfs(start);

  // it is a post order traversal, the start node is the last one to be pushed into the route
  function dfs(from: string): void {
    const tos = graph.get(from) || [];
    while (tos.length > 0) {
      // get the smallest lexical order destination and remove the ticket
      const dest = tos.shift()!;
      dfs(dest);
    }
    // push the start node to the route, it will be reversed at last
    route.push(from);
  }

  return route.reverse();
}

function findItinerary_2(tickets: string[][]): string[] {
  const graph: Record<string, string[]> = {};

  // 构建图
  for (const [from, to] of tickets) {
    if (!graph[from]) graph[from] = [];
    graph[from].push(to);
  }

  // 按字典序排序
  for (const key in graph) {
    graph[key].sort(); // 小的先出栈
  }

  const result: string[] = [];

  function dfs(node: string) {
    const dests = graph[node];
    while (dests && dests.length) {
      const next = dests.shift()!; // 用掉这张票
      dfs(next);
    }
    result.push(node); // 回溯加入行程
  }

  dfs("JFK");
  return result.reverse();
}

/*
Approach: Brute Force

https://www.youtube.com/watch?v=LKSdX31pXjY&list=PLTNkreZiUTIL-S_VJBLRxlmGktAQtla-m&index=6

Time Complexity: O(N) + O(NlogN) + O(n!)
Space: O(n) + O(n) graph + Stack


Create a graph with the tickets. node -> list of neighbors, sorted in lexical order.
DFS from JFK, backtracking when all tickets are used.
*/
function findItinerary_LaiOff(tickets: string[][]): string[] {
  return [];
}
