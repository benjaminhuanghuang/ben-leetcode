/*
1541. Minimum Insertions to Balance a Parentheses String

Level: Medium

https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string
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