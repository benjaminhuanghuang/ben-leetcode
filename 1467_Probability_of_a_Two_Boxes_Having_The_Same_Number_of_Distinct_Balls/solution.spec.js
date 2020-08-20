/*
1467. Probability of a Two Boxes Having The Same Number of Distinct Balls

Level: Hard

https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls
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