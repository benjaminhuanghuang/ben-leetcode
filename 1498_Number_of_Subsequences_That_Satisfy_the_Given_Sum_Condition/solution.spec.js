/*
1498. Number of Subsequences That Satisfy the Given Sum Condition

Level: Medium

https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition
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