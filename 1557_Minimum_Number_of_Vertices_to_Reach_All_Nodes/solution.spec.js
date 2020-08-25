/*
1557. Minimum Number of Vertices to Reach All Nodes

Level: Medium

https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes
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