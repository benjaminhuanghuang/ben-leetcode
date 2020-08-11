/*
1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K

Level: Medium

https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k
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