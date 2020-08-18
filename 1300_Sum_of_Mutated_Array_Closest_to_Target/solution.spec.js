/*
1300. Sum of Mutated Array Closest to Target

Level: Medium

https://leetcode.com/problems/sum-of-mutated-array-closest-to-target
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