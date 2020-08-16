/*
1404. Number of Steps to Reduce a Number in Binary Representation to One

Level: Medium

https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one
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