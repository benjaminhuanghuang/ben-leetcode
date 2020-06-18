/*
1413. Minimum Value to Get Positive Step by Step Sum

Level: Easy

https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum
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