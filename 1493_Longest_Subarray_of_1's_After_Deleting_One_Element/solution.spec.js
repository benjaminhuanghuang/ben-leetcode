/*
1493. Longest Subarray of 1's After Deleting One Element

Level: Medium

https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element
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