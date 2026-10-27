/*
利用 Map 的插入顺序特性实现 LRU：
- Map 的 key 顺序即插入顺序，重新 set 同一个 key 会把它移到末尾（最新位置）
- 约定 Map 的第一个 key（keys().next().value）为最久未使用（LRU）的元素
*/
class LRUCache {
  private capacity: number;
  private map: Map<number, number>;

  constructor(capacity: number) {
    this.capacity = capacity;
    this.map = new Map<number, number>();
  }

  get(key: number): number {
    if (!this.map.has(key)) return -1;

    const value = this.map.get(key)!;
    this.map.delete(key);
    this.map.set(key, value); // 重新插入，移到最近使用位置
    return value;
  }

  put(key: number, value: number): void {
    if (this.map.has(key)) {
      this.map.delete(key);
    } else if (this.map.size >= this.capacity) {
      const lruKey = this.map.keys().next().value; // 第一个 key 即最久未使用
      this.map.delete(lruKey!);
    }
    this.map.set(key, value);
  }
}

export {};
