/*
1283. Find the Smallest Divisor Given a Threshold

Level: Medium

https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold
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