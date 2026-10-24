# Binary Search recursive version and iterative version

```js
// recursive version
// Time complexity: O(log n), 每次搜索范围减半,所以时间复杂度是 O(log n)
// Space complexity: O(log n),因为递归调用栈会有 log n 层。
// 更贴近"分治"的定义, 数组极大时理论上有栈溢出可能
function binarySearch(arr, l, r, x) {
    if (r >= l) {
        const mid = l + Math.floor((r - l) / 2);
        if (arr[mid] === x) return mid;
        if (arr[mid] > x)  
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
```

```js
// iterative version
// Time complexity: O(log n), 每次搜索范围减半,所以时间复杂度是 O(log n)
// Space complexity: O(1)
function binarySearch(arr, x) {
    let l = 0, r = arr.length - 1;
    while (l <= r) {
        const m = l + Math.floor((r - l) / 2);
        if (arr[m] === x) return m;
        
        if (arr[m] < x) 
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
```
