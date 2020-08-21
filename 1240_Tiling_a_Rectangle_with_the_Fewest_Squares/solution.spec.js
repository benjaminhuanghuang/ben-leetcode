/*
1240. Tiling a Rectangle with the Fewest Squares

Level: Hard

https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares
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