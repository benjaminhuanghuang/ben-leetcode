/*
1588. Sum of All Odd Length Subarrays

Level: Easy

https://leetcode.com/problems/sum-of-all-odd-length-subarrays
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