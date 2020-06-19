/*
1356. Sort Integers by The Number of 1 Bits

Level: Easy

https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits
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