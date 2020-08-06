/*
1347. Minimum Number of Steps to Make Two Strings Anagram

Level: Medium

https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram
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