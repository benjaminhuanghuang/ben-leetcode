class MinHeap<T> {
  private data: T[] = [];
  private compare: (a: T, b: T) => boolean;

  constructor(compare: (a: T, b: T) => boolean) {
    this.compare = compare;
  }

  size(): number {
    return this.data.length;
  }

  isEmpty(): boolean {
    return this.data.length === 0;
  }

  push(value: T): void {
    this.data.push(value);
    this.heapifyUp();
  }

  pop(): T | undefined {
    if (this.isEmpty()) return undefined;
    const top = this.data[0];
    const end = this.data.pop()!;
    if (!this.isEmpty()) {
      this.data[0] = end;
      this.heapifyDown();
    }
    return top;
  }

  private heapifyUp(): void {
    let i = this.data.length - 1;
    while (i > 0) {
      const parent = Math.floor((i - 1) / 2);
      if (this.compare(this.data[i], this.data[parent])) {
        [this.data[i], this.data[parent]] = [this.data[parent], this.data[i]];
        i = parent;
      } else break;
    }
  }

  private heapifyDown(): void {
    let i = 0;
    const n = this.data.length;
    while (true) {
      let left = 2 * i + 1;
      let right = 2 * i + 2;
      let smallest = i;

      if (left < n && this.compare(this.data[left], this.data[smallest])) {
        smallest = left;
      }
      if (right < n && this.compare(this.data[right], this.data[smallest])) {
        smallest = right;
      }
      if (smallest === i) break;

      [this.data[i], this.data[smallest]] = [this.data[smallest], this.data[i]];
      i = smallest;
    }
  }
}
