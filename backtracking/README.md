# Backtracking

## When to use

Backtracking is useful when we need to **explore all possible solutions** to a problem.
For example, if we need to find all possible ways to arrange items, or generate all possible subsets, permutations,
or combinations, backtracking can help to identify every possible solution.

- 排列问题：N个数按⼀定规则全排列，有⼏种排列⽅式, 顺序不同算不同的排列
- 组合问题：N个数⾥⾯按⼀定规则找出k个数的集合, 不考虑顺序
- 切割问题：⼀个字符串按⼀定规则有⼏种切割⽅式
- ⼦集问题：⼀个N个数的集合⾥有多少符合条件的⼦集
- 棋盘问题：N皇后，解数独等等

## Complexity

The time complexity is often estimated as O(b^d),
b denotes the branching factor and d denotes the depth.

Branching factor: The number of children each node has. It typically represents the maximum
number of decisions that can be made for a given state.

Depth: The length of the deepest path in the state space tree. It corresponds to the number
of decisions or steps required to reach a complete solution .

This is because in the worst case, every node at each level of the tree needs to
be explored during a typical backtracking algorithm .

## Template

The state can be nums, candidate, used, result

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

template 2:

```js
void backtracking(参数) {
  if (终⽌条件) {
    存放结果;
    return;
  }
  for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
    处理节点;
    backtracking(路径，选择列表); // 递归
    回溯，撤销处理结果
  }
}
```

## Leetcode list

79. Word Search

80. Robot Room Cleaner

81. Letter Tile Possibilities
