# Backtracking P293

Template of backtacking

```js
function dfs(state: State): void {
  // Termination condition.
  if (meetsTerminationCondition(state)) {
    processSolution(state);
    return;
  }

  // Explore each possible decision that can be made at the current
  // state.
  for (const decision of possibleDecisions(state)) {
    makeDecision(state, decision);
    dfs(state);
    undoDecision(state, decision); // Backtrack.
  }
}
```

The time complexity is often estimated as O(b^d),
b denotes the branching factor and d denotes the depth.

Branching factor: The number of children each node has. It typically represents the maximum
number of decisions that can be made for a given state.

Depth: The length of the deepest path in the state space tree. It corresponds to the number
of decisions or steps required to reach a complete solution .

This is because in the worst case, every node at each level of the tree needs to
be explored during a typical backtracking algorithm .

## When to use backtracking

Backtracking is useful when we need to explore all possible solutions to a problem . For example, if
we need to find all possible ways to arrange items, or generate all possible subsets, permutations,
or combinations, backtracking can help to identify every possible solution.
Real-world
