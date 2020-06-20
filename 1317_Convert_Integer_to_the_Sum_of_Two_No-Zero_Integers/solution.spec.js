/*
1317. Convert Integer to the Sum of Two No-Zero Integers

Level: Easy

https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
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