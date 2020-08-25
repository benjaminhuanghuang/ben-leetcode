/*
1558. Minimum Numbers of Function Calls to Make Target Array

Level: Medium

https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array
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