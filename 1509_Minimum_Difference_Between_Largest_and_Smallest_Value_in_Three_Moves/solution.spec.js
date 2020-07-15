/*
1509. Minimum Difference Between Largest and Smallest Value in Three Moves

Level: Medium

https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves
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