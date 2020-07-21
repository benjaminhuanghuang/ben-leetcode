/*
1520. Maximum Number of Non-Overlapping Substrings

Level: Medium

https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings
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