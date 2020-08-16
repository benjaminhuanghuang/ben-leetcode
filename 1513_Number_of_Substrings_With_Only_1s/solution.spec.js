/*
1513. Number of Substrings With Only 1s

Level: Medium

https://leetcode.com/problems/number-of-substrings-with-only-1s
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