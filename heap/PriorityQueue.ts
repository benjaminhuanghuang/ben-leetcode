/*
For a min-heap, the compare function typically returns a value "less than zero" if the first element 
should have higher priority (be placed higher) than the second element. 
This ensures that the smallest element is always at the root of the heap.
Example: compare(a, b) => a - b would prioritize smaller values (a should come before b).

For a max-heap, the compare function typically returns a value greater than zero if the first element 
should have higher priority (be placed higher) than the second element. 
This ensures that the largest element is always at the root of the heap.
Example: compare(a, b) => b - a would prioritize larger values (b should come before a).

*/
type CompareFunction<T> = (a: T, b: T) => boolean;

export class PriorityQueue<T> {
  private heap: T[];
  private compare: CompareFunction<T>;
  private capacity: number;

  constructor(compare: CompareFunction<T>, capacity: number = Infinity) {
    this.heap = [];
    this.compare = compare;
    this.capacity = capacity;
  }

  // Add an element to the priority queue
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
      this.compare(this.heap[currentIndex], this.heap[parentIndex])
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
      this.compare(this.heap[leftChildIndex], this.heap[smallest])
    ) {
      smallest = leftChildIndex;
    }

    if (
      rightChildIndex < this.heap.length &&
      this.compare(this.heap[rightChildIndex], this.heap[smallest])
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

  add(value: T): void {
    if (this.heap.length < this.capacity) {
      this.heap.push(value);
      this.heapifyUp(this.heap.length - 1);
    } else {
      // to minHeap, if this.heap[0] < value, we need to re-evaluate the min value in the heap
      // this logic is for the Kth largest element in an array
      if (this.compare(this.heap[0], value)) {
        // Replace the root with the new value
        this.heap[0] = value;
        this.heapifyDown(0);
      }
    }
  }

  poll(): T | undefined {
    if (this.heap.length === 0) {
      return undefined;
    }
    // remove the element at the top of the heap, which is the smallest/bigest element
    // and then re-heapify the heap
    const val = this.heap[0];
    this.heap[0] = this.heap[this.heap.length - 1];
    this.heap.pop();
    this.heapifyDown(0);

    return val;
  }

  peek(): T | undefined {
    return this.heap.length > 0 ? this.heap[0] : undefined;
  }

  size(): number {
    return this.heap.length;
  }

  isEmpty(): boolean {
    return this.heap.length === 0;
  }
}
