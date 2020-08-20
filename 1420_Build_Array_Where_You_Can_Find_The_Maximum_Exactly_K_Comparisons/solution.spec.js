/*
1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

Level: Hard

https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons
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