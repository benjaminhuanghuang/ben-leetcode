/*
1281. Subtract the Product and Sum of Digits of an Integer

Level: Easy

https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer
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