/*
1005. Maximize Sum Of Array After K Negations

Level: Easy

https://leetcode.com/problems/maximize-sum-of-array-after-k-negations
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