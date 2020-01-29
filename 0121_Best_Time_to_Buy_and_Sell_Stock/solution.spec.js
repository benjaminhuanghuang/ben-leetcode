/*
121. Best Time to Buy and Sell Stock

Level: Easy

https://leetcode.com/problems/best-time-to-buy-and-sell-stock
*/
import { maxProfit } from './solution';

describe('Solution 121 test', () => {;
  beforeEach(() => {
    
  });

  it('test case', () => {
    const input = [7,1,5,3,6,4]
    const ans = 5;
    expect(maxProfit(input)).toEqual(ans);
  });
  it('test case 2', () => {
    const input = [7,6,4,3,1]
    const ans = 0;
    expect(maxProfit(input)).toEqual(ans);
  });
});