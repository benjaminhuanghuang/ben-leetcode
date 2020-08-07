/*
1418. Display Table of Food Orders in a Restaurant

Level: Medium

https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant
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