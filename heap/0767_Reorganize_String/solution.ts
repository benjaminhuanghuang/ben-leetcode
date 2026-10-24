/*
767. Reorganize String

https://leetcode.com/problems/reorganize-string/

重新排列字符串，使得相同字符不相邻，如果不可能返回空字符串。

想优先选择剩余次数最多的字符。
如果我们先用低频字符，频率高的字符可能会被迫连续出现，最终无法安排。
选频率高的字符 → 保证它们能“均匀分布”在整个结果中。
*/

function reorganizeString(s: string): string {
  if (s.length <= 1) return s;

  // 1. Count frequencies
  const freq: Map<string, number> = new Map();
  for (const ch of s) {
    freq.set(ch, (freq.get(ch) ?? 0) + 1);
  }

  // 2. Max heap by frequency
  const maxHeap = new MyHeap<[string, number]>((a, b) => a[1] > b[1]);

  // 3. Push all [char, count] pairs
  for (const [ch, count] of freq) {
    maxHeap.push([ch, count]);
  }

  let result = "";
  let prev: [string, number] | null = null;

  // 4. Build result
  while (!maxHeap.isEmpty()) {
    //get the current most frequent character.
    const [ch, count] = maxHeap.pop();
    result += ch;

    // Push back the previous character if it still has remaining count
    if (prev && prev[1] > 0) {
      maxHeap.push(prev);
    }

    // Update current character as previous
    prev = [ch, count - 1];
  }

  // 5. Validate result
  return result.length === s.length ? result : "";
}

class MyHeap<T> {
  private data: T[] = [];

  constructor(private cmp: (a: T, b: T) => boolean) {}

  push(val: T) {
    this.data.push(val);
    this.bubbleUp();
  }

  pop(): T {
    const top = this.data[0];
    const last = this.data.pop()!;
    if (this.data.length > 0) {
      this.data[0] = last;
      this.bubbleDown();
    }
    return top;
  }

  isEmpty(): boolean {
    return this.data.length === 0;
  }

  private bubbleUp() {
    let i = this.data.length - 1;
    while (i > 0) {
      const p = Math.floor((i - 1) / 2);
      if (!this.cmp(this.data[i], this.data[p])) break;
      [this.data[i], this.data[p]] = [this.data[p], this.data[i]];
      i = p;
    }
  }

  private bubbleDown() {
    let i = 0;
    const n = this.data.length;
    while (true) {
      let best = i;
      const l = i * 2 + 1;
      const r = i * 2 + 2;
      if (l < n && this.cmp(this.data[l], this.data[best])) best = l;
      if (r < n && this.cmp(this.data[r], this.data[best])) best = r;
      if (best === i) break;
      [this.data[i], this.data[best]] = [this.data[best], this.data[i]];
      i = best;
    }
  }
}
