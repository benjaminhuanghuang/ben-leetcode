/*
705. Design HashSet

https://leetcode.com/problems/design-hashset/
*/

class MyHashSet {
  private set: boolean[];

  constructor() {
    this.set = new Array(1000001).fill(false);
  }

  add(key: number): void {
    this.set[key] = true;
  }

  remove(key: number): void {
    this.set[key] = false;
  }

  contains(key: number): boolean {
    return this.set[key];
  }
}
