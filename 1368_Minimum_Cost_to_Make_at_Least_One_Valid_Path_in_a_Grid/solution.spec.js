/*
1368. Minimum Cost to Make at Least One Valid Path in a Grid

Level: Hard

https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid
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