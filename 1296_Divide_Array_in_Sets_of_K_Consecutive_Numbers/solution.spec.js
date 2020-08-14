/*
1296. Divide Array in Sets of K Consecutive Numbers

Level: Medium

https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers
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