# Prefix Sum

prefixSum[i] 表示从数组开头到第 i 个元素的累加和。

```js
prefixSum[i] = arr[0] + ... arr[i]

// 数组区间和

sum(l, r) = prefixSum[r] - prefixSum[l-1]   // l > 0
```

对二维数组 matrix[i][j],

```js
prefixSum[i][j] = matrix[0][0] + ... matrix[i][j]

// 矩形内的所有元素之和
sum(x1,y1,x2,y2) = prefixSum[x2][y2] - prefixSum[x1-1][y2] - prefixSum[x2][y1-1]+ prefixSum[x1-1][y1-1]
```

## Complexity

时间复杂度：O(n)
空间复杂度：O(n)
