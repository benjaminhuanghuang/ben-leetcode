/*
1482. Minimum Number of Days to Make m Bouquets

Level: Medium

https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets
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