/*
995. Minimum Number of K Consecutive Bit Flips

Level: Hard

https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips
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