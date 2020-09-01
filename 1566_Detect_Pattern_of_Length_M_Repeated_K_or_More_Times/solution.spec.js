/*
1566. Detect Pattern of Length M Repeated K or More Times

Level: Easy

https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times
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