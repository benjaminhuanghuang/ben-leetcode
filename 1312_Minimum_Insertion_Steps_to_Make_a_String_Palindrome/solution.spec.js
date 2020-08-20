/*
1312. Minimum Insertion Steps to Make a String Palindrome

Level: Hard

https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome
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