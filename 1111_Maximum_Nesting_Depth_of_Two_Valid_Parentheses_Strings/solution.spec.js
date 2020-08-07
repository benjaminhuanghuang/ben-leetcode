/*
1111. Maximum Nesting Depth of Two Valid Parentheses Strings

Level: Medium

https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings
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