/*
117. Populating Next Right Pointers in Each Node II

Level: Medium

https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii
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