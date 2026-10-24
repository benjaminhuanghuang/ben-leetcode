import { GraphNode } from "./graph";
/*

Time complexity of graph_deep_copy is O(n + e)

Space complexity of graph_deep_copy is O(n) due to the space taken up by the recursive call
stack, which can grow as large as n. In addition, the clone_map hash map stores a key-value pair
for each of the n nodes

*/
function graphDeepCopy(node: GraphNode | null): GraphNode | null {
  if (!node) {
    return null;
  }
  return dfs(node, new Map<GraphNode, GraphNode>());
}

function dfs(node: GraphNode, cloneMap: Map<GraphNode, GraphNode>): GraphNode {
  // If this node was already cloned, then return this previously
  // cloned node.
  if (cloneMap.has(node)) {
    return cloneMap.get(node)!;
  }

  // Clone the current node.
  const clonedNode = new GraphNode(node.val);

  // Store the current clone to ensure it doesn't need to be created
  // again in future DFS calls.
  cloneMap.set(node, clonedNode);

  // Iterate through the neighbors of the current node to connect
  // their clones to the current cloned node.
  for (const neighbor of node.neighbors) {
    const clonedNeighbor = dfs(neighbor, cloneMap);
    clonedNode.neighbors.push(clonedNeighbor);
  }

  return clonedNode;
}
