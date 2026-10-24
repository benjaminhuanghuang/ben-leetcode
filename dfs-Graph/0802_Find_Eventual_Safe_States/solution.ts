/*
802. Find Eventual Safe States

https://leetcode.com/problems/find-eventual-safe-states/
*/

/*
  http://zxi.mytechroad.com/blog/graph/leetcode-802-find-eventual-safe-states/
  https://www.youtube.com/watch?v=v5Ni_3bHjzk

  DFS + state, find cycle
  States: Unknown, Visiting, Unsafe, Safe
  If we enter a node of state visiting then there is a
cycle.
  A node is unsafe if it forms a cycle or any of its
children is unsafe.

  Time complexity: O(V + E)
  Space complexity: O(V + E)
*/
enum State {
  UNKNOWN,
  VISITING,
  SAFE,
  UNSAFE,
}

function eventualSafeNodes(graph: number[][]): number[] {
  const states: State[] = new Array(graph.length).fill(State.UNKNOWN);
  const ans: number[] = [];

  for (let i = 0; i < graph.length; ++i) {
    if (dfs(graph, i, states) === State.SAFE) {
      ans.push(i);
    }
  }

  return ans;
}

function dfs(graph: number[][], cur: number, states: State[]): State {
  if (states[cur] === State.VISITING) {
    return (states[cur] = State.UNSAFE);
  }

  if (states[cur] !== State.UNKNOWN) {
    // is visited
    return states[cur];
  }

  states[cur] = State.VISITING;

  for (const next of graph[cur]) {
    if (dfs(graph, next, states) === State.UNSAFE) {
      states[cur] = State.UNSAFE; // has neighbor that is unsafe
      return State.UNSAFE;
    }
  }

  return (states[cur] = State.SAFE);
}

export {};
