
# Combination - Huahua

## Combination: order does not matter

花花酱 LeetCode 78. Subsets <https://www.youtube.com/watch?v=CUzm-buvH_8>

Time complexity: O(N * 2^N)
Space complexity: O(N)

d: recursion depth
n: take how many numbers

Combination: 每一层递归只使用 start index 后面的number
s: start index

```js
const nums = [...];
const ans = [];

// C(m,n)
for (let i = 0; i <= nums.length; i++) {
    dfs(i, 0, []);   // i is the length of the combination
}

// n is length of the combination
// s is starting index
function dfs(n, s, cur) {
    if (cur.length === n) {   // find a answer
        ans.push([...cur]);
        return;
    }
    for (let i = s; i < nums.length; i++) {
        cur.push(nums[i]);

        dfs(n, i + 1, cur);

        cur.pop();
    }
}
```

## Permutation: order matters

```js
const nums = [...];
const ans = [];
const used = new Array(nums.length).fill(false);

// P(m, n)
for (let i = 0; i <= nums.length; i++) {
    dfs(i, []);
}

function dfs(n, cur) {
    if (cur.length === n) {
        ans.push([...cur]);
        return;
    }

    for (let i = 0; i < nums.length; i++) {  // from index 0
        if (used[i]) continue;

        used[i] = true;
        cur.push(nums[i]);

        dfs(n, cur);

        cur.pop();
        used[i] = false;
    }
}
```

## 什么时候需要排序

1. 输入数据中存在重复元素时，需要排序。 排序能把相同元素放在一起，便于去重

2. 需要产生结果按字典序（lexicographical order）输出时

3. 使用剪枝优化时， 如 Combination Sum 中，排序后当总和已经超出目标值可以提前中断：

## 什么时候不需要排序？

1. 数据已保证无重复且不要求顺序
2. 明确需要保持输入顺序

## Permutation

time complexity O(n × n!) "O of n times n factorial."
全排列总共有 n! 种可能, 每次构造一个长度为 n 的排列，需要 O(n) 的操作（例如 push / copy / join）

space complexity
O(n) 栈空间 + O(n × n!) 输出空间

## Combination

如果要求从 n 个元素中选 k 个，组合总数为：C(n,k)
时间复杂度: O(k×C(n,k))

## 全组合 Subsets

时间复杂度：O(n × 2^n)
因为： 共有 2^n 个子集, 每个最多长度 n → 构造 O(n)

空间复杂度: 栈深度最大为 O(n) + 输出空间为 O(n × 2^n)
