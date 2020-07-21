/*
395. Longest Substring with At Least K Repeating Characters

Level: Medium

https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters
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