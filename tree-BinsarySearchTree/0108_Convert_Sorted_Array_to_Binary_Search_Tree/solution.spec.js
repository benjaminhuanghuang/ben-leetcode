/*
108. Convert Sorted Array to Binary Search Tree

Level: Easy

https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
*/
import { sortedArrayToBST } from './solution';

describe('Solution 108 test', () => {;
  beforeEach(() => {
    
  });

  it('test case', () => {
    const input = [-10,-3,0,5,9]
    const ans = 0;
    expect(sortedArrayToBST(input).val).toEqual(ans);
    expect(sortedArrayToBST(input).left.val).toEqual(-10);
    expect(sortedArrayToBST(input).right.val).toEqual(5);

  });
});