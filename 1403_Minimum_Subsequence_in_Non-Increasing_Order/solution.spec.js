/*
1403. Minimum Subsequence in Non-Increasing Order

Level: Easy

https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order
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