/*
1481. Least Number of Unique Integers after K Removals

Level: Medium

https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals
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