/*
133. Clone Graph

https://leetcode.com/problems/clone-graph/

    138. Copy List with Random Pointer
*/

import { _Node } from "../Common/_Node";

function cloneGraph(node: _Node | null): _Node | null {
  //uses a map, maps old graph nodes with new graph ones
  //it also tells us which node of the old graph have already been visited
  let visited = new Map<_Node, _Node>();

  return dfs(node, visited);
}

function dfs(node: _Node | null, visited: Map<_Node, _Node>): _Node | null {
  if (node === null) return null;

  //if this node has already been visited, simply return the counterpart
  //node of the new graph and return
  if (visited.has(node)) return visited.get(node) as _Node;

  //node hasn't been already visited, create its counterpart version for the new graph
  let clonedNode = new _Node(node.val);
  //maps to the old graph counterpart(also marked as visited)
  visited.set(node, clonedNode);

  //for each edge of the old node, add that edge in the new graph node
  for (let i = 0; i < node.neighbors.length; i++) {
    clonedNode.neighbors.push(dfs(node.neighbors[i], visited) as _Node);
  }

  return clonedNode;
}
