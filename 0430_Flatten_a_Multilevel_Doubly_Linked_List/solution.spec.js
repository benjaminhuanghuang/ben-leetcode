/*
430. Flatten a Multilevel Doubly Linked List

Level: Medium

https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list
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