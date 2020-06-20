/*
1237. Find Positive Integer Solution for a Given Equation

Level: Easy

https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation
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