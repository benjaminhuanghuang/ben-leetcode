/*
1239. Maximum Length of a Concatenated String with Unique Characters

Level: Medium

https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters
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