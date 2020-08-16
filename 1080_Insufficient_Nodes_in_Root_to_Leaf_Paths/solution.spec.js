/*
1080. Insufficient Nodes in Root to Leaf Paths

Level: Medium

https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths
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