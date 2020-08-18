/*
1028. Recover a Tree From Preorder Traversal

Level: Hard

https://leetcode.com/problems/recover-a-tree-from-preorder-traversal
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