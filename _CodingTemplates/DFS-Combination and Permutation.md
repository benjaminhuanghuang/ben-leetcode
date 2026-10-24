# Permutation and combination

## Combination: order does not matter

每个元素 只能使用一次， 只用 startIndex 表示下一层递归从哪个位置开始选元素

Time complexity: O(N * 2^N): 2^N 个子集 × 拷贝 O(N)
Space complexity: O(N) 递归栈深度：最深 N 层

## Permutation(order matters)， used[i] = true 表示 第 i 个元素已经在当前路径中使用过
