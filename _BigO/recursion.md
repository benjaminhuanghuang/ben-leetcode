# Time and Space complexity of Recursion

```ts
fun(n) {
    if(n <=1) return 1;
    return f(n-1) + f(n-2)
}
```

The hight of the recursion tree is N
Every node has 2 sub nodes
The total node count is
2^0 + 2^1 + 2^2 .... 2^N = 2进制数的N+1个1 = 2^(N+1) - 1

Normally, the time complexity of recursion function is:
Branch count ^ height of recursion tree = O(2^N)

```ts
sum(node) {
    if(node == null) return 0;
    return sum(node.left) + node.val + sum(node.right);
}
```

出于直觉，每个node都被访问了一遍，因此 time complexity is O(N)

套用上面的公式，time complexity is O(2^Depth)
而树的高度depth = LogN, 可以推导出 2^Depth = N

```js
factorial(n) {
    if(n <) return -1;
    if(n==0) return 1;
    return n * factorial(n-1);
}
```

Calculate n to 1, the time complexity is O(N)

- Time/Space Complexity of Recursive Algorithms(Hua hua)
  <https://www.youtube.com/watch?v=OQi4n8EKRD8&list=PLLuMmzMTgVK5Hy1qcWYZcd7wVQQ1v0AjX&index=20>
