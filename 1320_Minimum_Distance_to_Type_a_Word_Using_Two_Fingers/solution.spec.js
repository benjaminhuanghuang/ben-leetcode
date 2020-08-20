/*
1320. Minimum Distance to Type a Word Using Two Fingers

Level: Hard

https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers
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