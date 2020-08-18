/*
1297. Maximum Number of Occurrences of a Substring

Level: Medium

https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring
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