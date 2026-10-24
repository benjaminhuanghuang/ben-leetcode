/*
220. Contains Duplicate III

https://leetcode.com/problems/contains-duplicate-iii/

217. Contains Duplicate
219. Contains DuplicateⅡ    use map(value, index) or use Set as sliding window
*/

/*
Lai offer: 
https://www.youtube.com/watch?v=yc4hCFzNNQc

Approach: Sliding Window+ sorted Set
https://algo.monster/liteproblems/220

*/
type CompareFunction<T> = (a: T, b: T) => number;

class TreeSet<T> {
  elements: T[];
  length: number;
  compare: CompareFunction<T>;

  constructor(
    compare: CompareFunction<T> = (a: T, b: T) => Number(a) - Number(b)
  ) {
    this.length = 0;
    this.elements = [];
    this.compare = compare;
  }

  size() {
    return this.elements.length;
  }

  last() {
    return this.elements[this.length - 1];
  }

  first() {
    return this.elements[0];
  }

  isEmpty() {
    return this.size() === 0;
  }

  pollLast() {
    if (this.length > 0) {
      this.length--;
      return this.elements.splice(this.length, 1);
    }
    return null;
  }

  pollFirst() {
    if (this.length > 0) {
      this.length--;
      return this.elements.splice(0, 1);
    }
    return null;
  }

  // Keep the order of the elements in the set
  add(element: T) {
    let index = this.searchInsert(element);
    this.elements.splice(index, 0, element);
    this.length++;
  }

  remove(element: T) {
    let index = this.binarySearch(element);
    if (index >= 0) {
      this.elements.splice(index, 1);
      this.length--;
    }
  }
  // find the largest [i] that nums[i] < target
  floor(value: T): number {
    let left = 0;
    let right = this.elements.length;
    if (right === 0) return -1;
    if (value < this.elements[0]) return -1;
    let result = -1;

    while (left < right) {
      let mid = Math.floor((left + right) / 2);
      if (this.compare(this.elements[mid], value) <= 0) {
        left = mid + 1;
        result = mid;
      } else {
        right = mid;
      }
    }

    return result;
  }

  // Find the first [i] that nums[i]>target
  ceil(value: T): number {
    let left = 0;
    let right = this.elements.length;
    if (right === 0) return -1;
    if (value > this.elements[right - 1]) return -1;

    while (left < right) {
      let mid = Math.floor((left + right) / 2);
      if (this.compare(this.elements[mid], value) >= 0) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

  getValueAt(index: number): T {
    return this.elements[index];
  }
  /*
    35. Search Insert Position
    */
  searchInsert(value: T): number {
    let left = 0;
    let right = this.elements.length;

    while (left < right) {
      let mid = left + Math.floor((right - left) / 2);
      if (this.elements[mid] === value) return mid;
      // Find the minimum left that nums[left]<target
      if (this.compare(this.elements[mid], value) < 0) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }

  binarySearch(value: T): number {
    let left = 0;
    let right = this.elements.length;

    while (left < right) {
      let mid = Math.floor((left + right) / 2);
      let compare = this.compare(this.elements[mid], value);
      if (compare === 0) {
        return mid;
      } else if (compare < 0) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return -1;
  }
}

function containsNearbyAlmostDuplicate(
  nums: number[],
  indexDiff: number,
  valueDiff: number
): boolean {
  const treeSet: TreeSet<number> = new TreeSet((a: number, b: number) => a - b);

  for (let i = 0; i < nums.length; ++i) {
    const num = nums[i];

    const ceil = treeSet.ceil(num);
    if (ceil !== -1 && treeSet.getValueAt(ceil) - num <= valueDiff) {
      return true;
    }
    const floor = treeSet.floor(num);
    if (floor !== -1 && num - treeSet.getValueAt(floor) <= valueDiff) {
      return true;
    }

    // Insert the current element into the set
    treeSet.add(num);

    // If our window exceeds the permitted index difference, remove the oldest value
    if (i >= indexDiff) {
      treeSet.remove(nums[i - indexDiff]);
    }
  }

  // If no duplicates are found in the given range, return false
  return false;
}

function containsNearbyAlmostDuplicate2(
  nums: number[],
  indexDiff: number,
  valueDiff: number
): boolean {
  // value to bucket
  let map = new Map();

  for (let i = 0; i < nums.length; i++) {
    let bucket = Math.floor(nums[i] / (valueDiff + 1));
    if (
      map.has(bucket) ||
      (map.has(bucket - 1) &&
        Math.abs(nums[i] - map.get(bucket - 1)) <= valueDiff) ||
      (map.has(bucket + 1) &&
        Math.abs(nums[i] - map.get(bucket + 1)) <= valueDiff)
    ) {
      return true;
    }
    map.set(bucket, nums[i]);
    if (i >= indexDiff) {
      map.delete(Math.floor(nums[i - indexDiff] / (valueDiff + 1)));
    }
  }

  return false;
}
export { containsNearbyAlmostDuplicate, TreeSet };
