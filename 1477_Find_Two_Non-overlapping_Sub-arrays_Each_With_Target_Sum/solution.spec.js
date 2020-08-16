/*
1477. Find Two Non-overlapping Sub-arrays Each With Target Sum

Level: Medium

https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum
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