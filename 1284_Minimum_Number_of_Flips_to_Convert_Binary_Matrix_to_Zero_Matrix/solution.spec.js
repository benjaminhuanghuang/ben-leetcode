/*
1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix

Level: Hard

https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix
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