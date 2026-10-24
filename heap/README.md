# Heap and Priority Queue

A priority queue is a concept, and a heap is how you implement it efficiently.

最小堆：父节点 ≤ 子节点
堆数组: [1, 2, 4, 3]
二叉树:
1
/ \
2 4
/
3

最大堆：父节点 ≥ 子节点

insert: 插入新元素 时，新元素通常放在数组末尾。将它一路“上浮”到正确的位置，

删除堆顶元素（dequeue）时，把最后一个元素放到堆顶, 将它移动到正确位置，保持堆性质。

```py
bubbleUp(index):
    element = heap[index]
    while index > 0:
        parentIndex = (index - 1) // 2
        parent = heap[parentIndex]
        if heap性质满足:
            break
        swap element and parent
        index = parentIndex

bubbleDown(index):
    element = heap[index]
    while true:
        leftChildIndex = 2*index + 1
        rightChildIndex = 2*index + 2
        找出 left/right 中最小/最大值的 child
        if element <= child (最小堆) or element >= child (最大堆):
            break
        swap element and child
        index = childIndex
```

## Complexity

Time complexity: insert = O(logN), extract = O(logN), Peek = O(1)
