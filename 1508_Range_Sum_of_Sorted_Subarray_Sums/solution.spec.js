/*
1508. Range Sum of Sorted Subarray Sums

Level: Medium

https://leetcode.com/problems/range-sum-of-sorted-subarray-sums
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