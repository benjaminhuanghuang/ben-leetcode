/*
56. Merge Intervals

Level: Nediun

https://leetcode.com/problems/merge-intervals/
*/
import { twoSum } from './solution';

describe('Solution 0056 test', () => {;
  beforeEach(() => {
    
  });

  it('test case', () => {
    const input = [2, 7, 11, 15]
    const target = 9;
    expect(twoSum(input, target)).toEqual([1,0]);
  });
});