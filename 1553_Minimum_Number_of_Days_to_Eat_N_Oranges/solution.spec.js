/*
1553. Minimum Number of Days to Eat N Oranges

Level: Hard

https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges
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