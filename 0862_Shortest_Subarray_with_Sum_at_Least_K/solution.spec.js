/*
862. Shortest Subarray with Sum at Least K

Level: Hard

https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k
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