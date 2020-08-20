/*
1526. Minimum Number of Increments on Subarrays to Form a Target Array

Level: Hard

https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array
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