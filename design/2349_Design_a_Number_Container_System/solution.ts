/*
2349. Design a Number Container System

https://leetcode.com/problems/design-a-number-container-system/
*/

class NumberContainers {
  // index -> number
  indexMap: Map<number, number> = new Map();
  // index-> indexes of the number, each number can have multiple indexes
  numberMap: Map<number, Set<number>> = new Map();

  constructor() {}

  change(index: number, number: number): void {
    if (this.indexMap.has(index)) {
      const oldNumber = this.indexMap.get(index)!;
      const indicesSet = this.numberMap.get(oldNumber);
      if (indicesSet) {
        indicesSet.delete(index);
        if (indicesSet.size === 0) {
          this.numberMap.delete(oldNumber);
        }
      }
    }

    this.indexMap.set(index, number);
    if (!this.numberMap.has(number)) {
      this.numberMap.set(number, new Set());
    }
    this.numberMap.get(number)!.add(index);
  }

  find(number: number): number {
    if (this.numberMap.has(number) && this.numberMap.get(number)!.size > 0) {
      return Math.min(...this.numberMap.get(number)!); // Return the smallest index
    }
    return -1;
  }
}
