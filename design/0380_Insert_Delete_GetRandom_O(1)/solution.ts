/*
380. Insert Delete GetRandom O(1)

https://leetcode.com/problems/insert-delete-getrandom-o1/
*/

/*

*/
class RandomizedSet {
  // map of value to index in the list
  private map: Map<number, number>; // value -> index
  // sorted list of values for random access
  private list: number[]; // value

  constructor() {
    this.map = new Map<number, number>();
    this.list = [];
  }

  insert(val: number): boolean {
    if (this.map.has(val)) return false;
    this.map.set(val, this.list.length);
    this.list.push(val);
    return true;
  }

  remove(val: number): boolean {
    if (!this.map.has(val)) return false;
    // Get index of the value to be removed
    const index = this.map.get(val)!;
    this.map.delete(val);
    const last = this.list.pop()!; // remove the last element and holed it in variable last
    // if the element to remove is the last element, we are done
    // otherwise, we need to move the last element to the position of the element to remove
    if (last !== val) {
      this.list[index] = last;
      this.map.set(last, index);
    }
    return true;
  }

  getRandom(): number {
    return this.list[Math.floor(Math.random() * this.list.length)];
  }
}
