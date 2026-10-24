/*
378. Kth Smallest Element in a Sorted Matrix

Level: Medium

https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix
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