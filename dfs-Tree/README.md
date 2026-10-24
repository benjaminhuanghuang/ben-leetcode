# Depth-First Search with Tree

## When to use

## Complexity

Time complexity O(N): 在DFS中，每个节点会被访问一次，因此总的时间复杂度为 O(N)，其中 N 是二叉树中的节点总数。

Space complexity: O(N) ~ O(logN) DFS的空间复杂度主要取决于递归调用栈的深度。在最坏情况下，树是一条链状结构（即每个节点只有一个子节点），这种情况下递归调用栈的深度为 N，空间复杂度为 O(N)。 在平均情况下，假设树是完全平衡的，那么递归调用栈的深度为树的高度。对于一个完全平衡的二叉树，树的高度为 O(log N)，因此空间复杂度为 O(log N)。

## Template

```ts
function dfs(startIndex, target) {
    if (isLeaf(startIndex)) {
        return 1
    }
    int ans = initialValue;
    for (const edge of getEdges(startIndex, [...additional states])) {
        if (additional states) {
            update([...additional states]);
        }
        ans = aggregate(ans, dfs(startIndex + edge.length(), [...additional states])
        if (additional states) {
            revert([...additional states]);
        }
    }
    return ans;
}
```

```js
function dfs(startIndex, path, res, [...additional states]) {
    if (isLeaf(path)) {
        res.push(new Array(path));
        return;
    }
    for (const edge of getEdges(startIndex, [...additional states])) {
        path.push(choice);
        if (...additional states) update(...additional states)
        dfs(startIndex + edge.length, path, res, [...addtional states]);
        path.pop();
        // revert(...additional states) if necessary, e.g. permutations
    }
}
```
