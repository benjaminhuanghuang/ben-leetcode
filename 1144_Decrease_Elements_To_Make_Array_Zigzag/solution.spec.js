/*
1144. Decrease Elements To Make Array Zigzag

Level: Medium

https://leetcode.com/problems/decrease-elements-to-make-array-zigzag
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