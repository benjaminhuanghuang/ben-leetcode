/*
1448. Count Good Nodes in Binary Tree

Level: Medium

https://leetcode.com/problems/count-good-nodes-in-binary-tree
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