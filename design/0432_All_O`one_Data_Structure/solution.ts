/*
432. All O`one Data Structure

https://leetcode.com/problems/all-oone-data-structure/
*/
class Node {
  count: number;
  keySet: Set<string>;
  next: Node | null;
  pre: Node | null;

  constructor(cnt: number) {
    this.count = cnt;
    this.keySet = new Set<string>();
    this.next = null;
    this.pre = null;
  }
}

/*
双向链表维护所有计数 bucket（每个 bucket 存一组相同计数的 key）
为什么引入 bucket？
把相同计数的 key 聚在一起

比如 count = 5 的所有 key 都在同一个 bucket.keySet 中

增加或减少计数时只需要移动 key 在 bucket 之间

链表维护计数顺序

head → tail 链表顺序 = 从小到大计数

getMinKey → head.next.keySet 中任意 key

getMaxKey → tail.pre.keySet 中任意 key

不用遍历所有 key → O(1)

O(1) 时间移动 key

inc(key) → key 从旧 bucket 移到下一个 bucket

dec(key) → key 从旧 bucket 移到前一个 bucket

如果新 bucket 不存在 → 创建并插入链表

删除空 bucket → 链表中删除节点
*/

class AllOne {
  private head: Node;
  private tail: Node;
  private countBucketMap: Map<number, Node>;
  private keyCountMap: Map<string, number>;

  constructor() {
    this.head = new Node(Number.MIN_SAFE_INTEGER);
    this.tail = new Node(Number.MAX_SAFE_INTEGER);
    this.head.next = this.tail;
    this.tail.pre = this.head;
    this.countBucketMap = new Map<number, Node>();
    this.keyCountMap = new Map<string, number>();
  }

  inc(key: string): void {
    if (this.keyCountMap.has(key)) {
      this.changeKey(key, 1);
    } else {
      this.keyCountMap.set(key, 1);
      if (this.head.next!.count !== 1) {
        this.addBucketAfter(new Node(1), this.head);
      }
      this.head.next!.keySet.add(key);
      this.countBucketMap.set(1, this.head.next!);
    }
  }

  dec(key: string): void {
    if (this.keyCountMap.has(key)) {
      let count = this.keyCountMap.get(key)!;
      if (count === 1) {
        this.keyCountMap.delete(key);
        this.removeKeyFromBucket(this.countBucketMap.get(count)!, key);
      } else {
        this.changeKey(key, -1);
      }
    }
  }

  getMaxKey(): string {
    return this.tail.pre === this.head
      ? ""
      : this.tail.pre!.keySet.values().next().value!;
  }

  getMinKey(): string {
    return this.head.next === this.tail
      ? ""
      : this.head.next!.keySet.values().next().value!;
  }

  private changeKey(key: string, offset: number): void {
    let count = this.keyCountMap.get(key)!;
    this.keyCountMap.set(key, count + offset);
    let curBucket = this.countBucketMap.get(count)!;
    let newBucket: Node;
    if (this.countBucketMap.has(count + offset)) {
      newBucket = this.countBucketMap.get(count + offset)!;
    } else {
      newBucket = new Node(count + offset);
      this.countBucketMap.set(count + offset, newBucket);
      this.addBucketAfter(newBucket, offset === 1 ? curBucket : curBucket.pre!);
    }
    newBucket.keySet.add(key);
    this.removeKeyFromBucket(curBucket, key);
  }

  private removeKeyFromBucket(bucket: Node, key: string): void {
    bucket.keySet.delete(key);
    if (bucket.keySet.size === 0) {
      this.removeBucketFromList(bucket);
      this.countBucketMap.delete(bucket.count);
    }
  }

  private removeBucketFromList(bucket: Node): void {
    bucket.pre!.next = bucket.next;
    bucket.next!.pre = bucket.pre;
    bucket.next = null;
    bucket.pre = null;
  }

  private addBucketAfter(newBucket: Node, preBucket: Node): void {
    newBucket.pre = preBucket;
    newBucket.next = preBucket.next;
    preBucket.next!.pre = newBucket;
    preBucket.next = newBucket;
  }
}

export {};
