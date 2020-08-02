/*
558. Logical OR of Two Binary Grids Represented as Quad-Trees

Level: Medium

https://leetcode.com/problems/logical-or-of-two-binary-grids-represented-as-quad-trees
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