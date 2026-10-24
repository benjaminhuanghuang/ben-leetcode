/*
384. Shuffle an Array

https://leetcode.com/problems/shuffle-an-array/
*/

class Solution {
  backup: number[];
  constructor(nums: number[]) {
    this.backup = [...nums];
  }

  reset(): number[] {
    return [...this.backup];
  }

  shuffle(): number[] {
    const n = this.backup.length;
    // Creating a copy of the original array to shuffle.
    let shuffledNums = [...this.backup];
    // Implementing Fisher-Yates shuffle algorithm
    for (let i = 0; i < n; i++) {
      // get a random index j from [0..i]
      const j = Math.floor(Math.random() * (i + 1));
      // Swapping elements at indices i and j.
      [shuffledNums[i], shuffledNums[j]] = [shuffledNums[j], shuffledNums[i]];
    }
    return shuffledNums;
  }
}

export {};
