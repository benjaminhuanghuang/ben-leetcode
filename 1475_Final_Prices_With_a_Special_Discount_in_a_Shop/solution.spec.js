/*
1475. Final Prices With a Special Discount in a Shop

Level: Easy

https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop
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