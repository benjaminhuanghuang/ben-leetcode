/*
1315. Sum of Nodes with Even-Valued Grandparent

Level: Medium

https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent
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