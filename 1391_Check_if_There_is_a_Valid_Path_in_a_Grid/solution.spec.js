/*
1391. Check if There is a Valid Path in a Grid

Level: Medium

https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid
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