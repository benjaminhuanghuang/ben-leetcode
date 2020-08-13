/*
1358. Number of Substrings Containing All Three Characters

Level: Medium

https://leetcode.com/problems/number-of-substrings-containing-all-three-characters
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