/*
1545. Find Kth Bit in Nth Binary String

Level: Medium

https://leetcode.com/problems/find-kth-bit-in-nth-binary-string
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