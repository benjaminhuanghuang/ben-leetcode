/*
1170. Compare Strings by Frequency of the Smallest Character

Level: Easy

https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character
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