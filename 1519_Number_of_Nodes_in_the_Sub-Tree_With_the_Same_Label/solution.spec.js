/*
1519. Number of Nodes in the Sub-Tree With the Same Label

Level: Medium

https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label
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