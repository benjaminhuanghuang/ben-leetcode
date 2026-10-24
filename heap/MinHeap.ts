export class MinHeap {
  private heap: number[];
  private capacity: number;

  constructor(capacity: number) {
    this.heap = [];
    this.capacity = capacity;
  }

  private getParentIndex(index: number): number {
    return Math.floor((index - 1) / 2);
  }

  private getLeftChildIndex(index: number): number {
    return 2 * index + 1;
  }

  private getRightChildIndex(index: number): number {
    return 2 * index + 2;
  }

  private heapifyUp(index: number): void {
    let currentIndex = index;
    let parentIndex = this.getParentIndex(currentIndex);
    while (
      currentIndex > 0 &&
      this.heap[currentIndex] < this.heap[parentIndex]
    ) {
      [this.heap[currentIndex], this.heap[parentIndex]] = [
        this.heap[parentIndex],
        this.heap[currentIndex],
      ];
      currentIndex = parentIndex;
      parentIndex = this.getParentIndex(currentIndex);
    }
  }

  private heapifyDown(index: number): void {
    let currentIndex = index;
    let leftChildIndex = this.getLeftChildIndex(currentIndex);
    let rightChildIndex = this.getRightChildIndex(currentIndex);
    let smallest = currentIndex;

    if (
      leftChildIndex < this.heap.length &&
      this.heap[leftChildIndex] < this.heap[smallest]
    ) {
      smallest = leftChildIndex;
    }

    if (
      rightChildIndex < this.heap.length &&
      this.heap[rightChildIndex] < this.heap[smallest]
    ) {
      smallest = rightChildIndex;
    }

    if (smallest !== currentIndex) {
      [this.heap[currentIndex], this.heap[smallest]] = [
        this.heap[smallest],
        this.heap[currentIndex],
      ];
      this.heapifyDown(smallest);
    }
  }

  insert(value: number): void {
    if (this.heap.length < this.capacity) {
      this.heap.push(value);
      this.heapifyUp(this.heap.length - 1);
    } else if (value > this.heap[0]) {
      // To minHeap, if this.heap[0] < value, we need to re-evaluate the min value in the heap
      // this logic is for the Kth largest element in an array
      this.heap[0] = value;
      this.heapifyDown(0);
    }
  }

  extractMin(): number | undefined {
    if (this.heap.length === 0) {
      return undefined;
    }

    const minValue = this.heap[0];
    this.heap[0] = this.heap[this.heap.length - 1];
    this.heap.pop();
    this.heapifyDown(0);

    return minValue;
  }

  peek(): number | undefined {
    return this.heap.length > 0 ? this.heap[0] : undefined;
  }

  size(): number {
    return this.heap.length;
  }

  isEmpty(): boolean {
    return this.heap.length === 0;
  }
}
