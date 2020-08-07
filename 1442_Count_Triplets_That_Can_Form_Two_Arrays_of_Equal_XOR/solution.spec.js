/*
1442. Count Triplets That Can Form Two Arrays of Equal XOR

Level: Medium

https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor
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