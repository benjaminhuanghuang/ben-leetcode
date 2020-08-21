/*
1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree

Level: Hard

https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree
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