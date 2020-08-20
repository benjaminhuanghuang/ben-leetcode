/*
1074. Number of Submatrices That Sum to Target

Level: Hard

https://leetcode.com/problems/number-of-submatrices-that-sum-to-target
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