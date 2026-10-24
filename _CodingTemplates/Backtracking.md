# Backtracking

## Template

```js
function backtrack(path, choices) {
  // 1. Base case
  if (isComplete(path)) {
    // Copy！不能直接 push(path)
    result.push([...path]);
    return;
  }

  // 2. Try every possible choice
  for (const choice of choices) {
    if (!isValid(choice)) continue;

    // 3. Make a choice
    path.push(choice);

    // 4. Explore
    backtrack(path, choices);

    // 5. Undo the choice
    path.pop();
  }
}
```

Backtracking 不一定需要 undo；它只需要 state isolation。undo 是实现 state isolation 的一种方式。

## Complexity

- Backtracking explores a decision tree, so it's exponential — big O of b to the d, where b is the branching factor and d is the depth. Pruning reduces the constant, not the complexity class.

| 问题                   | 复杂度     | 为什么                            |
| ---------------------- | ---------- | --------------------------------- |
| Subsets（子集）        | O(2^n)     | 每个元素选/不选，2 种 × n 个      |
| Permutations（全排列） | O(n!)      | 第 1 位 n 个选择，第 2 位 n-1 个… |
| N-Queens               | O(n!) 量级 | 每行 n 列试，剪枝后远小于理论值   |
| Letter Combinations    | O(4^n)     | 每位最多 4 个字母（7/9 键）       |

- Space: 辅助空间（auxiliary）：O(d) — 递归栈深度 + 当前 path 数组，d 是决策树深度,  path 长度永远 ≤ 递归深度。n=20 的 subsets，栈也就 20 层。
输出本身：如果算上存结果，那就是 O(输出量 × 单个解大小) — subsets 是 O(n·2^n)，permutations 是 O(n·n!)。输出通常是题目要的，不算进"额外空间"，但面试官问起你要分得清。

Auxiliary space is big O of d — just the recursion stack and the current path. The output dominates if you count it: storing all subsets is big O of n times 2 to the n."

顺带：这就是为什么 backtracking 题经常加一句 "excluding the output" — 不加这句，空间复杂度永远被输出淹没，没意义。

## Sample
