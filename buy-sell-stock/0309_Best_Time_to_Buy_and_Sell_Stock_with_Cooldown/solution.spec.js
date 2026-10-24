/*
309. Best Time to Buy and Sell Stock with Cooldown

Level: Medium

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
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