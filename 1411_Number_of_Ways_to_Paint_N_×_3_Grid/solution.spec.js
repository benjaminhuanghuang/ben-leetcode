/*
1411. Number of Ways to Paint N × 3 Grid

Level: Hard

https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid
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