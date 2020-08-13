/*
1190. Reverse Substrings Between Each Pair of Parentheses

Level: Medium

https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses
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