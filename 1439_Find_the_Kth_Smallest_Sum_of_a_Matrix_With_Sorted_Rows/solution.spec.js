/*
1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows

Level: Hard

https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows
*/
import { twoSum } from './solution';

describe('Solution 0001 test', () => {;
  beforeEach(() => {
    
  });

  it('test case', () => {
    const input = [2, 7, 11, 15]
    const target = 9;
    expect(twoSum(input, target)).toEqual([1,0]);
  });
});