/*
A graph is bipartite if the nodes can be colored in one of two colors, so that no two adjacent nodes are the same color.

If the nodes of a graph can be divided into two distinct sets, with the edges only running between nodes from
different sets, then the graph is bipartite.

To determine if a graph is bipartite, we can use graph coloring, where we attempt to color one set
of nodes with one color, and the other set of nodes with another color, while ensuring no adjacent
nodes share the same color.


Keep i n mind the input isn't necessarily a graph that's fully connected

*/
function bipartite_graph_validation(graph: number[][]): boolean {
  // Track the color assigned to each node, where 0 means uncolored,
  // 1 means color A, and -1 means color B.
  const colors: number[] = new Array(graph.length).fill(0);

  // Determine if each graph component is bipartite.
  for (let i = 0; i < graph.length; i++) {
    if (colors[i] === 0 && !dfs(i, 1, graph, colors)) {
      return false;
    }
  }

  return true;
}

// DFS to color the graph and check for bipartiteness.
function dfs(
  nodeIndex: number,
  color: number,
  graph: number[][],
  colors: number[]
): boolean {
  // Color the current node.
  colors[nodeIndex] = color;

  // Explore each neighbor of the current node.
  for (const neighbor of graph[nodeIndex]) {
    // If the current neighbor has the same color as the current
    // node, the graph is not bipartite.
    if (colors[neighbor] === color) {
      return false;
    }

    // If the current neighbor is not colored, color it with the
    // other color and continue the DFS.
    if (colors[neighbor] === 0 && !dfs(neighbor, -color, graph, colors)) {
      return false;
    }
  }

  return true;
}

/*
Time complexity: O(n + e) where n denotes the number of nodes and e denotes the number of edges. 
This is because we explore all nodes in the graph and traverse across e edges during DFS.

Space complexity: O(n) due to the space taken up by the recursive call stack, which can grow as large as n. 
In addition, the colors array also contributes O(n) space.
*/
