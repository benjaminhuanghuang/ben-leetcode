/*
1318. Minimum Flips to Make a OR b Equal to c

Level: Medium

https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c
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