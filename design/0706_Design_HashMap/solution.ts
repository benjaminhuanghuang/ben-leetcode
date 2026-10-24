/*
706. Design HashMap

https://leetcode.com/problems/design-hashmap/
*/

class MyHashMap {
  DATA_SIZE = 10 ** 6 + 1; // Define the size of the data array
  data: number[] = new Array(this.DATA_SIZE).fill(-1);

  constructor() {}

  put(key: number, value: number): void {
    this.data[key] = value;
  }

  get(key: number): number {
    return this.data[key];
  }

  remove(key: number): void {
    this.data[key] = -1;
  }
}
