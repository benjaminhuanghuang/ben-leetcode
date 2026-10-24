class PriorityQueue<T> {
  private heap: { item: T; priority: number }[] = [];

  constructor(private isMinHeap: boolean = true) {}

  // 插入 新元素通常放在数组末尾， 然后通过上浮操作调整位置以维护堆的性质
  enqueue(item: T, priority: number) {
    this.heap.push({ item, priority });
    this.bubbleUp(this.heap.length - 1);
  }

  // 弹出优先级最高的元素
  dequeue(): T | undefined {
    if (this.isEmpty()) return undefined;

    const top = this.heap[0].item;
    const end = this.heap.pop()!;
    if (!this.isEmpty()) {
      this.heap[0] = end;
      this.bubbleDown(0);
    }
    return top;
  }

  // 查看优先级最高元素
  peek(): T | undefined {
    return this.heap[0]?.item;
  }

  // 队列是否为空
  isEmpty(): boolean {
    return this.heap.length === 0;
  }

  // 上浮
  private bubbleUp(index: number) {
    const element = this.heap[index];
    while (index > 0) {
      const parentIndex = Math.floor((index - 1) / 2);
      const parent = this.heap[parentIndex];
      if (
        this.isMinHeap
          ? element.priority >= parent.priority
          : element.priority <= parent.priority
      )
        break;
      this.heap[parentIndex] = element;
      this.heap[index] = parent;
      index = parentIndex;
    }
  }

  // 下沉
  private bubbleDown(index: number) {
    const length = this.heap.length;
    const element = this.heap[index];

    while (true) {
      let leftChildIndex = 2 * index + 1;
      let rightChildIndex = 2 * index + 2;
      let swapIndex: number | null = null;

      if (leftChildIndex < length) {
        const left = this.heap[leftChildIndex];
        if (
          this.isMinHeap
            ? left.priority < element.priority
            : left.priority > element.priority
        ) {
          swapIndex = leftChildIndex;
        }
      }

      if (rightChildIndex < length) {
        const right = this.heap[rightChildIndex];
        if (
          this.isMinHeap
            ? swapIndex === null
              ? right.priority < element.priority
              : right.priority < this.heap[swapIndex].priority
            : swapIndex === null
              ? right.priority > element.priority
              : right.priority > this.heap[swapIndex].priority
        ) {
          swapIndex = rightChildIndex;
        }
      }

      if (swapIndex === null) break;

      this.heap[index] = this.heap[swapIndex];
      this.heap[swapIndex] = element;
      index = swapIndex;
    }
  }
}
