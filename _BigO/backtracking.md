# Backtracking

- branching factor（分支数）
- recursion tree（递归树）
- dominated by the last term
- geometric series = 等比数列 每一项都是上一项乘以同一个数

The time complexity of backtracking is generally **exponential** in the worst case.

Backtracking explores all possible combinations or configurations of a problem space. If there are **N decisions** and each decision has M possible choices, the complexity often looks like: O(M^N), M to the power of N

- Make a choice
- Recursively explore deeper
- Undo the choice (backtrack)
- Try next option

For a search tree with:
b = branching factor (choices at each step)
d = depth

Time complexity: O(b^d)
Space complexity: O(d) // due to recursion stack

## Typical Examples

| Problem             | Typical Backtracking Complexity   |
| ------------------- | --------------------------------- |
| N-Queens            | `O(N!)`big O of N factorial or approximately `O(N^N)`|
| Sudoku solver       | `O(9^N)` (exponential)|
| Subsets / Power set | `O(2^N)`                          |
| Permutations        | `O(N · N!)`                       |
| Combination Sum     | `O(k^N)` (exponential)            |
| Maze pathfinding    | `O(2^(rows × cols))`              |

```js
function subsets(nums) {
  const result = [];

  function backtrack(start, current) {
    result.push([...current]);
    for (let i = start; i < nums.length; i++) {
      current.push(nums[i]);
      backtrack(i + 1, current);
      current.pop();
    }
  }

  backtrack(0, []);
  return result;
}
```

O(2^N) complexity.

## 写法

"The time complexity is exponential, O(b^d), where b is the branching
factor and d is the maximum depth of the recursion tree.

Think of the recursion as a tree. Each level branches into at most b
children, and the tree is at most d levels deep.

So level i has b^i nodes, and the total is 1 + b + b² + ... + b^d.

This geometric series is dominated by its last term, so it's O(b^d).

Space is O(d) for the recursion stack."

## 口语（面试时要讲出来）

"The time complexity is exponential, big O of b to the power of d,
where b is the branching factor and d is the maximum depth of the
recursion tree.

Think of the recursion as a tree. Each level branches into at most b
children, and the tree is at most d levels deep.

So level i has b to the i nodes, and the total is: 1 plus b plus b
squared, and so on, up to b to the d.

This geometric series is dominated by its last term, so it's big O of
b to the d.

Space is big O of d for the recursion stack."
